#include <esp-rix.h>

void setup() {
	Serial.begin(115200);

	int ok = rix_init_wifi("YourSSID", "SekritPass");
}

void loop() {
	handle_rix();

	rix_1("ALERT message");
	rix_2("CRITICAL message");
	rix_3("ERROR message");
	rix_4("WARNING message");
	rix_5("NOTICE message");
	rix_6("INFORMATION message");
	rix_7("DEBUG message");

	Serial.println("Loooping");

	rix_delay(2000);
}
