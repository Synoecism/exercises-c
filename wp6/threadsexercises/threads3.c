#include <pthread.h>
#include <stdio.h>

int x, y;

/* this function is run by the second thread */
void *inc_x(void *x_void_ptr)
{
    /* increment x to 100 */
    int *x_ptr = (int *)x_void_ptr;

    //increment x by 10
    for(int i = 0; i < 10; i++){
        ++*x_ptr;

        //print current value
        printf("x is (inside thread %d): %d \n",pthread_self(),*x_ptr);
    }

    /* the function must return something - NULL will do */
    return NULL;
}

int main()
{
    x = 0;
    y = 0;


    /* show the initial values of x and y */
    printf("x: %d, y: %d\n", x, y);

    pthread_t t_id;
    pthread_t t_id2;
    int i;

    //thread creation should be in loop
    if (pthread_create(&t_id, NULL, inc_x, &x))
    {
        perror("ERROR");
    }

    if (pthread_create(&t_id2, NULL, inc_x, &x))
    {
        perror("ERROR");
    }

    //thread joining should be in loop
    if (pthread_join(t_id, NULL))
    {
        fprintf(stderr, "Error joining thread\n");
        return 2;
    }
    if (pthread_join(t_id2, NULL))
    {
        fprintf(stderr, "Error joining thread\n");
        return 2;
    }

    /* show the results - x is now 100 thanks to the second thread */
    printf("x: %d, y: %d\n", x, y);

    return 0;
}