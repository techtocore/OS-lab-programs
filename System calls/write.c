#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main()
{
char data[30]="Writing to text document";
char arr[30];

int fd1, fd2, r1, r2;

fd1 = open("text.txt",O_RDWR|O_CREAT);

r1 = write(fd1, data, sizeof(data));

lseek(fd1,0,0);

r2 = read(fd1, arr, sizeof(data));

printf("Data read : %s\n", arr);

return 0;
}



