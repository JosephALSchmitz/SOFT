#include "wiringPi.h"
#include "SOFT.h"

void init_gpio(AMP *RES, AMP *EXT, FIREBOX *FB) {
  pinMode(RES->status.ready.pin, INPUT);
  pinMode(RES->status.clip.pin, INPUT);
  pinMode(RES->status.otw1.pin, INPUT);
  pinMode(RES->status.otw2.pin, INPUT);
  pinMode(RES->status.sd.pin, INPUT);

  pinMode(RES->control.reset.pin, OUTPUT);

  pinMode(EXT->status.ready.pin, INPUT);
  pinMode(EXT->status.clip.pin, INPUT);
  pinMode(EXT->status.otw1.pin, INPUT);
  pinMode(EXT->status.otw2.pin, INPUT);
  pinMode(EXT->status.sd.pin, INPUT);

  pinMode(EXT->control.reset.pin, OUTPUT);
}
