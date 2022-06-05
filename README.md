# Blinky template

A bare-bones Makefile-based template for ESP32 projects.

I like to understand the build systems of my projects.  Here, I'm
looking to understand how a C++ program becomes a binary file
that's uploaded to the flash chip.

The build systems for the [Arduino][1] and [ESP-IDF]() are very
generic and powerful, but also very opaque.

## How to run.

NOTE: For the moment, this still needs you to have previously
installed the Arduino IDE.  I will try to remove this limitation soon.

But you don't need to run it.  Just ensure that
`~/.arduino15/packages/esp32/` exists after having followed a tutorial
like [this one][1].

Then simply type `make flash-blinky`.

[1]: https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/
[2]: https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html
