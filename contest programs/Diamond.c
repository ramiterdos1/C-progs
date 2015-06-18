#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
extern int getchar_unlocked(void);
extern int putchar_unlocked(int c);
extern size_t strlen(const char *s);

int inp();
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
}
int main()
{
  int T=inp(),i=1;double output[501];
  for(i=1;i<=T;i++)
    {
     int N=inp(),j=1;
     int V[2002];
      for(;j<=N;j++)V[i]=inp(); 
     }
   
}
