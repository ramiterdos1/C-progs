#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  double pi,h,G,M,c,ans;
pi=3.14159;
h= 1.054592;
c=3;
M=1.8835;
G=14.387655;
ans=192*pow(pi,3)*pow(h,7)*pow(10,7)*pow(G,-2)*pow(M,-5)*pow(c,-4);
printf("%.10lf\n",ans*pow(10,-7));
return 0;
}
