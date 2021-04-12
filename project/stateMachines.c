#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
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
void dim_green(){
  red_on=0;
  if (green_on==0)
    green_on=1;
  else if(green_on==1){
    green_on=0;
  }
  led_changed=1;
  led_update();
}
void dim_red(){
  green_on=0;
  if(red_on==0)
    red_on=1;
  else if (red_on==1)
    red_on=0;
  led_changed=1;
  led_update();
}
void bright_green(){
  red_on=0;
  green_on=1;
  led_changed=1;
  led_update();
}
void bright_red(){
  green_on=0;
  red_on=1;
  led_changed=1;
  led_update();
}

void superMarioTheme(){
  if(switch_state_changed==4){
    green_on=0;
    red_on=0;
    switch(song_counter){

    case 0:

    case 1:

    case 2:

    case 4: buzzer_set_period(750); song_counter++; break; //E note

    case 3: buzzer_set_period(950); song_counter++; break; //C note

    case 5: buzzer_set_period(630); song_counter++; break; //G note

    case 6: buzzer_set_period(1260); song_counter = 0; break; //Lower G note

    }
    led_changed=1;
    led_update();
  }
  else{
    buzzer_set_period(0);
  }
}

