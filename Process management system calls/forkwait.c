#include<stdio.h>
#include<unistd.h>
# include <sys/wait.h>
int main()
{

int ret,status,p;
ret= fork();

if (ret >0)
{
printf("\n Am Parent");
p= wait (&status);
printf(" \n Pid is %d",getpid());
}

if (ret ==0)
{
printf("\n Am Child");
printf(" \n Pid is %d",getpid());

printf(" \n Parent Pid is %d",getppid());
}

if (WIFEXITED (status))
printf ("EXIT IS NORMAL");
return 0;
}
