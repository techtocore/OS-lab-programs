#include <stdio.h>
#include <unistd.h>
 
int main()
{
    int i;
     
    for(i=1; i<=2; i++)
	{
	fork();
        printf("Hello %d\n",i);}
 
    return 0;
}
