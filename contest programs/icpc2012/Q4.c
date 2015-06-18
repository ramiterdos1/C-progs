#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#define ModNum 1000000007
extern int getchar_unlocked(void);
extern int putchar_unlocked(int c);
int inpint();
long long inplong();
inline int inpint()
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
}
inline long long inplong()
{
long long noRead=0;
char p=getchar_unlocked();
for(;p<33;){p=getchar_unlocked();};
while(p>32)
{
noRead = (noRead << 3) + (noRead << 1) + (p - '0');
p=getchar_unlocked();
}
return noRead;
}

