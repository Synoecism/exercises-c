#include <stdio.h>

void move();
void turn();
int start();
int stop();

enum DIRECTION
{
    N,
    O,
    S,
    W
};

typedef struct
{
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;

int main()
{

do {

    start();

    //When all instructions are executed robot stops and the program prints out the new robot positionfor the robot
    end();

}while(1);
//change while(1) to something else later
    return 0;
}

void move()
{
}

void turn()
{
}

int start()
{
}

int stop()
{
}