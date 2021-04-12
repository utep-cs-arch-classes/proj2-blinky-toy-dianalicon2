#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  if (++blink_count == 125 && switch_state_changed==1) {
    state_advance();
    superMarioTheme();
    blink_count = 0;
  }
  else if(blink_count>125 && blink_count%2==0 && switch_state_changed==2){
    dim_green();
    superMarioTheme();
  }
  else if(blink_count<125 && switch_state_changed==2){
    bright_green();
    superMarioTheme();
    
  }
  else if(blink_count>125 && blink_count%2==0 &&switch_state_changed==3 ){
    dim_red();
  }
  else if(blink_count<125 && switch_state_changed==3){
    bright_red_s();
  }
  else if (switch_state_changed==4 && blink_count==62){
    superMarioTheme();
    blink_count=0;
  }
}
