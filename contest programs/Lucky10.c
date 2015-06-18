#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
extern int getchar_unlocked(void);
extern int putchar_unlocked(int c);
extern size_t strlen(const char *s);
long inp2();
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
inline long inp2()
{
long noRead=0;
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
  int T=inp(),i=1;
  char A[20000],B[20000],output[200000];
  for(;i<=T;i++)
   {
     //scanf("%s",A);scanf("%s",B);
     int Table[10],j;
     for(j=0;j<10;j++)
        Table[j]=Table[j]^Table[j];
     j=2;char c;int length;
     while((j--))while((c=getchar_unlocked()!='\n'){Table[c-'0']++;length++;}
     int no_sevens=0,no_fours=0,tmp1=0,tmp2=0,tmp3=0,tmp4=0;
     if(Table[7]<Table[4])    
       {
         tmp1=Table[9]+Table[8];
         tmp2=Table[6]+Table[5];
         tmp3=Table[3]+Table[2]+Table[1]+Table[0];
         tmp4=tmp1-tmp2;
         //if(tmp4<0){no_sevens=(Table[7]-tmp4);no_fours=Table[4]
       }
    }
   
  
}
