#include "stringIO.h"

void printMilliseconds(uint16_t value){
  transmitString("\r\nYou took ");
  uint8_t digit;
  digit = 0;
  while(value >= 10000){
    digit++;
    value -= 10000;
  }
  if (digit){
    transmitByte('0' + digit);
  }
  digit = 0;
  while(value >= 1000){
    digit++;
    value -= 1000;
  }
  transmitByte('0' + digit);
  transmitByte('.');
  digit = 0;
  while(value >= 100){
    digit++;
    value -= 100;
  }
  transmitByte('0' + digit);
  digit = 0;
  while(value >= 10){
    digit++;
    value -= 10;
  }
  transmitByte('0' + digit);
  // Ones digit is easy.
  transmitByte('0' + value);

  transmitString(" seconds.\r\n");
}

void printComments(uint16_t value){
  if (value > 1000){
    transmitString("---->  Hello?\r\n");
  }
  else if (value > 500){
    transmitString("---->  Slow.\r\n");    
  }
  else if (value > 250){
    transmitString("---->  Have another cup of coffee.\r\n");    
  }
  else if (value > 200){
    transmitString("---->  Respectable.\r\n");    
  }
  else if (value >= 150){
    transmitString("---->  Fast.\r\n");    
  }
  else if (value < 150){
    transmitString("---->  Amazing!\r\n");    
  }
}

void randomDelay(void){
  uint8_t randomTime;
  _delay_ms(1000);	    /* wait at least one second */
				/* "random" extra time to about 2.5 sec */
  randomTime = (uint8_t) TCNT1; /* take value from timer */
  while(--randomTime){  /* not really random, but hard to control */
    _delay_ms(10);		/* (like coin-flipping) */
  }
}

