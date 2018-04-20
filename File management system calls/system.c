#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{

printf("\n On Error , I shall return 1");
int ret1,ret2;

ret1 = system("ls -lrt");
printf("\n the return value is %d",ret1);

ret2 = system("pwd");
printf("\n the return value is %d",ret2);


return 0;

}



