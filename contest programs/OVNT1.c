//
//  OVNT1.c
//  
//
//  Created by Ramit on 29/01/13.
//
//
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#define ModNum 1000000007
//extern int getchar_unlocked(void);
//extern int putchar_unlocked(int c);
int inpint();
long long inplong();
int count=36500+25+1;
int chk=0;
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
int f(long long n)
{
    while(n>1 && chk<count)
    {
    if(n&1)n=3*(n+1);
    else n>>=1;
    //printf("%lld->",n);
    
    if(n==1)return 1;
    
    }
    
        return 0;
}
int main()
{
    int T=0;
    scanf("%d",&T);
    
    while(T--)
    {
        /*int Can=0;
        scanf("%d",&Can);
        int Hum=2*Can;*/
        long long N=0;
        N=inplong();
        chk=0;
        int flag=f(N);
        printf("%s\n",((flag&1)?"No":"Yes"));
    }
    return 0;
    
}