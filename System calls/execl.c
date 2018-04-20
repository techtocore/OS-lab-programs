#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
printf("Printing once\n");

//all exec() family system calls loads the pgm into current process space and runs it from entry point, control never returns to the original pgm until there is an error

/*
functions in exec() system calls has different behaviours

    l : arguments are passed as a list of strings to the main()
    v : arguments are passed as an array of strings to the main()
    p : path/s to search for the new running program
    e : the environment can be specified by the caller */


// exec, along with combinations of l, v, p, e

//execlp("exit(1)","exit(1)","-lr",NULL);

execl("/bin/ls","ls","-l","-r",NULL); //full path required
 
printf("Printing second\n");
return 0;
}


