#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
int r;
r = fork();
printf("%d",r);

if (r==0)
{
//sleep(2); remove this comment after removing comment from exit(1) in parent
printf("I am child and my id is %d and my parent id is %d\n", getpid(),getppid());

}
if(r>0)
{
printf("I am parent and my id is %d and my child id is %d\n", getpid(),r);
//exit(1);
wait(NULL);
}
return 0;
}
