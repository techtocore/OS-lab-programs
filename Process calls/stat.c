#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
int main(void)
{
int fd;
struct stat status;
// stat is the structure that is internally maintained.
// we are trying to create an instance of the stat structure, thro which we can acc
stat ("fork.c", &status); // We are passing the file as an argument here.
printf ("\n I-NODE number = %d", status.st_ino); // ret i node number.
printf ("\n User Id = %d", status.st_uid); // ret user id.
printf ("\n hard link = %d", status.st_nlink); // return hard link detail
}
