#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define MaxTests 20
#define N 10000009
inline int inp()
{
int noRead=0;
char p=getchar_unlocked();
for(;p<33;){p=getchar_unlocked();};
while(p>32)
{
noRead = (noRead << 3) + (noRead << 1) + (p - '0');
p=getchar_unlocked();
}
return noRead;
};
 
int main()
{
   int T,i,length;char c[1000005];
    long ans,output[MaxTests+1];
   //scanf("%d",&T);//no of test cases
   T=inp();
   for(i=1;i<=T;i++)
     { int j,k;fflush_unlocked(stdin);
       j=k=length=0;ans=1;
       while((c[length++]=getchar_unlocked())!='\n');
       k=length-2;
       for(j=0;j<=k;j++,k--)
           {ans*=((c[k]==c[j]&c[j]=='?')*26+(c[k]==c[j]&c[k]!='?')+(c[k]!=c[j]&(c[k]=='?'|c[j]=='?')))%N;
            if(!ans)k=0;
           }
      // printf("%d..%s....fin...\n",i,c);
       output[i]=ans;    
     }
   for(i=1;i<=T;i++)
     printf("%ld\n",output[i]);
}
