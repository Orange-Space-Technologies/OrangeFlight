#pragma once

#include "globals.h"

bool PYRO_1_FIRED = false;
bool PYRO_2_FIRED = false;

void firePyro1();
void firePyro2();

bool continuityCheckPyro1();
bool continuityCheckPyro2();