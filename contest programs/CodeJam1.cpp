#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
#define f+(a,b) {for(int i=a;i<b;i++)}
#define f_(a,b) {for(int i=a;i>b;i--)}

extern int getchar_unlocked(void);
extern int putchar_unlocked(int c);
extern size_t strlen(const char *s);
int inp();
char a[16];
string output[4]={"X won","O won","Draw","Game has not completed yet"};
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
    int T;
    scanf("%d",&T);
    while(T--)
        {
            f+(0,4);
               {
                   scanf("",);
               }
        
        
        }
  
}
