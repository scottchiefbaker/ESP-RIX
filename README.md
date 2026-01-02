# 🔭 Remote Information eXchange

<!--
Icons from: https://shields.io/

https://img.shields.io/badge/ESP-32-success
https://img.shields.io/badge/ESP-8266-success
https://img.shields.io/badge/Arduino-AVR-success?logo=arduino&logoWidth=18
-->
![ARDUINO-AVR](https://user-images.githubusercontent.com/3429760/220426704-0a102a4f-f661-4fa8-a3cc-b37af02a35d4.svg)
![ESP8266](https://user-images.githubusercontent.com/3429760/220426614-77c8aa30-325e-4e14-8bb9-94daf03f68fc.svg)
![ESP 32](https://user-images.githubusercontent.com/3429760/220428060-b08bb5ee-3a5c-4061-97ab-2c8977045aa2.svg)

**R**emote **I**nformation e**X**change adds remote logging and debugging
capabilities to your ESP based Arduino projects. This can be useful if
your project is in an inaccessible location, and serial isn't available.

# 📦 Installation

Clone this repo to your Arduino libraries directory. On Linux this is
`~/Arduino/libraries/`

# ✨ Usage

Include the RIX library

```C
#include <esp-rix.h>
```

Listen for RIX calls at the end of your `loop()` function

```C
void loop() {
	// Other loop code here

	// Rix supports 7 levels of debug messages
	rix_1("This is a LEVEL 1 message");
	rix_7("This is a LEVEL 7 message");

	// Rix also supports printf style messages
	rix_5("MCU Uptime: %d minutes", millis() / 1000 / 60);

	handle_rix();
}
```

On a machine that shares the same WiFi as your ESP you can `telnet` to your
ESP's IP address to view the messages.

# ⚙️ Library options

Enable/disable color in output

```C
rix_color(0); // Disable color
```

Set the initial output logging level

```C
rix_log_level(4); // Default: 7
```

Change the TCP port that RIX listens on

```C
rix_tcp_port(2300); // Default: 23
```

Using `delay()` in your scripts may cause RIX to be less responsive. A
`rix_delay()` method has been added as a drop-in replacement to keep your
project responsive.

```C
rix_delay(500); // Wait 500 ms
```

RIX has a function to make connecting to your WiFi simple:

```C
int ok = rix_init_wifi("MySSID", "SekritPassword");
```

# 🚫 Disabling RIX

When you're done debugging you can disable RIX entirely by adding:

```C
# define RIX_DISABLE
```

before the include line. This will make all the `rix_*` calls no-ops, and
disable logging. This means you can leave all your setup and logging calls in
your code and simply disable the library at compile time.

# ◀️ Backwards compatibility

On non-ESP boards RIX is **automatically** disabled. This allows you to test
and debug on an ESP board, and then compile on an Arduino Nano with no changes
to your code.

# 🤹 Inspired by

RIX was inspired by Joao Lopes' [RemoteDebug](https://github.com/JoaoLopesF/RemoteDebug)
which appears to be abandonned.
