#include <stdio.h>
#include <stdbool.h> //import of boolean type
#include <ctype.h> // import of isdigit

int main()
{
    bool x = false;
    printf("Please select an option between 1-5! \n")
    while(!x)
    {
        //wait for input
        char ch = getchar();
        x = true;

        switch(ch){
            case '1':
                printf("\n Dionysius of Halicarnassus: Only the brave enjoy noble and glorious deaths. \n");
                break;
            case '2':
                printf("\n Lucius Annaeus Seneca: In war there is no prize for runner-up. \n");
                break;
            case '3':
                printf("\n Sophacles: Quick decisions are unsafe decisions. \n");
                break;
            case '4':
                printf("\n Thucydides: War is not so much a matter of weapons as of money. \n");
                break;
            case '5':
                printf("\n Euripides: Courage may be taught as a child is taught to speak. \n");
                break;            
            default:
                //used to consume \n unnecssary?:)
                getchar();

                //return to while
                printf("\n Please enter a valid choice between 1-5. \n");
                x = false;
                break;    
        }
    }
    return 0;
}