
/* to illustrate communication between different processes which are not related.
write can complete its execution unless reader reads data
run this FIFO-write pgm first in one terminal and in another terminal run fifo-read second
*/

//man fifo command will give the required header files

#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
int main ()
{
int fd, r;
char arr [30] = "Writing through fifo";
fflush (stdin);
r = mkfifo ("/tmp/onefifo", 0666);
fd= open ("/tmp/onefifo",O_WRONLY);
write (fd, arr, sizeof(arr));
close (fd);
return 0;
}
