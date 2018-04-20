#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{

int fd1,fd2;

fd1=open("txt8.txt",O_RDONLY|O_CREAT,0777);
fd2=fcntl(fd1,F_DUPFD,0);

//fd2=dup(fd1) 
// 0 1 2 3 4      where 3 and 4 will txt8.txt

while(1)
{
}

}

