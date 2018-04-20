#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
// to execute a command from within the c program
int r = system("ls -l");
printf("%d\n",r);
return 0;
}


