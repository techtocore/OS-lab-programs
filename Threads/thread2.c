#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


long s = 0;

void* sum(void* arg)
{
 long val = (long) arg;
 
 for(long i = 0; i <= val; i++)
  {
   s += i;
  }
  pthread_exit(NULL);
}

int main()
{
long n = 10;

pthread_t tid;

//pthread_attr_t attr;
//pthread_attr_init(&attr);

pthread_create(&tid, NULL, sum, (void*)n);
// wait till thread is done

pthread_join(tid, NULL);

printf("Sum of first %ld numbers is %ld\n",n, s);
}
