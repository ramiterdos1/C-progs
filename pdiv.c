#include <stdio.h>
#include "pe1.h"
//#include "division.c"
extern int *num,*q;extern int nod,r;
extern void calculation(int ,int );
extern void display(int ,int );
int  Dig(int *p,int lmt);
int isprime(int n);
int isprime(int n)
{
    int i=2,chk=1;
    for(;i<=n/2;i++)
        if(n%i==0){chk=0;i=n;}
    return chk;
}//checkin primality of n 
int  Dig(int *p,int lmt)
{
     int i=0;
     for(;i<lmt;i++)
         if(p[i]!=0) break;
      return i;
}             
main()
{
   
   num=(int *)(6,0,0,8,5,1,4,7,5,1,4,3);
   int cnt=1001,chk=0;
   while(chk<=5)
   {
        if(isprime(cnt))
           { 
             nod=12;
             q=(int *)malloc(nod*(sizeof(int)));
             calculation(0,cnt);
             if(r==0){chk=Dig(q,12);display(cnt,0);num=q;cnt+=2; }
             }
         else cnt+=2;
     }     
}
