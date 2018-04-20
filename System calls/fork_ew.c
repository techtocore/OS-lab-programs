#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

/*A parent process may wait for the termination of a child process by using the wait() system call. The wait() system call is passed a parameter that allows the parent to obtain the exit status of the child. This system call also returns the process identifier of the terminated child so that the parent can tell which of its children has terminated:

When a process terminates, its resources are deallocated by the operating system. However, its entry in the process table must remain there until the parent calls wait() , because the process table contains the process’s exit status. A process that has terminated, but whose parent has not yet called wait() , is known as a zombie process. All processes transition to this state when they terminate, but generally they exist as zombies only briefly. Once the parent
calls wait() , the process identifier of the zombie process and its entry in the process table are released.*/
int main()
{
int r;
r = fork();

if (r==0)
{

printf("I am child and my id is %d and my parent id is %d\n", getpid(),getppid());
exit(1);

}
if(r>0)
{
printf("I am parent and my id is %d and my child id is %d\n", getpid(),r);
int status;
//int pid = wait(&status);
//printf("pid %d\n",pid);
}

return 0;
}
