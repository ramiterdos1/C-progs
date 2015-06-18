#include <stdio.h>
#include <stdlib.h>
int main()
{
int i=0;
for(int j=1;j<5040;j++)
   { i=(i*i*i+i*i+i+1)%1008;printf("%d. %d\n",j,i);}
return 0;
}
