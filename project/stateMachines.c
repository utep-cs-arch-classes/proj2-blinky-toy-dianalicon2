#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

			/* always change


void state_advance()		/* alternate between toggling red & green */
static int song_counter=0;
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
void dim_red(){
  char changed=0;
  red_on=0;
  if (green_on==0)
    green_on=1;
  else if(green_on==1){
    green_on=0;
  }
  changed=1;
  led_changed=changed;
  led_update();
}
void bright_red(){
  char changed=0;
  red_on=0;
  green_on=1;
  changed=1;
  led_changed=changed;
  led_update();
}

void superMarioTheme(){

  switch(song_counter){

  case 0:

  case 1:

  case 2:

  case 4: buzzer_set_period(750); counterForSMTheme++; break; //E note

  case 3: buzzer_set_period(950); counterForSMTheme++; break; //C note

  case 5: buzzer_set_period(630); counterForSMTheme++; break; //G note

  case 6: buzzer_set_period(1260); counterForSMTheme = 0; break; //Lower G note

  }

}

