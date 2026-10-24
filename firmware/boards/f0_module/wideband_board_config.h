#pragma once

// Fundamental board constants
#define VCC_VOLTS (3.3f)
#define HALF_VCC (VCC_VOLTS / 2)
#define ADC_MAX_COUNT (4095)
#define ADC_OVERSAMPLE 24

// *******************************
//    Nernst voltage & ESR sense
// *******************************
#define NERNST_INPUT_GAIN (2.7f)

#define AFR_CHANNELS 1

// *******************************
//    Nernst voltage & ESR sense
// *******************************
#define VM_RESISTOR_VALUE (10)

// *******************************
//    Battery / heater supply sense (connector pin 7 VBatt_Sense)
// *******************************
// On-module divider: R20=100k (sense→PB0), R21=10k (PB0→GND).
// At 24 V → ~2.18 V on ADC; 3.3 V full-scale only above ~36 V.
#define BOARD_HAS_VOLTAGE_SENSE
#define BATTERY_INPUT_DIVIDER (10.0f / (10.0f + 100.0f))

// Stock heater_control aborts at >=23 V (12 V automotive). Hearth DIN is 24 V;
// keep V_eff≤12 via duty=(V_eff/V_batt)^2 and only abort on absurd overvoltage.
#define HEATER_SUPPLY_ABSURD_VOLTAGE 32.0f
