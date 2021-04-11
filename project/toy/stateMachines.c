#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

void state_advance(){
  static char state = 0;
  state=!state;
  led_dim(state);
}
