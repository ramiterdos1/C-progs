#include <stdio.h>
#define concatenate(x,y) #x" "#y
int main()
{
  char *a="s",*e="e";
 printf(concatenate(a,e));
 }
