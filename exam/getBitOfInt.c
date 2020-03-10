

void printStatus(int status)
{
    int printout = 0, n;
    /*
    for (n = 0; n < 4; n++)
    {
        printout = status & 0x000F;
        printf("\n Sensor nr %d : %d", n, printout);
        status = status >> 4;
    }
    */

    printout = status & 0x000F;
    printf("\n Sensor nr %d : %d", n, printout);

    printout = status & 0x00F0;
    printf("\n Sensor nr %d : %d", n, printout);

    printout = status & 0x0F00;
    printf("\n Sensor nr %d : %d", n, printout);

    printout = status & 0xF000;
    printf("\n Sensor nr %d : %d", n, printout);
}

int main()
{
    printStatus(12423);
    return 0;
}