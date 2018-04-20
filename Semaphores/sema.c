/* Semaphore example program a (sema.c) */
/* We have two programs, sema and semb. Semb may be initiated at any 
  time, but will be forced to wait until sema is executed. Sema and
  semb do not have to be executed by the same user! */

// sema does signal i.e V operation

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>

#define KEY (1492)
/* This is the external name by which the semaphore is known to any
   program that wishes to access it. */

void main()
{
   int id;  /* Internal identifier of the semaphore. */

   struct sembuf op;
   /* struct sembuf op[1];
   An "array" of one operation to perform on the semaphore. */
   

   int retval; /* Return value from semop() */
   
   // int semget(key_t key, int nsems, int semflg);
        // nsems : number of semaphores to create

   /* Get the index for the semaphore with external name KEY. */
   id = semget(KEY, 1, 0666);

   if(id < 0)
   /* Semaphore does not exist. */
   {
      fprintf(stderr, "Program sema cannot find semaphore, exiting.\n");
      exit(0);
   }

   /* Do a semaphore V-operation. */
   printf("Program sema about to do a V-operation. \n");

   /* Set up the sembuf structure. */
   /* Which semaphore in the semaphore array : */
    op.sem_num = 0;
    /* Which operation? Add 1 to semaphore value : */
    op.sem_op = 1;
    /* 0: waiting on semaphore, Set the flag so we will wait : */   
    op.sem_flg = 0;

    
     //  int semop(int semid, struct sembuf *sops, size_t nsops);
     // nsops is 1 here as we are creating only one structure variable for sembuf (struct sembuf op;), if it is an array, give the index number as variable

    /* So do the operation - signal - V! */

    retval = semop(id, &op, 1);

    if(retval == 0)
    {
       printf("Successful V-operation by program sema.\n");
    }
    else
    {
       printf("sema: V-operation did not succeed.\n");
	perror("REASON");
    }
}

/* Think carefully about what the V-operation does. If sema is executed 
   twice, then semb can execute twice. */

