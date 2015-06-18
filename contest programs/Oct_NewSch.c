#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#define ModNum 1000000007
extern int getchar_unlocked(void);
extern int putchar_unlocked(int c);
long long inp();
inline long long inp()
{
long noRead=0;
char p=getchar_unlocked();
for(;p<33;){p=getchar_unlocked();};
while(p>32)
{
noRead = (noRead << 3) + (noRead << 1) + (p - '0');
p=getchar_unlocked();
}
return noRead;
}
int main()
{
 long long T=inp(),i=1,k=1,output[102];
 for(;i<=T;i++)
     {
        long long n=inp(),j=1,a=3,ans=1;
        output[i]=((n&1)?-3:3);
        for(;j<n;)
          {
             if(n&1)ans=(a*ans)%ModNum;
             a=(a*a)%ModNum;
             n=n>>1;
           }
         output[i]+=(a*ans)%ModNum;  
      }
  for(;k<i;k++)printf("%lld\n",output[k]);
  exit(0);
}
