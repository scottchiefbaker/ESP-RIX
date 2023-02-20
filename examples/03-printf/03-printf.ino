#include <esp-rix.h>

void setup() {
	Serial.begin(115200);

	int ok = rix_init_wifi("YourSSID", "SekritPass");\
}

void loop() {
	handle_rix();

	float pi = 3.14159265;

	// RIX supports printf() style formats
	rix_1("Uptime: %d ms", millis());
	rix_4("Hello %s", "world");
	rix_7("Pi is: %1.5f", pi);

	Serial.println("Loooping");

	rix_delay(2000);
}
