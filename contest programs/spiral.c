#include <stdlib.h>
#include <time.h>
#include <stdio.h>
int main()
{
  clock_t begin=clock(),end;time_t b=time(&b),e;
  int sum=0,elem=1,count=0,spiral=3;
while(spiral<1002)
 {
   count=spiral-1;
    int i=1;
   for(;i<=4;i++)
      {  sum+=elem;
         elem+=count;
      }
  spiral+=2;
  }  
  printf("%d\n",sum+elem);
   end=clock();e=time(&e);
   printf(" Processor Time taken is %f.\n",(double)((end-begin)/(double)CLOCKS_PER_SEC));
   printf(" Time taken is %f.\n",difftime(e,b));
      
}

