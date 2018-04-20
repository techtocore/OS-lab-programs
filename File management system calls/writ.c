#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
char buffer[12]="I love God";
int fd1,ret;
fd1=creat("txt4.txt",0777);
ret=write(fd1,buffer,sizeof(buffer));
return 0;
}

