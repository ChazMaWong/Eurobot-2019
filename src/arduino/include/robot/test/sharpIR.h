
/* MD25 ticks test
 *     requires connection for meaningful output
 * 
 * Should log "Sensor connected to A0" when connected
 * Should repeatedly log "<reading>" where <reading> is
 *   (the sensor connected to A0)'s reading
 */

#pragma once

#include "../../component/SharpIR.h"
#include "../../debug.h"
#include "../../messages.h"
