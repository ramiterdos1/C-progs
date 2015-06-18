#include<stdio.h>
#include<inttypes.h>
 
inline int64_t inp()
{
int64_t noRead=0;
char p=getchar_unlocked();
for(;p<33;){p=getchar_unlocked();};
while(p>32)
{
noRead = (noRead << 3) + (noRead << 1) + (p - '0');
p=getchar_unlocked();
}
return noRead;
};
 
int64_t a[10002];
int main()
{
int64_t i,t,n,f,b,count;
t=inp();
while(t--)
{
count=1;
n=inp();
f=inp();
for(i=1;i<n;++i)
{
b=inp();
if(b<=f)
{
count++;
f=b;
}
}
printf("%"PRId64"\n",count);
}
return 0;
}
