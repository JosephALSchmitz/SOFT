#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include "wiringPi.h"
#include "mcp3004.h"
#include "SOFT.h"

int main() {
  wiringPiSetup();
  mcp3004Setup(BASE, SPI_CHAN);

  int i;
  AMP RES = {.status.ready.pin = 17,
	      .status.clip.pin = 18,
	      .status.otw1.pin = 16,
	      .status.otw2.pin = 15,
	      .status.sd.pin = 19,
	      .control.reset.pin = 14};
  AMP EXT = {.status.ready.pin = 3,
	      .status.clip.pin = 5,
	      .status.otw1.pin = 2,
	      .status.otw2.pin = 4,
	      .status.sd.pin = 1,
	      .control.reset.pin = 0};
  FIREBOX FB = {.status.temp = 0,
		.status.lit = 0,
		.control.solen.pin = 27,
		.control.ignite.pin = 26,
		.control.audSel.pin = 28};

  init_gpio(&RES, &EXT, &FB);

  while (true) {
    update(&RES,&EXT,&FB);
    delay(100);
  }

  for( i=0 ;i<10; i++ ) {
    digitalWrite(RES.control.reset.pin,HIGH); delay(1000);
    printf("Set Logic High on pin: %i \n", RES.control.reset.pin);
    digitalWrite(RES.control.reset.pin,LOW); delay(500);
    printf("Set Logic Low on pin: %i \n", RES.control.reset.pin);
  }

  return 0;
}
