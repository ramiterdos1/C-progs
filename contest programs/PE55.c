#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
extern void *memset(void *s, int c, size_t n);
long stack[50];
inline long reverseNum(long j)
{
  long rev=j%10,copy=j,digit=0;
     while((copy/=10))
       {
         rev=(rev<<3)+(rev<<1);// this without brackets will cause havoc!
         digit=copy%10;
         rev+=digit;
       }
   return rev;
}

int main()
{
   clock_t begin=clock(),end;time_t b=time(&b),e;
   long is_Lycheral[10001];// long-->char.. there was a bus error
   memset(stack,0,50); 
   memset(is_Lycheral,1,10001);
   int count=0;long i=0;
   
   while((i++)<10000)
    {int itr=50,flag=1;long long int j=i;
     if(is_Lycheral[i])
      {printf("Hel\n");
        while((itr--)&&flag)
        {printf("%d\n",itr);
         if((j<10000))
          {int indx=j;is_Lycheral[indx]=0;}
          stack[itr]=reverseNum(j)+j;
         j=stack[itr];
         flag=((reverseNum(j)-j)==0)?0:1;//palindrome check
         if(i>150 &&i<200 || i==7)
           {printf("Hello..%ld...%lld..%d..%d\n",i,j,flag,itr);}
        }
       }
      /*if(i<50)
       {printf("%d\n",i);
        int k;
         for(k=0;k<50;k++);
            // printf("%d ",stack[i]);printf("\n");
         }*/

     if(stack[0])
     {count++; int k;
     for(k=0;k<50;k++)if((stack[k]<10000))is_Lycheral[stack[k]]=1;
     is_Lycheral[i]=2;
     } 
     memset(stack,0,51); 
     }
     printf("There r %d no. of Lycheral numbers!\n They are...\n",count);
     for(i=0;i<10000;i++)if(is_Lycheral[i]==2)printf("%5d.%5ld\n",count--,i);
   end=clock();e=time(&e);
   printf(" Processor Time taken is %f.\n",(double)((end-begin)/(double)CLOCKS_PER_SEC));
   printf(" Time taken is %f.\n",difftime(e,b));
   return 0;
} 
