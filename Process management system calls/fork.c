#include<stdio.h>
#include<unistd.h>
int main()
{

int ret;
ret= fork();

if (ret >0)
{
printf("\n Am Parent");
printf(" \n Pid is %d",getpid());
}

if (ret ==0)
{
printf("\n Am Child");
printf(" \n Pid is %d",getpid());

printf(" \n Parent Pid is %d",getppid());
}
return 0;
}
