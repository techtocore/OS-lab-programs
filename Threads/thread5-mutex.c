#include <pthread.h>
#include<stdlib.h>
#include<stdio.h>
#define n 5
int counter; /* incremented by threads */

pthread_mutex_t lock;

void *fnt(void *);
	
int main(int argc, char **argv) {
	pthread_t tidA, tidB;
        pthread_mutex_init(&lock, NULL);

	pthread_create(&tidA, NULL, &fnt, NULL);
	pthread_create(&tidB, NULL, &fnt, NULL);

	pthread_join(tidA, NULL);
	pthread_join(tidB, NULL);
	exit(0);
}

void * fnt(void *vptr) {
	int i, val;

	/* Each thread fetches, prints, and increments the counter "n"
	times. The value of the counter should increase monotonically. 		*/
	
	for (i = 0; i < n; i++) {
		pthread_mutex_lock(&lock);
		val = counter;
		printf("Thread id %ld: counter value %d\n", pthread_self(), val + 1);
		counter = val + 1;
		pthread_mutex_unlock(&lock);
	}
	return (NULL);
}
