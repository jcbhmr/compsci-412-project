# Embedded Systems project

👨‍👩‍👧‍👦 WiFi & BLE person count estimator
💡 Based on [Makerfabs/Project_WiFi-Statistics] and [ESP-EOS/ESP32-WiFi-Sniffer]

<div align="center">

![]()

<!-- prettier-ignore -->
[Tutorial]()
| [Demo video]()
| [How it works]()

</div>

🔢 Count the approximate number of people in an area \
📚 Great for tracking busyness over time \
📡 Counts unique MAC addresses \
📈 Usually overestimates \
✨ Complete project, not a library

## Installation

![ESP32](https://img.shields.io/static/v1?style=for-the-badge&message=ESP32&color=E7352C&logo=Espressif&logoColor=FFFFFF&label=)
![Arduino IDE](https://img.shields.io/static/v1?style=for-the-badge&message=Arduino+IDE&color=00979D&logo=Arduino&logoColor=FFFFFF&label=)

This is a physical project, as well as a software project! You'll need...

1. An ESP32 chip. Preferrably a development board. If you want something that
   you can reuse for other projects, the [Adafruit HUZZAH32] is a good choice.
   If you just want a cheap $10 board for this project only, you can snag one of
   the many [ESP32 boards on Amazon].
2. A way to power your ESP32. This is most likely a USB charging brick. If you
   are truly dedicated to wireless deployment, you can use your own battery
   solution. But for the intended deployment case of an indoor stationary spot,
   a wired-to-wall solution is probably the most sensible. Your charging brick
   doesn't need to be fancy. As long as it can supply ~500mA of current, that's
   sufficient. You can find [cheap $4/pc chargers on Amazon].
3. An OLED screen. This will be used to display the count of how many people are
   estimated to be in the area. This project's code expects an 0.96 in display,
   but you can probably fiddle with the code to get it to work with other sizes.
   You can find [0.96 in OLED screens on Amazon].

In my own experimentation and development, I used {TODO: Add board name}.

To configure the hardware, you should match this circuit:

Specifically, the OLED screen is connected to power (of course) with its {TODO:
Explain pin connections in English}.

To install this project onto an ESP32 board, you'll need to download the latest
released `compsci-412-project.zip` folder from the GitHub Releases page. Inside
this folder is a `compsci-412-project/` folder which has a
`compsci412-project/compsci-412-project.ino` file which is the main file of this
project.

You'll also need the following Arduino IDE libraries! You can install these
using the builtin Library manager tool.

- Library #1
- Library #2

## Usage

Once you've downloaded the application code to your ESP32, you just need to
deploy it someplace! The easiest spot is, of course, right where you're sitting.
Plug in the ESP32 to the power brick, make sure you've got the OLED output
screen hooked up, and see how many WiFi signals are in your area!

## Development

![C++](https://img.shields.io/static/v1?style=for-the-badge&message=C%2B%2B&color=00599C&logo=C%2B%2B&logoColor=FFFFFF&label=)
![Arduino IDE](https://img.shields.io/static/v1?style=for-the-badge&message=Arduino+IDE&color=00979D&logo=Arduino&logoColor=FFFFFF&label=)
![ESP32](https://img.shields.io/static/v1?style=for-the-badge&message=ESP32&color=E7352C&logo=Espressif&logoColor=FFFFFF&label=)

TODO: Add development description

<!-- prettier-ignore-start -->
[adafruit huzzah32]: https://www.adafruit.com/product/3405
[esp32 boards on amazon]: https://www.amazon.com/s?k=esp32+board
[cheap $4/pc chargers on amazon]: https://www.amazon.com/s?k=usb+charger
[0.96 in oled screens on amazon]: https://www.amazon.com/s?k=arduino+oled
[Makerfabs/Project_WiFi-Statistics]: https://github.comMakerfabs/Project_WiFi-Statistics#readme
[ESP-EOS/ESP32-WiFi-Sniffer]: https://github.com/ESP-EOS/ESP32-WiFi-Sniffer#readme
<!-- prettier-ignore-end -->
