#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
 int fd1,fd2;

 fd1=open("txt3.txt",O_RDONLY|O_CREAT,0777);
 fd2=open("txt4.txt",O_RDONLY|O_CREAT,0777);
	while(1)
	{
	}
}

