
// thread is not a process 
// cc -o thr filename.c -lpthread
// cc -lpthread -o thr filename.c 


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
void* fnt(void* tno) {

  long t_no = (long) tno;
  
  pthread_t t_id = pthread_self();
  // pthread_self() will give the thread id

  printf("Hey there, I am thread number %ld \n with thread id %ld\n", t_no, t_id);
 
  //return NULL; // either return or exit
   pthread_exit(NULL);

}
 
int main() 
{
  pthread_t threads[3];
  int r;
  long i;
 
  // create all threads one by one
  for (i = 0; i < 3; ++i) {

    printf("In main: creating thread %ld\n", i);
sleep(2);
/* int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg); */

    r = pthread_create(&threads[i], NULL, fnt, (void*)i);

// returns 0 on success

 if(r)
	{
         printf("Ooops, there is some error %d\n", r);
         exit(-1);
	}

//  The  pthread_join(pthread_t thread, void **retval)  function  waits for the thread specified by thread to terminate.  If  that  thread has already terminated, then pthread_join() returns immediately.

//int pthread_join(pthread_t thread, void **retval);
}
 for (i = 0; i < 3; ++i) {
r = pthread_join(threads[i], NULL);
// returns 0 on success
   if(r)
	{
         printf("Ooops, there is some error %d\n", r);
         exit(-1);
	}
    printf("In main: thread %ld has completed\n", i); 
sleep(2);
  }
 
  printf("In main: All threads completed successfully\n");
  exit(1);
}



