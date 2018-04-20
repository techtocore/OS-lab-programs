#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
int main()
{
int fd1, fd2, fd3, ret;

fd1 = open("tex1.txt",O_RDONLY|O_CREAT, 0777);
fd2 = open("tex2.txt",O_RDONLY|O_CREAT, 0777);
close(fd2); // to remove entry from fd table so that it can be reallocated to another file
// but will not delete the file

fd3 = open("tex3.txt",O_RDONLY|O_CREAT, 0777);

ret = unlink("tex2.txt"); // will remove the file permanently from the system
while(1)
{
}
}
