#include "init.h"

// IMU status variables
unsigned char imu_system_status = 0, imu_self_test_results = 0, imu_system_error = 0;

// IMU calibration status
unsigned char imu_system_calibration_status = 0, imu_gyro_calibration_status = 0, imu_accel_calibration_status = 0, imu_mag_calibration_status = 0;

unsigned long imu_calibration_timeout_start_time = 0;

// Check sensor calibration
void v_state_init()
{
    // Check sensors and calibrate the BNO055
    sensor_imu.getSystemStatus(&imu_system_status, &imu_self_test_results, &imu_system_error);
    sensor_imu.getCalibration(&imu_system_calibration_status, &imu_gyro_calibration_status, &imu_accel_calibration_status, &imu_mag_calibration_status);

    // Check if the IMU is calibrated
    bool system_calibrated  = imu_system_calibration_status != 0;
    bool sensors_calibrated = imu_gyro_calibration_status >= MIN_IMU_GYRO_CALIBRATION && imu_accel_calibration_status >= MIN_IMU_ACCEL_CALIBRATION && imu_mag_calibration_status >= MIN_IMU_MAG_CALIBRATION;
    
    if (system_calibrated && sensors_calibrated) // If calibrated
    {
        v_state_change(&v_state, V_STATE::IDLE);
    }

    log_event("IMU !calibrated");

    if (imu_calibration_timeout_start_time == 0) // Start the timeout
    {
        imu_calibration_timeout_start_time = GET_TIME();
    }
    else
    {
        if (GET_TIME() - imu_calibration_timeout_start_time > IMU_CALIBRATION_TIMEOUT) // If timeout exceeded
        {
            log_event("IMU calibration timeout");
            state_core0.p_state = P_STATE::INIT_ERROR;
            return;
        }
    }

    delay(IMU_CALIBRATION_STATUS_DELAY);
}