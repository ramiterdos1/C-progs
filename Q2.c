#include <stdio.h>
#include <time.h>
#include <math.h>
int t(long);
int p(long);
int h(long);
int t(long n)
{
    int flag=-1,cnt=1;
    while((cnt++)<(long)sqrt(2*n))
        if((cnt*(cnt+1)/2)==n){flag=cnt;break;}
    return flag;
}
int p(long n)
{
    int flag=-1,cnt=1;
    while((cnt++)<(long)sqrt(n))
        if((cnt*(3*cnt-1)/2)==n){flag=cnt;break;}
    return flag;
}
int h(long n)
{
    int flag=-1,cnt=1;
    while((cnt++)<(long)sqrt(n))
        if((cnt*(2*cnt-1))==n){flag=cnt;break;}
    return flag;
}       
main()
{
      unsigned long i=10000000;
      printf("T%d=P%d=H%d=%d\n",t(i),p(i),h(i),i);
      
      while(i++<70000000)
       if(t(i)>0 && p(i)>0 && h(i)>0)break;
         printf("dun now i=%d\n",i);
      printf("T%d=P%d=H%d=%d",t(i),p(i),h(i),i);
}      
