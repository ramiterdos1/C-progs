#include <stdio.h>
#include <stdlib.h>
int main()
{
  char buf[10],buf2[10000];int n,i,j=0;
  while(n=read(0,buf,10))
    {
       i=0;
       while(i<n) buf2[j++]=buf[i++];
    }
   printf("\n");    
   for(i=0;i<30;i++)printf("-");
  
  printf("\n%s\n",buf2);
}
