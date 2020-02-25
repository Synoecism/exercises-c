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

bool keyhit; 
char key;
int row = 0;
int col;
const int analogPin = A0;
float tempAnalogValue;

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

void incrementRow()
{
  row += 1;
  row = row % 4;
}

bool isRowInUse(int ext)
{
  //if extracted number is 15, then row is not in use
  if(ext != 15)
  {
    return true;
  } 
  else 
  {
    return false;
  }
}

// INTERRUPT REQUEST - WILL BE CALLED WHEN THERE IS AN INTERRUPRT
void keyboardirs(void)
{ 
  int numOfBytes = 4;
  int startPosition = 4;
  
  for(int i = 0; i < 4; i++)
  {
    //an unneccessary method
    incrementRow();
    
    //activate row
  	setPORTB(row);
    
    //get bit value (in decimal form) to read which column is in use
  	//will only be called when row is activated
  	int extractedNumber = (((1 << numOfBytes) - 1) & (PIND >> startPosition));
        
    //check if current row is in use/any key on row is pressed
    if(isRowInUse(extractedNumber))
    {
      	//accept keyhit
        keyhit = true;

      	//-1 since extracting from double array ranging from [0-3][0-3]
  		col = getColumn(extractedNumber)-1;
       
  		//get key value of keypad as matrix above
  		key = getKeyValue(row,col);
      
        //break of loop necessary to exclude multiple key prints	
      	break;
    }
  }
}

float calculateTemp(float sensorValue){
 
  // convert from decimal to voltage
  // 0.004882814 due to (5v / 1024)
  // converts the 0 to 1023 value that analogRead() returns
  float voltage = (sensorValue * 0.004882814);
 
  //voltage - 0.5 shifts the output value. Reading minimum temp of -50° then equals 0V.
  //The new value is within the temperature range -0.5 to 1.25
  //Multiplying by 100 to get the celcius
  float celcius = (voltage - 0.5) * 100;
  
  return celcius;
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
 
  //similar to eventListener
  //inbuilt method (attachinterput())
  //inbuilt method (digitalPinToInterrupt())
  //FALLING = 0
  //RISING = 1
  //https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
  attachInterrupt(digitalPinToInterrupt(2),keyboardirs,FALLING);
}

void loop()
{
  //set all outgoing ports to 0
  PORTB = B00000000;
  
    
     //continously check if any key is hit
  if(keyhit)
  {
    	Serial.println(key);
    	key = NULL;
  }
  

  //set keyhit to false
  keyhit = false;
    
  //read the analog input pin
  tempAnalogValue = analogRead(analogPin); 
    
  float temperature = calculateTemp(tempAnalogValue);
  
  Serial.print("Temp in Celsius is: ");
  Serial.println(temperature);
  
  delay(500);
  
}
  