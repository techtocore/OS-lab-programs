#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
int fd1;
fd1=open("one.txt",O_RDONLY|O_CREAT,0777);
if(fd1 == -1)
{
	printf("Open failed \n");
}
else
	printf("Success\n");

while(1){}

}
