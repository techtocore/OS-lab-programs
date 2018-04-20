/* THIS IS THE PROGRAM FOR SHARED MEMORY - READ
BY SHRIRAM K VASUDEVAN!
Well, This is yet another mechanism of Interprocess Communication.
This can be done between any two processes, That is they need not be related.
By default a page of memory (4kbytes) would be allocated for Shared memory
from any process.
Assume process 1 wants to access its Shared Memory area, It has to get attached
to it first. Though its P1's memory area, it cannot get access as such.
Only after attaching it can gain access.
There are three steps:
1. Initialization
2. Attach
3. Detach.
*/
// SHARED MEMORY - READ
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
int main ()
{
int r, shmid;

char *s, *mem,  c;

key_t key = 123;

// step 1 - initialization of shared memory

/* int shmget(key_t key, size_t size, int shmflg);

shmget()  returns  the identifier of the System V shared memory segment associated with the value of the argument key.   A  new  shared  memory segment,  with size equal to the value of size is created*/


shmid = shmget (key, 26, IPC_CREAT|0666 );

if (shmid < 0)
{
	printf ("The Creation has gone as a failure\n");

}
printf ("\n We are getting the shared memory created in read with id %d\n", shmid);

/* step 2 - attachment to shared memory

void *shmat(int shmid, const void *shmaddr, int shmflg);

shmat() attaches the System V shared memory segment identified by shmid to the address space of the calling process.  If  shmaddr  is NULL, the system chooses a suitable (unused) address at which to attach the segment

*/

mem = shmat (shmid, NULL, 0);

//On success shmat() returns the address of the attached shared memory segment

if (mem == NULL)
{
printf ("Attachment failure\n ");
return 0;
}
/* step 3 - reading from shared memory */

printf("\n The data read from shared memory is : \n \n");

for (s = mem; *s != '\0'; s++)
        putchar(*s);

putchar('\n');

/* Change the first character of the segment to '*', indicating we 		have read the segment.*/

    *mem = '*';


/* step 4 - detach from shared memory
int shmdt(const void *shmaddr);

int shmctl(int shmid, int cmd, struct shmid_ds *buf);
 */

r = shmdt (mem);

if (r < 0)
{
printf ("Couldn't detach\n");
return 0;
}

r = shmctl (shmid, IPC_RMID, NULL);

return 0;
}









