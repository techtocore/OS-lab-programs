#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
int fd, r;
char arr[30];
fd = open ("/tmp/onefifo",O_RDONLY);

r = read (fd, arr, sizeof (arr));

fflush(stdin);

write(1, arr, sizeof (arr));

close (fd);
return 0;
}
