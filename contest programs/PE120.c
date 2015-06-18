#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
int main()
{
  int i=2,a[1001];long sum=0;
  while(i++<=1000)
   {int r_max=2,j=0,tmp=0;
     while(j++<i)
        { tmp=(2*i*j)%(i*i);
           if(tmp>r_max)
             r_max=tmp;
        }
    printf("%d--->%d\n",i,r_max);
    a[i]=r_max;
    }
   for(i=3;i<=1000;i++)
      sum+=a[i];
  printf("\n\n %ld\n",sum);
}
