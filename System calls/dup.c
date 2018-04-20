#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<fcntl.h>
int main()
{
//dup() creates a copy of fd , uses lowest numbered unused descriptor for the new descriptor
// both fds can be used interchangeably
int fd1 = open("dup1.txt",O_WRONLY|O_CREAT,0777);
close(2);
int fd2 = dup(fd1);
printf("%d %d\n",fd1, fd2);
write(fd1, "Writing using fd1\n", 19);
write(fd2, "Writing using fd2\n", 19);
while(1){}
return 0;
}



// explore dup2() and fcntl()

