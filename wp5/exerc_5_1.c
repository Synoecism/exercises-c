/*
File name: exerc_x_x.c (or cpp)
Date: YYYY-MM-DD
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

bool keyhit; 
char key;
int row = 0;
int col;
int pind_value;

char keymap[4][4]=
{
		{'0','1','2','3'},
		{'4','5','6','7'},
		{'8','9','A','B'},
		{'C','D','E','F'}
};

char getKeyValue(int row, int col)
{
  return keymap[row][col]; 
}

int getColumn(int ext)
{  
  	//check which column is pressed
      switch(ext)
      {
       
        //column 1 (7 representing 0111)
        case 7:
        	return 1;
        //column 2 (11 representing 1011)
        case 11:
        	return 2;
        //column 3 (13 representing 1101)
        case 13:
        	return 3;
        //column 4 (14 representing 1110)
        case 14: 
        	return 4;
      }
}

void setPORTB(int i)
{
  //activate correct row
   
      //PORTB = B00000111; row 1
      //PORTB = B00001011; row 2
      //PORTB = B00001101; row 3
      //PORTB = B00001110; row 4
  
  	if(i == 0)
      {
      PORTB = B00000111;
      } 
      else if (i == 1)
      {
        PORTB = B00001011;
      }
      else if (i == 2)
      {
        PORTB = B00001101;
      }
      else if (i == 3)
      {
        PORTB = B00001110;
      }
}

void setup()
{
  //Init of terminal
  Serial.begin(9600);
  
  //PORT B (pin 8 to 13) is OUTPORT  with color BLUE which are ROWS
  //Using bit 0 - 3 as outport, value 1
  DDRB = DDRB | B00001111;
  
  //PORT D is INPORT with color GREEN which are COLUMNS
  //SETTING TO 0 MAKES THESE INPUT PINS
  DDRD = DDRD | B00000000; 
 
  //inbuilt method (attachinterput())
  //inbuilt method (digitalPinToInterrupt())
  //FALLING = 0
  //RISING = 1
  //https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
  attachInterrupt(digitalPinToInterrupt(2),keyboardirq,FALLING);
}

void incrementRow()
{
  row += 1;
  row = row % 4;
}

void loop()
{
  incrementRow();
  setPORTB(row);
  
  //continously check if keyhit is true
  if(keyhit)
  {
    Serial.println(key);
  }
  //set keyhit to false
  keyhit = false;
  
  delay(50);
}

// THIS IS CALLED WHEN THERE IS AN INTERRUPT REQUEST (IE PRESS OF KEY ON KEYPAD)
void keyboardirq(void)
{
  keyhit = true;
  //do stuff
 
  int numOfBytes = 4;
  int startPosition = 4;
  
  //get bit value (in decimal form) to read which column is in use
  //will only be called when row is activated
  int extractedNumber = (((1 << numOfBytes) - 1) & (PIND >> startPosition));
  
  //-1 since extracting from double array ranging from [0-3][0-3]
  col = getColumn(extractedNumber)-1;
  
  //get key value of keypad as matrix above
  key = getKeyValue(row,col);
}