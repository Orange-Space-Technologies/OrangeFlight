#include "pyro.h"

void firePyro1() {
    digitalWrite(PIN_PYRO_1_FIRE, HIGH);
}

void firePyro2() {
    digitalWrite(PIN_PYRO_2_FIRE, HIGH);
}

bool continuityCheckPyro1() {
    #ifdef PYRO_CONTINUITY
        return digitalRead(PIN_PYRO_1_CONTINUITY) == HIGH;
    #else
        return !PYRO_1_FIRED;
    #endif
}

bool continuityCheckPyro2() {
    #ifdef PYRO_CONTINUITY
        return digitalRead(PIN_PYRO_2_CONTINUITY) == HIGH;
    #else
        return !PYRO_2_FIRED;
    #endif
}