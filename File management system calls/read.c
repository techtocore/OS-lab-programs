#include<stdio.h>
#include <fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
  int fd, sz , fdw,ret;
  //char *c = (char *) calloc(100, sizeof(char));
char buff[12], buffer[12]="I love God";
 
  fd = open("foo.txt", O_RDONLY|O_CREAT,0777);

  if (fd < 0) { perror("r1"); exit(1); }
 
  sz = read(fd, buff, sizeof(buff));
  printf("called read");
  //Printing the contents of buff
	printf("The output is %s \n",buff);
close(sz);

  //wrting
printf("WRiting starts");

fdw =creat("foo.txt",0777);
//Writing the contents of buffer to the file (softlink)
printf("Writing the contents of buffer to the file (softlink)");

	ret =write(fdw,buffer,sizeof(buffer));

printf("closing starts");
close(fdw);
printf("closed:");

  
 

}
