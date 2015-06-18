/*
Trying to generate random numbers on 25-5-13
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/file.h>
#include <fcntl.h>
#include <stdlib.h>
void readNprint(char *n)
{int fd;
fd=open(n,O_RDONLY,0);
if(fd<0)
   printf("Error opening! %s\n",n);
else {
   char s[10];
   struct {unsigned int a : 8;} f[10];
   int n=read(fd,s,10); //int f[10];
   if(n<1)printf("NO READ...\n");
   else {
          printf("Read %d no. of characters!\n",n);
          for(n=0;n<10;n++){f[n].a=0;f[n].a=(unsigned int)s[n];}
          printf("READ  --- %s....\n",s);
          for(n=0;n<10;n++)printf("%dI",f[n].a);
          printf("\n");
   close(fd);
   }
}   
}
int main()
{
char *n1="/dev/random",*n2="/dev/NULL";
struct {unsigned int a : 2;} f;unsigned int b=0;f.a=0;
while(b++<7)printf("%d..%d\n",(f.a)++,b);
readNprint(n1);
readNprint(n2);
return 0;
}
