#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BASE 100
#define SPI_CHAN 0

typedef struct GPIO_ELEM {
  int value;
  int pin;
} GPIO_ELEM;

typedef struct AMP {
  struct AMP_STATUS {
    GPIO_ELEM ready;
    GPIO_ELEM clip;
    GPIO_ELEM otw1;
    GPIO_ELEM otw2;
    GPIO_ELEM sd;
  } status;

  struct AMP_CONTROL {
    GPIO_ELEM reset;
  } control;
} AMP;

typedef struct FIREBOX {
  struct FB_STATUS {
    double temp;
    int lit;
  } status;
  struct FB_CONTROL {
    GPIO_ELEM solen;
    GPIO_ELEM ignite;
    GPIO_ELEM audSel;
  } control;
} FIREBOX;


void init_gpio(AMP *RES, AMP *EXT, FIREBOX *FB);
void update(AMP *RES, AMP *EXT, FIREBOX *FB);
