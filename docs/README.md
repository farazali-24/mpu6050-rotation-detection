
# MPU6050 Rotation Detection — Documentation

This folder contains the circuit diagrams, photographs, flowchart and editable Fritzing design for the MPU6050 rotation detection project using an ESP32.

## Files

| File | Description |
|---|---|
| `fritzingmpu6050breadboard.png` | Fritzing breadboard layout showing the ESP32, MPU6050, LED and resistor. |
| `fritzingmpu6050schematic.png` | Circuit schematic showing the electrical connections between components. |
| `photo.png` | Photograph of the original MPU6050 breadboard implementation. |
| `flowchart.png` | Flowchart explaining the rotation detection algorithm and LED response. |
| `wiring.fzz` | Editable Fritzing project containing the circuit design. |

## Circuit Overview

The MPU6050 communicates with the ESP32 using the I2C protocol.

### Pin Connections

| Component | ESP32 |
|---|---|
| MPU6050 VCC | 3.3V |
| MPU6050 GND | GND |
| MPU6050 SDA | GPIO19 |
| MPU6050 SCL | GPIO18 |
| LED anode (through 220Ω resistor) | GPIO26 |
| LED cathode | GND |

## Additional Information

For the Arduino code, project operation, results and limitations, see the [main README](../README.md).
