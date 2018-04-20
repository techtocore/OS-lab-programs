// SHARED MEMORY - WRITE
/*
Another mechanism of Interprocess Communication.
This can be done between any two processes, That is they need not be related. By default a page of memory (4kbytes) would be allocated for Shared memory from any process.

There are three steps:
1. Initialization
2. Attach
3. Detach.
*/
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main ()
{
int r, shmid;
char *p, *mem,  c;
key_t key = 123;

// step 1 - initialization of shared memory

/* int shmget(key_t key, size_t size, int shmflg);

shmget()  returns  the identifier of the System V shared memory segment associated with the value of the argument key.   A  new  shared  memory segment,  with size equal to the value of size is created*/


shmid = shmget (key, 26, IPC_CREAT|0666 );

if (shmid < 0)
{
	printf ("The Creation has gone as a failure \n");

}
printf ("We are getting the shared memory created with id %d\n", shmid);

/* step 2 - attach to shared memory

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
/*  write some content to memory */

p =  mem;

for (c = 'a'; c <= 'z'; c++)
{
	*p++ = c;
}

/* Wait until the other process changes the first character of our memory to '*', indicating that it has read what we put there.
*/

printf("\n Waiting for reader to read the string and change the first character to * \n");

while ( *mem != '*')
	sleep(1);

printf("\n Modified string is \n \n");

for (p = mem; *p != '\0'; p++)
        putchar(*p);

putchar('\n');

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


/* if shhmdt and shmctl are commented , reader can access the shared memory any time it is executed.. */

return 0;
}






