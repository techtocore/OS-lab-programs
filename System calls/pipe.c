
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
char arr[15]; 

pipe (pipefd);// pipe created successfully with one end as read (pipefd[0]) and other end as write(pipefd[1])

r = fork ();

if (r > 0) // parent
{
fflush(stdin);// to clear the input buffer
printf(" I am Parent executing first\n");
write(pipefd[1],"Writing to pipe",15); // parent writing the data to the write end of the pipe using pipefd[1]
}

if(r == 0) // child
{
sleep(3); // waiting for three seconds until parent writes to pipe
fflush(stdin);
printf("I am child executing second\n");
read(pipefd[0],arr,sizeof(arr));
write(1,arr,sizeof(arr)); // fd 1 is stdout
}
return 0;
}

