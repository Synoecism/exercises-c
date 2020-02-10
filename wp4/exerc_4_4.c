/*
File name: exerc_4_4.c (or cpp)
Date: 2020-02-02
Group nr 1
Members that contribute to the solutions
Emanuel Dellsén
Niklas Möller
Karl Westgårdh 

Member not present at demonstration time:
NONE

Demonstration code: []
Important
No code no exercise points!
*/


// ---- Program template for Arduino in Tinkercad VT 2020

/* --- Macros predefined for the compiler
DDRB Data direction register B
PORTB Outport B
PINB Inport B
DDRD Data direction register D
PORTD Outport D
PIND Inport D
*/

#include <avr/io.h>
#include <util/delay.h>

	int c;
  	int c2; 
  	int dib_switch;

void setup()
{
  //Values for shifting the bytes
  c = 1;
  c2 = 2;
  
   	// never use serial it causes problems with the leds
  	// Configure PORTD as output
    DDRD = 0xff;
  	// Configure PORTB as input
    DDRB = 0x00;

  	// Turn ON the first two Leds connected to PORTD
    PORTD = 0x3;

  
}

void loop(){

      	//Read the input from the switch
      	dib_switch = PINB;
      	
  		//Using modular to reset values above 7 to 0
  		c = c % 8;
      	c2 = c2 % 8;
        
  		_delay_ms(500);      // Wait for some time
      	//two parenthesis since we have two bits
      	PORTD = (1<<c)|(1<<c2);

  		//if dib_switch is flicked, move the lights
      	if(dib_switch == 1){
        c = c+1;
      	c2 = c2+1;
      }
      
    }
