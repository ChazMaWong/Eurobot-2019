
/* configuration.h (internal)
 *
 * This file contains code related to runtime configuration of the robot
 * - functions used by `robot.*`
 * 
 * See `docs/Configuration.md`
 */

#pragma once

#include <Arduino.h>
#include "debug.h"

namespace robot {
	namespace configuration {

		extern int16_t wheel_radius // distance from wheel centre to circumference
		             , robot_radius // distance from robot centre to wheel centre
		             , peak_speed   // maximum speed of the robot, speeds are otherwise scaled
		             , acceleration // acceleration of the robot/MD25
		             ;

		extern int16_t config_key;

		// sets the key to be written to
		void set_config_key(int16_t key);

		// sets the configuration value for the currently selected key
		void set_config_value(int16_t value);

	}
}
