#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cmath>
#include <cstring>
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
  int T=inp();
  
}
