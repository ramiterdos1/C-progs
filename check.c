#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int check(long n)
{
   double s= (1.0+sqrt(24*n+1))/6.0;
   double z=sqrt(1+8*n);
   double s1= (z+1)/4.0;
   double s2=(z-1)/2.0;
   return  ((s==(int)s) && (s1==(int)s1) && (s2==(int)s2)); 
}
int main()
{
 //double i=9.0,j=9.1;
// printf("%d - %d\n", (i==(int)i),(j==(int)j));
 long i=40755;
 if(check(i))printf("%ld\n",i);
 while(i++)
  {
    if(check(i)){printf("%ld\n",i);exit(0);}
   
  } 
return 0;
}
