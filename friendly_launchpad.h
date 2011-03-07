// Friendly Launchpad
// This is my attempt at making the MSP430 Launchpad as simple to program as the Arduino
// http://github.com/chrishulbert/friendly_launchpad

#ifndef __FRIENDLY_LAUNCHPAD_H
#define __FRIENDLY_LAUNCHPAD_H

#include <io.h>
#include <signal.h>

// Random defines
#define HIGH 1
#define LOW  0
#define OUTPUT 1
#define INPUT 0

// My functions
#define pinBit(pin) (1<<(pin-10))

// Arduino-ish functions
#define delay(milliseconds) for(int x=0;x<milliseconds;x++){for (int delayCountdown=0;delayCountdown<100;delayCountdown++){P2OUT^=BIT7;}}
#define pinMode(pin, mode) {if(mode){P1DIR|=(1<<(pin-10));}else{P1DIR&=~(1<<(pin-10));}}
#define digitalWrite(pin, mode) {if(mode){P1OUT |= (1<<(pin-10));}else{P1OUT&=~(1<<(pin-10));}}
#define digitalRead(pin) (P1IN & pinBit(pin) ? HIGH : LOW)

// The main loop
void setup();
void loop();
int main(void)
{
  // Stop watchdog
  WDTCTL = WDTPW + WDTHOLD;

  // Todo maybe remove the defaults?
  // Not necessary as they default to input just like arduino
  //P1DIR = 0; // All input (arduino's default?)
  //P2DIR = 0; // All input
  P1SEL = 0; // All GPIO
  P2SEL = 0; // All GPIO

  setup();
  for(;;) {
  	loop();    
  }

  return 0;
}


#endif // #ifndef __FRIENDLY_LAUNCHPAD_H
