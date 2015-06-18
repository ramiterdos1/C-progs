//this calculates the number of 4-digit numbers that have digit products divisible by 3

#include<stdio.h>
int main()
{
int l=0;
for(int i=1000;i<=9999;i++)
  {
    int d=i,p=1;
    for( int j=1;j<5;j++)
      { p*=(d%10);d/=10;}
    if(p%3==0)++l;
  }
printf("%d\n",l);
return 0;
}
