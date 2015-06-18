#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
int main()
{
  fflush(stdin);
  long T,tmp=1,outpt[101];
  scanf("%d\n",&T);
  while(tmp<=T)
  {
   int N,countr=1,a,b;
   scanf("%d\n",&N);
   scanf("%d",&a);
   N-=1;
   while(N--){
              scanf("%d",&b);
              countr+= (a>b);a=(a>b)?b:a;}
   outpt[tmp++]=countr;
   } 
   for(tmp=1;tmp<=T;tmp++)printf("%ld\n",outpt[tmp]);
}
