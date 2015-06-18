//magic numbers
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#define ModNum 1000000007
extern int getchar_unlocked(void);
extern int putchar_unlocked(int c);
inline long inp()
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
 long T=inp(),i=1;char input[1001];
 char output[1001][1003];
  while(i<=T)
   {
    int j=0,k=0,flag=0;char c=0;
    while((c=getchar_unlocked())!='\n')input[j++]=c;
    output[i][j+1]='\n'; flag=1;
    for(k=1;k<=j;k++)output[i][k]='4';
    if(input[0]>'7')output[i][0]='4';
    else {output[i][0]=0;
    for(k=1;k<=j&&flag;k++)
      { if(input[k-1]>'4' && input[k-1]<='7')
         {if(input[k-1]=='7')flag=1;
          else flag=0;
          output[i][k]='7';   
          }
       else if(input[k-1]>'7')
           { output[i][k]='4';flag=1;
             do{
             if(input[k-flag-1]=='4')output[i][k-flag]='7';
             if(input[k-flag-1]=='7')output[i][k-flag]='4';
             flag++;
             }while(k>=flag && input[k-flag-1]>'6');
            if(k==flag==1 && input[0]!='4')output[i][0]='4';
            flag=0;
           }
           else if(input[k-1]!='4')flag=0;
       }
          } 
   i++;
   }
    for(i=1;i<=T;i++)
        { 
           int j=0,k=0;
            while((k=output[i][j++])!='\n')
                  if(k)putchar_unlocked(k);
            putchar_unlocked(10);     
         }
}
