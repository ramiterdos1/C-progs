#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
extern int getchar_unlocked(void);
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
}
