#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
extern int getchar_unlocked(void);
extern int putchar_unlocked(int c);
extern size_t strlen(const char *s);
int inp();
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
  int T=inp(),i=1,output[101];
  for(i=1;i<=T;i++)
    {
      int N=inp(),M=inp(),j=1,SoInt[101][2],SoFloat[101][2],SoChef=0,z=0;
      //soInts--N
      for(j=1;j<=100;j++)SoInt[j][0]=SoFloat[j][0]=0;
      for(j=1;j<=N;j++)
         {int C=inp(),L=inp();
          if(SoInt[L][0])SoInt[L][1]+=C;
          else {SoInt[L][0]=1;SoInt[L][1]=C;}  
         }
      //SoFloats --M
      for(j=1;j<=M;j++)
         {int C=inp(),L=inp();
          if(SoFloat[L][0])SoFloat[L][1]+=C;
          else {SoFloat[L][0]=1;SoFloat[L][1]=C;}
         /* if(SoFloat[j][1]>SoInt[j][1]){SoChef+=(SoFloat[j][1]-SoInt[j][1]);SoFloat[j][1]=SoFloat[j][1]-SoInt[j][1];SoInt[j][1]=0;printf("Sochef=%d\n",SoChef);}
          else if(SoFloat[j][1]==SoInt[j][1]){SoFloat[j][1]=SoInt[j][1]=0;}
               else {SoInt[j][1]=SoInt[j][1]-SoFloat[j][1];SoFloat[j][1]=0;}*/
         }
      //calculating power to be given by SoChef  
      for(j=1;j<=100;j++)
          if(SoFloat[j][0])
                //printf("(I,%d,%d)-(F,%d,%d)\n", SoInt[j][1],j,SoFloat[j][1],j);
                //if(z=(SoFloat[j][1]-SoInt[j][1])){SoChef+=z;printf("Sochef=%d\n",SoChef);}}
                SoChef+=((SoFloat[j][1]-SoInt[j][1])>0?(SoFloat[j][1]-SoInt[j][1]):0);
     output[i]=SoChef; 
     }
  for(i=1;i<=T;i++)
   printf("%d\n",output[i]); 
  exit(0);
}
