#include <esp-rix.h>

void setup() {
	Serial.begin(115200);

	int ok = rix_init_wifi("YourSSID", "SekritPass");
}

void loop() {
	handle_rix();

	rix_1("This is an ALERT");
	rix_2("This is CRITICAL %0.1f", 8.1);
	rix_3("This is an error %d", 37);
	rix_4("This is a warning %s", "BUB!");
	rix_5("This is a %s", "NOTICE");
	rix_6("INFORMATION: Uptime: %d", millis());
	rix_7("This is just debug %s", "Scott");

	test_func();

	rix_5("");

	Serial.println("Loooping");

	rix_delay(2000);
}

void test_func () {
	rix_7("Testing functions %s", __func__);
}
