#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
int r;
r = fork();

if (r==0)
{
execlp("ls","ls","ls","ls",NULL);
}
if(r>0)
{
wait(NULL);
printf("I am parent\n");
}

return 0;
}
