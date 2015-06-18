#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
int GS[1000001];
void gener8GolombSeq()
{
  GS[1]=1;GS[2]=2;int counter=2,i=2;
  while(counter<=1000000)
   {
     int freq=GS[i];
     while(freq--)GS[counter++]=i;
     i++;
    }

}
int main()
{
  clock_t begin=clock(),end;time_t b=time(&b),e;
  gener8GolombSeq();
  long sum=0,i=1;
  for(;i<=1000000;i++)
     { 
       printf("G(%7ld)=%5d\n",i,GS[i]);sum+=GS[i];
      }
   printf("Sum=%ld\n",sum);
  end=clock();e=time(&e); 
  printf(" Processor Time taken is %f.\n",(double)((end-begin)/(double)CLOCKS_PER_SEC));
  printf(" Time taken is %f.\n",difftime(e,b));
  exit(1);
  
}
