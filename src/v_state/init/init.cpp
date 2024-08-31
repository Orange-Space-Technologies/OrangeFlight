#include "init.h"

// IMU status variables
unsigned char imu_system_status = 0, imu_self_test_results = 0, imu_system_error = 0;

// IMU calibration status
unsigned char imu_system_calibration_status = 0, imu_gyro_calibration_status = 0, imu_accel_calibration_status = 0, imu_mag_calibration_status = 0;
void v_state_init() {
    // Check sensors and calibrate the BNO055
    sensor_imu.getSystemStatus(&imu_system_status, &imu_self_test_results, &imu_system_error);
    sensor_imu.getCalibration(&imu_system_calibration_status, &imu_gyro_calibration_status, &imu_accel_calibration_status, &imu_mag_calibration_status);

    // Check if the IMU is calibrated
    if (imu_system_calibration_status == 0) {
        return;
    }
}