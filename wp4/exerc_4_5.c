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

int value = 0;
int i;
int row;
int col;
char key;
char keymap[4][4] =
    {
        {'0', '1', '2', '3'},
        {'4', '5', '6', '7'},
        {'8', '9', 'A', 'B'},
        {'C', 'D', 'E', 'F'}};

char getKeyValue(int row, int col)
{
  return keymap[row][col];
}

int getColumn(int extractedNumber)
{
  //check which column is pressed
  switch (extractedNumber)
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
  default:
    Serial.println("Something return");
    return 0;
  }
}

void setPORTB(int i)
{
  //activate correct row

  //PORTB = B00000111; row 1
  //PORTB = B00001011; row 2
  //PORTB = B00001101; row 3
  //PORTB = B00001110; row 4

  if (i == 0)
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

bool checkIfKeyIsPressed(int ext)
{
  // check if key is pressed (15 = 1111 ie not pressed)
  if (ext != 15)
  {
    return true;
  }
  return false;
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
}
void loop()
{
  col = 0;
  row = 0;

  //iterate over the rows
  for (i = 0; i < 4; i++)
  {

    setPORTB(i);

    row = i;

    int numOfBytes = 4;
    int startPosition = 4;

    //get the values of PIND(4-7)
    int extractedNumber = (((1 << numOfBytes) - 1) & (PIND >> startPosition));

    //check if keypad is pressed
    if (checkIfKeyIsPressed(extractedNumber))
    {
      // get the specific column based on nibbet
      col = getColumn(extractedNumber);
      if (col != 0)
      {
        // get key value depending on row and column
        key = getKeyValue(row, (col - 1));

        //print key value
        Serial.print("Key value is: ");
        Serial.println(key);
      }
    }
  }

  //delay by 1 second
  delay(1000);
}