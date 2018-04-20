//to create hard link and soft link

#include<stdio.h>
#include<unistd.h>
int main()
{
/*
Hard Link:

    You have one file with two different filenames.
    If you edit one, it gets edited in all filename locations.
    If you delete one, it still exists in other places.
    Only one file on disk.

Soft Link:

    You have one file with one filename and a pointer to that file with 	the other filename.
    If you edit the link, its really editing the original file.
    If you delete the file, the link is broken.
    If you remove the link, the file stays in place.
    Only one file on disk.

*/

int hl = link("link.c","hl.c"); // hard link



int sl = symlink("link.c","sl.c"); // soft link

}

