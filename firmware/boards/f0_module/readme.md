Firmware for reference https://github.com/mck1117/wideband/tree/master/board_module F0 hardware.

Also the firmware for https://github.com/andreika-git/hellen-one/tree/master/modules/wbo.

## Hearth / 24 V DIN (`marpi82/custom`)

- Connector **pin 7 `VBatt_Sense`**: on-module divider 100k/10k → **PB0 / ADC_IN8**.
- Firmware reads local Ubat (`BOARD_HAS_VOLTAGE_SENSE`); heater duty uses
  `duty = (V_eff / V_batt)^2` with `V_eff ≤ 12 V` (≈25 % PWM at 24 V).
- Absurd-supply abort raised to 32 V (stock automotive cut-off was 23 V).
- Carrier power/CAN may live on the host board (Hearth Core); feed raw protected
  `+24V` into pin 7 (already divided on the module).