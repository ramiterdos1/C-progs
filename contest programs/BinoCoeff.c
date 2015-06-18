#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000

unsigned long binomial_coefficient(int n,int m)
{
 int i,j;
 unsigned long bc[MAXN][MAXN];
/* largest n or m */
/* computer n choose m */
/* counters */
/* table of binomial coefficients */
for(i=0;i<=n;i++)
  for (j=0; j<=n; j++) bc[i][j] = 0;
for (i=0; i<=n; i++) bc[i][0] = 1;
for (j=0; j<=n; j++) bc[j][j] = 1;

for (i=1; i<=n; i++)
{for (j=1; j<i; j++)
    { bc[i][j] = bc[i-1][j-1] + bc[i-1][j];
      if(j<(i/2+1))printf("%ld \n",bc[i][j]);
     }
  printf("\n");
}
/*for(i=0;i<=n;i++)
  { for (j=0; j<=i; j++)printf("%10ld ",bc[i][j]);
    printf("\n");
   }*/
 return( bc[n][m] );
}
int main()
{
 binomial_coefficient(100,12);
}
