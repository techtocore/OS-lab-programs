
// thread is not a process 
// cc -o thr filename.c -lpthread
// cc -lpthread -o thr filename.c 


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
void* fnt(void* tno) {
  
 pthread_t t_id = pthread_self();
  // pthread_self() will give the thread id

  printf("Hey there I am thread with id %ld\n", t_id);

   pthread_exit(NULL);
// or return NULL;
}
 
int main() 
{
  pthread_t t; // thread identifier
/* int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg); */

   pthread_create(&t, NULL, fnt, NULL);
   
// if main thread completes execution before thread, thread will automatically exit. To make the main thread wait, use pthread_join


//int pthread_join(pthread_t thread, void **retval);
  pthread_join(t, NULL);


    printf("In main: thread has completed\n"); 
	
  exit(1);
}



