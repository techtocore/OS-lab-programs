#include <stdio.h>
#include <unistd.h>
 
int main()
{
    int id,i;
     
    printf("Start of main...\n");
     
    id=fork();


    if(id>0)
    {
        /*parent process*/
        printf("Parent section...\n");
    }
    else if(id==0)
    {
        /*child process*/
        printf("\nfork created...child section\n");
    }
    else
    {
        /*fork creation faile*/
        printf("\nfork creation failed!!!\n");
    }
     
    printf("Printing the numbers from 1 to 5\n");
    for(i=1; i<=5; i++)
        printf("%d ",i);
    printf("\n");
    printf("End of the main function...\n");
 while(1){}
    return 0;
}
