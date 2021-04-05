#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

			/* always change


void state_advance()		/* alternate between toggling red & green */
void state_advance()
{
  char changed=0;
  static enum {R=0,G=1} color=G;
  switch (color) {
  case R: green_on=1; red_on=0; color= G; break;
  case G: red_on=1; green_on=0;color = R; break;
  }
  changed=1;

  led_changed = changed;
  led_update();
}



