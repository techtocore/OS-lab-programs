#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{

int fd1,fd2;

fd1=open("txt5.txt",O_RDONLY|O_CREAT,0777);//txt5.txt will get fd no 3

//close(2); //we are closing error fd 2=stderr

//going to close the fd for std err 
//as we are duplicating the fd for txt5.txt another fd will be created which will be placed in 
//the closed position 2 - all fd s will be allocated with a no in a sequential order.
//so generated fd should be kept in slot 2

dup(fd1);

while(1)
{
}

}

