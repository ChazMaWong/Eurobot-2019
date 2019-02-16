
#include "include/robot/primary.h"

MD25 md25;

auto ledOn = LOW;

ACTIVITY(toggleLED, cooldown=500000, timeout=5000000) {
	digitalWrite(LED_BUILTIN, ledOn);
	ledOn ^= HIGH;
}

PREDICATE(toggleLED) {
	return false;
}

uint16_t readComponentValue(uint16_t component_ID) {
	return 0u;
}

struct Activity* lookupActivity(uint16_t activity_ID) {
	return ACTIVITY(toggleLED);
}

DistanceSensor *sensors;

void setup() {
	Serial.begin(9600);

	pinMode(LED_BUILTIN, OUTPUT);

	md25.setup();

	sensors = malloc(1);

	robot::set_component_value_reader(&readComponentValue);
	robot::set_activity_lookup(&lookupActivity);
	robot::set_distance_sensors(0, sensors);
	robot::configuration::set_radii(50u, 150u);
	robot::drive::set_md25(&md25);

	robot::setup();
}

void loop() {
	robot::loop();
}