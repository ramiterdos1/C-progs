#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
long mapping(int n)
{
  long mappedVal=0;
  while(n)
   { int digit=n%10,digit4=1,i=1;
     for(;i<5;i++)digit4*=digit;
        mappedVal+=digit4;
        n/=10;
    }
   return mappedVal;
}
short check(int num)
{ 
  short flag=1,i=0; 
  long n[6];
  for(;i<6;i++)
      {
         n[i]=0;
         n[i]=mapping(num*(i+1));
        if(n[i]!=n[0])
          { flag=0;return flag;}
       }
   return flag;
}
int main()
{
  clock_t begin=clock(),end;time_t b=time(&b),e;
  long num=16,startingnum=10;   
   while(1)
   {  
     //num*=10+6;startingnum*=10;
     long val=startingnum++;
     //while((val+=10)<5*startingnum)
          if(check(val))
            { end=clock();e=time(&e);
              printf("%ld\n",val);
              printf(" Processor Time taken is %f.\n",(double)((end-begin)/(double)CLOCKS_PER_SEC));
              printf(" Time taken is %f.\n",difftime(e,b));
              exit(0);
            } 
     }
} 
