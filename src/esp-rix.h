#define RIX_VERSION 0.1

#if defined(ESP8266)
	#include <ESP8266WiFi.h>
#elif defined(ESP32)
	#include <WiFi.h>
#else
	#warning RIX requires an ESP board. Disabling for non-supported board
	#define RIX_DISABLE
#endif

///////////////////////////////////////////////////////////////////////
// The library is disabled so we null out a bunch of functions
///////////////////////////////////////////////////////////////////////
#ifdef RIX_DISABLE

// All the rix_# calls are nulled out
#define rix_1(fmt, ...)
#define rix_2(fmt, ...)
#define rix_3(fmt, ...)
#define rix_4(fmt, ...)
#define rix_5(fmt, ...)
#define rix_6(fmt, ...)
#define rix_7(fmt, ...)

// Nulled out
#define handle_rix()
#define rix_log_level(x)
#define rix_color(x) (0)
#define init_rix()
#define rix_delay(ms) delay(ms)
#define rix_init_wifi(x, y) (0)

///////////////////////////////////////////////////////////////////////
// The library is enabled so business as usual
///////////////////////////////////////////////////////////////////////
#else

#define ALERT       1
#define CRITICAL    2
#define ERROR       3
#define WARNING     4
#define NOTICE      5
#define INFORMATION 6
#define DEBUG       7

// Macros to wrap around debug print so we can capture the calling function name
#define rix_1(fmt, ...) __debug_print(__func__, ALERT      , fmt, ##__VA_ARGS__)
#define rix_2(fmt, ...) __debug_print(__func__, CRITICAL   , fmt, ##__VA_ARGS__)
#define rix_3(fmt, ...) __debug_print(__func__, ERROR      , fmt, ##__VA_ARGS__)
#define rix_4(fmt, ...) __debug_print(__func__, WARNING    , fmt, ##__VA_ARGS__)
#define rix_5(fmt, ...) __debug_print(__func__, NOTICE     , fmt, ##__VA_ARGS__)
#define rix_6(fmt, ...) __debug_print(__func__, INFORMATION, fmt, ##__VA_ARGS__)
#define rix_7(fmt, ...) __debug_print(__func__, DEBUG      , fmt, ##__VA_ARGS__)

void __debug_print(const char* func, int level, const char* format, ...);
void handle_rix();
void init_rix();
void rix_log_level(int level);
void rix_delay(unsigned int ms);
int  rix_color(int num);
int  rix_init_wifi(const char *ssid, const char *password);

#endif

// vim: tabstop=4 shiftwidth=4 noexpandtab autoindent softtabstop=4
