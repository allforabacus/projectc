
/********* IMPLEMENTATION OF ls/dir IN Unix TO DISPLAY CONTENTS OF A dIRECTORY********/

#include <sys/types.h>
#include <dirent.h>

#include <stdio.h>

int main(int argc, char *argv[])
{

struct dirent *de=NULL;
DIR *d=NULL;

if(argc != 2)
  {
    fprintf(stderr,"Usage: %s dirname\n",argv[0]);
    return(1);
  }

 d=opendir(argv[1]);
  if(d == NULL)
  {
   printf("Couldn't open directory");
   return(0);
  }

  		// Loop while not NULL
 while(de = readdir(d))
 printf("%s\n",de->d_name);

 closedir(d);
 return(0);

}
