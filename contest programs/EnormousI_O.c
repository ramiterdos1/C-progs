#include<stdio.h>

 
inline long inp()
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
};
int main()
{
 long n=inp();
 long i,tmp,count=0,k=inp();
 for(i=1;i<=n;i++)count+=((tmp=inp())%k==0);
 printf("%ld\n",count); 
}
