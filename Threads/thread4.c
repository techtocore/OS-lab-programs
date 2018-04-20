#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

struct sum_arg
{
long n;
long s;
};


void* sum(void* args)
{
 struct sum_arg *arg = (struct sum_arg*) args;
 long r=0;
 
 for(long i = 0; i <= arg->n; i++)
  {
   r += i;
  }
  arg->s = arg->s + r;

  pthread_exit(NULL);
}

int main()
{
long i, n = 10;

pthread_t tids[3];

struct sum_arg arg;
arg.n = 10;
arg.s = 0;

//create thread

for(i = 0; i < 3; i++)
{
pthread_create(&tids[i], NULL, sum, &arg);
pthread_join(tids[i], NULL);
}

printf("Sum of first %ld numbers computed %ld times is %ld\n", arg.n, i, arg.s);
}
