#include "wiringPi.h"
#include "mcp3004.h"
#include "SOFT.h"

void update(AMP *RES, AMP *EXT, FIREBOX *FB) {
  FB->status.temp = analogRead(BASE);
  
}
