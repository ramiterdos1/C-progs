#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main()
{
int T;scanf("%d",&T);
for(int i=1;i<=T;i++)
{
   long double C,F,X,tm=0,prd=2;
   scanf("%Lf",&C);
   scanf("%Lf",&F);
   scanf("%Lf",&X);
   while(1)
   {
     if(F*X<C*(prd+F))
        {
         tm+=(X/prd);break;
        }
     else {
        tm+=(C/prd);
        prd+=F;
     }
   }
   printf("Case #%d: %.7Lf\n",i,tm);
}
return 0;
}
