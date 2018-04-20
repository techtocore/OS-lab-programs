#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main()
{
char data[30]="Writing to text1";
char arr[30];

int fd1, fd2, r1, r2;

fd1 = open("text1.txt",O_RDWR|O_CREAT,0777);

r1 = write(fd1, data, sizeof(data));

close(fd1);
fd2=open("text1.txt",O_RDONLY);

r2 = read(fd2, arr, sizeof(data));

printf("Data read : %s\n", arr);

return 0;
}



