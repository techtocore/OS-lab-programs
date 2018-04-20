#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
sleep(5);
printf("\n test");
//execlp("ls","ls","-lrt",0);
//it should now come out of the process
// and print -lrt
execl("/bin/ls","ls","-lrt",0);
// here need to give the complete path

printf("\n Command executed");
//this above line will not be printed

}
