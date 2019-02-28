
/* MD25 ticks test
 *     doesn't require connection
 * 
 * Should log "MD25 set up" and "Reading left encoder", after MD25 setup, when connected
 * Should repeatedly log left encoder reading
 */

#pragma once

#include "../../component/MD25.h"
#include "../../debug.h"
#include "../../messages.h"
