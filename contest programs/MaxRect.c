#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
extern int getchar_unlocked(void);
extern int putchar_unlocked(int c);
extern size_t strlen(const char *s);
int inp();
inline long long inp2();
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
inline long long inp2()
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
int main()
{
 int H=inp(),W=inp(),i=0,j=0;
 long long c[301][301]; 
 //taking inputs
 for(;i<H;i++)
    for(j=0;j<W;j++)
        scanf("%lld",&c[i][j]);
 //generating solution
 int sum_r[301][2],sum_c[301][2],sumd_r[301][2],sumd_c[301][2];
 for(i=0;i<H;i++)sum_r[i][0]=sum_r[i][1]=sumd_r[i][0]=sumd_r[i][1]=0;
 for(i=0;i<W;i++)
    sum_c[i][0]=sumd_c[i][0]=sumd_c[i][1]=sum_c[i][1]=0;
  for(i=0;i<H;i++)
    for(j=0;j<W;j++)      
        /*if(c[i][j][0]!='-')
          {sum_r[i][0]+=(strlen(c[i][j])-1); 
           sum_c[j][0]+=(strlen(c[i][j])-1); 
           sumd_r[i][0]+=(c[i][j][0]-'0');
           sumd_c[j][0]+=(c[i][j][0]-'0');
          
           
          }
        else{ sum_r[i][0]-=strlen(c[i][j]); 
              sum_c[j][0]-=strlen(c[i][j]); 
              sumd_r[i][0]-=(c[i][j][1]-'0');
              sumd_c[j][0]-=(c[i][j][1]-'0');
            }*/
       { sum_r[i][0]+=c[i][j];
         sum_c[j][0]+=c[i][j];}
     
  //sorting's to be donexxxxxxxxxx
  int R_size=0,C_size=0;
  for(i=0;i<H;i++)
    {
      printf("%d..%d\n",sum_r[i][0],sumd_r[i][0]);
     if(sum_r[i][0]>0){sum_r[i][1]=1;R_size++;}
     //else if(sum_r[i][0]>=0){if(sumd_r[i][0]>0){sumd_r[i][1]=1;R_size++;}} 
     }
   for(i=0;i<W;i++)
    { printf("%d..%d\n",sum_c[i][0],sumd_c[i][0]);
     if(sum_c[i][0]>0){sum_c[i][1]=1;C_size++;}
     //else if(sum_c[i][0]>=0){if(sumd_c[i][0]>0){sumd_c[i][1]=1;C_size++;}}
     }
  printf("%d %d\n",R_size,C_size);
   for(i=0;i<H;i++)if(sum_r[i][1]||sumd_r[i][1])printf("%d ",i);
   printf("\n");
   for(i=0;i<W;i++)if(sum_c[i][1]||sumd_c[i][1])printf("%d ",i);  
  printf("\n");
}
