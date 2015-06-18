//
//  MinDist.c
//  
//
//  Created by Ramit on 20/01/13.
//
//

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#define ModNum 1000000007
//extern int getchar(void);
//extern int putchar_unlocked(int c);
int inpint();
long long inplong();
inline int inpint()
{
    int noRead=0;
    char p=getchar();
    for(;p<33;){p=getchar();};
    while(p>32)
    {
        noRead = (noRead << 3) + (noRead << 1) + (p - '0');
        p=getchar();
    }
    return noRead;
}
inline long long inplong()
{
    long long noRead=0;
    char p=getchar();
    for(;p<33;){p=getchar();};
    while(p>32)
    {
        noRead = (noRead << 3) + (noRead << 1) + (p - '0');
        p=getchar();
    }
    return noRead;
}
int main()
{
    int T=inpint();
    while(T--)
    {
        int Ds,Dt,D;
        Ds=inpint();
        Dt=inpint();
        D=inpint();
        int ans;
        ans=(D-Ds-Dt);
        if(ans<0)
        {
            ans=0;
        }
        printf("%d\n",ans);
    }
}