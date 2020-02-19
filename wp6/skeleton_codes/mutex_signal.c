
/* Test simple use of mutex   mutex_2.c */
/* Rev 2020-02- 17*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#define MAX 20

void *prod1 (void *param);
void *print1 (void *param);

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;
pthread_cond_t empty = PTHREAD_COND_INITIALIZER;

int buf[20];
int full_buf=0;
int pos=0;

int main (int argc, char **argv)
{
    pthread_t p1, p2;
	int n,i=0;

	pthread_create(&p1,NULL,prod1,NULL);
	pthread_create(&p2,NULL,print1,NULL);
	
	while(1){
	   puts("\n Main is running");
	   for (n=0; n<20000; n++); // Some delay
	   puts("\n Main is running end part");
	}
	
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	return (0);
}

void *prod1 (void *param){
	int n,p,i=0,m, r;
	while(1){
		if ((r = pthread_mutex_lock (&mutex)) != 0) {
            fprintf (stderr, "Error = %d (%s)\n", r, strerror (r)); exit (1);
        }
		if(full_buf){
		    pthread_cond_wait(&empty, &mutex);
		}
		
		    if(pos<MAX-1){
		      n=rand()%20 + 65;  // Gives AB....	
		      printf("\n Produced nr %d %c", pos, n );
		      buf[pos]= n;
		      for(p=0; p<1000; p++); // To delay a bit  
		      pos++;
		
		   }
		
		 if (pos==19) {
			 full_buf=1;
		     pthread_cond_signal(&full);
		 }
		 if ((r = pthread_mutex_unlock (&mutex)) != 0) {
            fprintf (stderr, "Error = %d (%s)\n", r, strerror (r)); exit (1);
        }
		for(m=0; m<1000; m++); // To delay a bit , give time for prod
	}
		
}

void *print1 (void *param){
	int m,n=0,i=0,r;
	while(1){
	    if ((r = pthread_mutex_lock (&mutex)) != 0) {
            fprintf (stderr, "Error = %d (%s)\n", r, strerror (r)); exit (1);
        }
		if(!full_buf){
		   pthread_cond_wait(&full, &mutex);
		}
		if (pos > 0){
		  pos--;  
		  printf("\n Out %c nr %d ", buf[pos], pos);
		  for(n=0; n<1000; n++); // To delay a bit 
		}
		printf("\n Print running");
		if (pos==0){
			full_buf=0;
			pthread_cond_signal(&empty);
		}
		if ((r = pthread_mutex_unlock (&mutex)) != 0) {
            fprintf (stderr, "Error = %d (%s)\n", r, strerror (r)); exit (1);
		}
		for(m=0; m<1000; m++); // To delay a bit , give time for prod.
	}
}
	

	
	
    