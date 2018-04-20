#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{

int fd1,fd2,fd3;

fd1=open("txt6.txt",O_RDONLY|O_CREAT,0777);// here fd 3 for txt6.txt
fd2=open("txt7.txt",O_RDONLY|O_CREAT,0777); // here fd 4 for txt6.txt

fd3= dup2(fd1,fd2);
/*duplicating fd1 to fd2 at the position where u need to duplicate where as dup will duplicate at the first available position*/

while(1)
{
}

}

