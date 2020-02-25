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

#include <avr/io.h>
#include <util/delay.h>

//https://exploreembedded.com/wiki/AVR_I/O_Register_Configuration
//https://www.arduino.cc/en/Reference/PortManipulation

int main()
{ 
  
  	// Configure PORTD as output
    DDRD = 0xff;   
  
  	// Configure PORTB as input
    DDRB = 0x00; 
  
  	// Turn ON the first two Leds connected to PORTD
    PORTD = 0x3;
  
  	int c = 1;
  	int c2 = 2;
  
  	int dib_switch;

    while(1)
    {
      	//Read the input from the switch
      	dib_switch = PINB;
     
      	c = c % 8;
      	c2 = c2 % 8;
        _delay_ms(500);
      
      	//two parenthesis since we have two bits
      	PORTD = (1<<c)|(1<<c2);
        _delay_ms(500);
      
      	PORTD = (1<<0);
      	_delay_ms(100);
      	PORTD = (0<<0);
      
      //if dib_switch is flicked, move the lights
      if(dib_switch == 1){
        c = c+1;
      	c2 = c2+1;
      } 
    }
    return 0;
}