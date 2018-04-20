# include <stdio.h>
# include <unistd.h>
#include<stdlib.h>
int main(void)
{
int ret;
ret = fork ();

if (ret > 0)
{
sleep (30); // Allow parent to execute and exit
printf (" \n Am Parent \n");
printf (" \n My PID is %d \n",getpid());
exit(1);
}

if (ret == 0)
{

printf (" \n AM CHILD \n");
printf (" \n My PID is %d \n",getpid());
printf (" \n My Parent PID is %d \n",getppid());
}
return 0;
}
