
#include "include/robot/primary.h"

MD25 md25;

auto ledOn = LOW;

ACTIVITY(toggleLED, cooldown=500000, timeout=5000000) {
	digitalWrite(LED_BUILTIN, ledOn);
	ledOn ^= HIGH;
}

int16_t readComponentValue(int16_t component_ID) {
	return 0u;
}

struct Activity* lookupActivity(uint16_t activity_ID) {
	return ACTIVITY(toggleLED);
}

SharpIR *sensors;

void setup() {
	pinMode(LED_BUILTIN, OUTPUT);
	Serial.begin(9600);

	robot::wait_for_connection();

	rlog("Connection established");

	md25.setup();

	rlog("MD25 set-up");

	sensors = (SharpIR*) malloc(1);

	robot::set_component_value_reader(&readComponentValue);
	robot::set_activity_lookup(&lookupActivity);
	robot::set_distance_sensors(0, sensors);
	robot::drive::set_md25(&md25);

	rlog("Initialisation complete");

	robot::setup();
}

void loop() {
	robot::loop();
}
