# Embedded Systems project

👨‍👩‍👧‍👦 WiFi person count estimator \
💡 Based on [Makerfabs/Project_WiFi-Statistics] and [ESP-EOS/ESP32-WiFi-Sniffer]

<div align="center">

[![](https://img.youtube.com/vi/R-2aqAtgXY8/0.jpg)](https://www.youtube.com/watch?v=R-2aqAtgXY8)

</div>

📡 Counts unique MAC addresses \
📚 Great for tracking busyness over time \
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
3. An LCD screen. This will be used to display the count of how many people are
   estimated to be in the area (by MAC addresses). This project's code expects a
   16x2 display, but you can probably fiddle with the code to get it to work
   with other sizes. You can find [16x2 LCD screens on Amazon].

In my own experimentation and development, I used the [DOIT ESP32 DEVKIT V1].

To configure the hardware, you should match this circuit:

<div align="center">

![](https://www.circuitschools.com/wp-content/uploads/2020/09/Interfacing-16X2-LCD-module-with-ESP-32-without-using-I2C-adapter.webp)

</div>

You'll also need to install the "FreeRTOS" library from the Arduino Library
Manager. We need this library to use the `vTaskDelay()` function.

## Usage

Once you've downloaded the application code to your ESP32, you just need to
deploy it someplace! The easiest spot is, of course, right where you're sitting.
Plug in the ESP32 to the power brick, make sure you've got the OLED output
screen hooked up, and see how many WiFi MAC addresses are in your area!

## Development

![C++](https://img.shields.io/static/v1?style=for-the-badge&message=C%2B%2B&color=00599C&logo=C%2B%2B&logoColor=FFFFFF&label=)
![Arduino IDE](https://img.shields.io/static/v1?style=for-the-badge&message=Arduino+IDE&color=00979D&logo=Arduino&logoColor=FFFFFF&label=)
![ESP32](https://img.shields.io/static/v1?style=for-the-badge&message=ESP32&color=E7352C&logo=Espressif&logoColor=FFFFFF&label=)

This project was developed using the Arduino IDE and an ESP32. You can get the
project running locally using `git clone` and then opening the main
`compsci-412-project.ino` in the Arduino IDE. You'll need an actual ESP32 to run
the code!

<!-- prettier-ignore-start -->
[adafruit huzzah32]: https://www.adafruit.com/product/3405
[esp32 boards on amazon]: https://www.amazon.com/s?k=esp32+board
[cheap $4/pc chargers on amazon]: https://www.amazon.com/s?k=usb+charger
[16x2 LCD screens on Amazon]: https://www.amazon.com/s?k=arduino+16x2+lcd
[Makerfabs/Project_WiFi-Statistics]: https://github.com/Makerfabs/Project_WiFi-Statistics#readme
[ESP-EOS/ESP32-WiFi-Sniffer]: https://github.com/ESP-EOS/ESP32-WiFi-Sniffer#readme
<!-- prettier-ignore-end -->
