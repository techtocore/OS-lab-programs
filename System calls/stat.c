/*     #include <sys/stat.h>
       #include <unistd.h>
stat and fstat

int stat(const char *pathname, struct stat *statbuf);
int fstat(int fd, struct stat *statbuf);

The stat structure
       All of these system calls return a stat structure, which contains the
       following fields:

           struct stat {
               dev_t     st_dev;         ID of device containing file 
               ino_t     st_ino;         /* Inode number 
               mode_t    st_mode;        /* File type and mode 
               nlink_t   st_nlink;       /* Number of hard links 
               uid_t     st_uid;         /* User ID of owner 
               gid_t     st_gid;         /* Group ID of owner 
               dev_t     st_rdev;        /* Device ID (if special file) 
               off_t     st_size;        /* Total size, in bytes 
               blksize_t st_blksize;     /* Block size for filesystem I/O 
               blkcnt_t  st_blocks;      /* Number of 512B blocks allocated 

               /* Since Linux 2.6, the kernel supports nanosecond
                  precision for the following timestamp fields.
                  For the details before Linux 2.6, see NOTES. 

               struct timespec st_atim;  /* Time of last access 
               struct timespec st_mtim;  /* Time of last modification 
               struct timespec st_ctim;  /* Time of last status change 

           #define st_atime st_atim.tv_sec      /* Backward compatibility 
           #define st_mtime st_mtim.tv_sec
           #define st_ctime st_ctim.tv_sec
           };
*/



#include<stdio.h>
#include <sys/stat.h>

int main(void)
{
struct stat st1,st2;
stat("file", &st1);
fstat(1, &st2);

printf("Output for stat(\"file\", &st1) : \n");
printf("Uid : %d\n", st1.st_uid);
printf("Inode : %ld\n",st1.st_ino);

printf("Output for fstat(1, &st2) : \n");
printf("Uid : %d\n", st2.st_uid);
printf("Inode : %ld\n",st2.st_ino);
}
