
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int global;
int err;
pthread_t tid[2];
int i;
void *doStuff(void *arg);

void *doStuff(void *arg)
{
    //get id of thread
    pthread_t id = pthread_self();

    //check if its the first or the second thread running
    if (pthread_equal(id, tid[0]))
    {
        printf("\n First thread processing\n");
    }
    else
    {
        printf("\n Second thread processing\n");
    }

    // do stuff
    for(int j = 0; j < 9; j++){
        printf("stuff doing \t%d\n",j);
    }

    // exit thread;
    pthread_exit(0);
}

int main()
{
    //init of variables
    i = 0;
    pthread_attr_t t_attr;
    pthread_attr_init(&t_attr);
    void *val;

    while (i < 2)
    {
        // create thread
        err = pthread_create(&(tid[i]), &t_attr, &doStuff, NULL);

        //check if thread was created
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        else
            printf("\n Thread created successfully\n");

        pthread_join(&(tid[i]),val);

        i++;
    }
}
