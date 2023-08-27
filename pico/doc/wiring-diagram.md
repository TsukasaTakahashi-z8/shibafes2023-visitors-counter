# Raspberry Pi Pico周りの配線

## 7セグ

## Pin割当

![Raspberry Pi 公式より](https://www.raspberrypi.com/documentation/microcontrollers/images/pico-pinout.svg)

| Pin |          | 接続先                    |
| --- | ---      | ---                       |
|  1  | GP0      | Access LED                |
|  2  | UART0 RX | Raspberry Pi 3A+ UART0 TX |
|  3  | GND      | GND                       |
|  4  | GP2      | Aのアノード               |
|  5  | GP3      | Bのアノード               |
|  6  | GP4      | Cのアノード               |
|  7  | GP5      | Dのアノード               |
|  8  | GND      | GND                       |
|  9  | GP6      | Eのアノード               |
| 10  | GP7      | Fのアノード               |
| 11  | GP8      | Gのアノード               |
| 12  | GP9      | optino                    |
| 13  | GND      | GND                       |
| 14  | GP10     | 万の位                    |
| 15  | GP11     | 千の位                    |
| 16  | GP12     | 百の位                    |
| 17  | GP13     | 十の位                    |
| 18  | GND      | GND                       |
| 19  | GP14     | 一の位                    |
| 20  | GP15     | -free-                    |
| --- | ---      | ---                       |
| 21~ | -free-   | -free-                    |
