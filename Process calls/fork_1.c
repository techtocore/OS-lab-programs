#include  <stdio.h>
#include  <string.h>
#include  <sys/types.h>

void  main(void)
{
     int    i,r;

     r=fork();
     for (i = 1; i <= 5; i++) {
          printf("This line is from pid %d, value = %d\n", getpid(), i);
		sleep(3);
     } 
}
