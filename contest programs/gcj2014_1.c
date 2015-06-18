#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define  inp(T) scanf("%d",&T)
int main()
{
int T,cnt=1;
inp(T);
while(T--)
{
int ans1,ans2,c=1,grid1[4][4],grid2[4][4],matches[5];
inp(ans1);
matches[0]=0;
for(int i=0;i<4;i++)for(int j=0;j<4;j++)
  inp((grid1[i][j]));
inp(ans2);ans1--,ans2--;
for(int i=0;i<4;i++)for(int j=0;j<4;j++)
  inp((grid2[i][j]));
for(int i=0;i<4;i++)for(int j=0;j<4;j++)
if(grid1[ans1][i]==grid2[ans2][j])
   {
     matches[0]++;matches[c++]=grid1[ans1][i];
   }
switch(matches[0])
{
case 0:printf("Case #%d: Volunteer cheated!\n",cnt++);
       break;
case 1:printf("Case #%d: %d\n",cnt++,matches[1]);break;
default:printf("Case #%d: Bad magician!\n",cnt++);
};
}
return 0;
}
