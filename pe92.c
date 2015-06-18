#include <stdio.h>
#include <stdlib.h>

int sq[10]={0,1,4,9,16,25,36,49,64,81};

int main()
{
  long n=2,count=0;
  for(;n<10000000;n++)
   {
     long i=n;
     //printf("%d\n",i);
     while(i!=1 &&i!=89&& i!=145 && i!=42 && i!=20 && i!=4 &&i!=16 && i!=37 && i!=58)
      {
     //printf("%d\n",i);
         long sum=0;
         while(i)
         {
          sum+=sq[i%10];
          i/=10;

         }
         i=sum;
      }
     if(i!=1)count++;
   }
  printf("%ld\n",count);
}
