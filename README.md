<!-- ![🗝️ Archived! 👴](https://i.imgur.com/9vmkYS4.png) -->

# Person counter

👨‍👩‍👧‍👦 WiFi person count estimator \
💡 Based on [Makerfabs/Project_WiFi-Statistics] and [ESP-EOS/ESP32-WiFi-Sniffer]

<div align="center">

[![](https://i.imgur.com/7kVg93O.png)](https://www.youtube.com/watch?v=R-2aqAtgXY8)

[Demo video](https://www.youtube.com/watch?v=R-2aqAtgXY8)

</div>

📡 Counts unique MAC addresses \
📚 Great for tracking busyness over time \
✨ Complete project, not a library \
👨‍💻 Make as a class project for _Embedded Systems_ at UW-Whitewater

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

📚 Getting started: [Installing ESP32 in Arduino IDE (Windows, Mac OS X, Linux)
| Random Nerd Tutorials]

## Usage

Once you've downloaded the application code to your ESP32, you just need to
deploy it someplace! The easiest spot is, of course, right where you're sitting.
Plug in the ESP32 to the power brick, make sure you've got the OLED output
screen hooked up, and see how many WiFi MAC addresses are in your area!

### Legal

I am not qualified to remark on whether or not this MAC address sniffing is
legal or not in your area. [This is not legal advice]. With that said, here are
some discussions and other resources about the legal side of tracking people
with WiFi signals:

- [What is legality of monitoring traffic for mac addresses · Issue #4 · schollz/howmanypeoplearearound](https://github.com/schollz/howmanypeoplearearound/issues/4)
- [Wi-Fi location analytics | ICO](https://ico.org.uk/media/for-organisations/documents/1560691/wi-fi-location-analytics-guidance.pdf)
- [18 U.S. Code § 2511 - Interception and disclosure of wire, oral, or electronic communications prohibited | U.S. Code | US Law | LII / Legal Information Institute](https://www.law.cornell.edu/uscode/text/18/2511)

## Related

There's some other interesting projects dealing with WiFi person detection that
are pretty cool! 😲

- [schollz/howmanypeoplearearound: Count the number of people around you by monitoring wifi signals](https://github.com/schollz/howmanypeoplearearound#readme)
- [cyberman54/ESP32-Paxcounter: Wifi & BLE driven passenger flow metering with cheap ESP32 boards](https://github.com/cyberman54/ESP32-Paxcounter#readme)
- [ESP-EOS/ESP32-WiFi-Sniffer: Simple WiFi sniffer for boards based on the Espressif Systems ESP32 module](https://github.com/ESP-EOS/ESP32-WiFi-Sniffer#readme)
- [Makerfabs/Project_WiFi-Statistics](https://github.com/Makerfabs/Project_WiFi-Statistics#readme)

## Development

![C++](https://img.shields.io/static/v1?style=for-the-badge&message=C%2B%2B&color=00599C&logo=C%2B%2B&logoColor=FFFFFF&label=)
![Arduino IDE](https://img.shields.io/static/v1?style=for-the-badge&message=Arduino+IDE&color=00979D&logo=Arduino&logoColor=FFFFFF&label=)
![ESP32](https://img.shields.io/static/v1?style=for-the-badge&message=ESP32&color=E7352C&logo=Espressif&logoColor=FFFFFF&label=)

This project was developed using the Arduino IDE and an ESP32. You can get the
project running locally using `git clone` and then opening the main
`person-counter.ino` in the Arduino IDE. You'll need an actual ESP32 to run the
code!

<!-- prettier-ignore-start -->
[adafruit huzzah32]: https://www.adafruit.com/product/3405
[esp32 boards on amazon]: https://www.amazon.com/s?k=esp32+board
[cheap $4/pc chargers on amazon]: https://www.amazon.com/s?k=usb+charger
[16x2 LCD screens on Amazon]: https://www.amazon.com/s?k=arduino+16x2+lcd
[Makerfabs/Project_WiFi-Statistics]: https://github.com/Makerfabs/Project_WiFi-Statistics#readme
[ESP-EOS/ESP32-WiFi-Sniffer]: https://github.com/ESP-EOS/ESP32-WiFi-Sniffer#readme
[this is not legal advice]: https://notlegaladvice.law/
[Installing ESP32 in Arduino IDE (Windows, Mac OS X, Linux) | Random Nerd Tutorials]: https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/
[DOIT ESP32 DEVKIT V1]:  https://www.circuitstate.com/wp-content/cache/all/pinouts/doit-esp32-devkit-v1-wifi-development-board-pinout-diagram-and-reference/index.html
<!-- prettier-ignore-end -->
