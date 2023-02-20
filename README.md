# Remote Information eXchange

[![ESP8266](https://img.shields.io/badge/ESP-8266-000000.svg?longCache=true&style=flat&colorA=CC101F)](https://www.espressif.com/en/products/socs/esp8266)
[![ESP32](https://img.shields.io/badge/ESP-32-000000.svg?longCache=true&style=flat&colorA=CC101F)](https://www.espressif.com/en/products/socs/esp32)

**R**emote **I**nformation e**X**change adds remote logging and debugging
capabilities to your ESP based Arduino projects. This can be useful if
your project is in an inaccessible location, and serial isn't available.

# Installation

Clone this repo to your Arduino libraries directory. On Linux this is
`~/Arduino/libraries/`

# Usage

Include the RIX library

    #include <WebOTA.h>

Listen for RIX calls at the end of your `loop()` function

    void loop() {
        // Other loop code here

        // Rix supports 7 levels of debug messages
        rix_1("This is a LEVEL 1 message");
        rix_7("This is a LEVEL 7 message");

        // Rix also supports printf style messages
        rix_5("MCU Uptime: %d minutes", millis() / 1000 / 60);

        handle_rix();
    }

On a machine that shares the same WiFi as your ESP you simply
`telnet` to your ESP's IP address to view the messages.

# Library options

Enable/disable color in output

    rix_color(0); // Disable color

Set the initial output logging level

    rix_log_level(4); // Set the initial log level (default: 7)

Using `delay()` in your scripts may cause RIX to be less responsive. A
`rix_delay()` method has been added as a drop-in replacement to keep your
project responsive.

    rix_delay(500); // Wait 500 ms

A simple function was added to make connecting to your WiFi simple:

    int ok = rix_init_wifi("MySSID", "SekritPassword");

# Backwards compatibility

Care was taken to make sure the library "fails gracefully" when disabled. You
may want to disable debugging entirely when your project is complete. This can
be accomplished by adding:

    # define RIX_DISABLE

before the include line. This will make all the `rix_*` calls no-ops, and
disable logging. This means you can leave all your setup and logging calls in
your code and simply disable the library at compile time.

**Note:** On non-ESP boards RIX is automatically disabled. This allows you to
test and debug on an ESP board, and then compile on an Arduino Nano with no
changes to your code.

# Inspired by

RIX was inspired by Joao Lopes' [RemoteDebug](https://github.com/JoaoLopesF/RemoteDebug)
which appears to be abandonned.
