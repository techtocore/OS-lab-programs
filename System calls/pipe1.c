
/*pipe()  creates a pipe, a unidirectional data  channel  that  can  be used  for  interprocess communication.  The array pipefd is used  to return  two file descriptors referring  to  the  ends  of  the  pipe.
pipefd[0] refers to the read end of the pipe.  pipefd[1] refers to  the
write  end of the pipe.  Data written to the write end of the pipe is
buffered  by the kernel until it is read from the read end of the pipe.*/

#include <stdio.h>
#include <unistd.h>
int main(void)
{
int pipefd[2]; // to be passed to pipe() system call
int r;
char arr[21]; 

pipe (pipefd);// pipe created successfully with one end as read (pipefd[0]) and other end as write(pipefd[1])

r = fork ();

if (r > 0) // parent
{
fflush(stdin);// to clear the input buffer
sleep(3);
printf(" I am Parent \n");
read(pipefd[0],arr,sizeof(arr));
 // parent reading the data from the read end of the pipe using pipefd[1]
write(1,arr,sizeof(arr)); // fd 1 is stdout
}

if(r == 0) // child
{

fflush(stdin);
printf("I am child executing first\n");
write(pipefd[1],"from child to parent",21);

}
return 0;
}

