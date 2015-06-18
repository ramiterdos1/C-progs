#include<stdio.h>
#include<stdlib.h>
int a[1000000],b[1000000];

int main()
{
int T;
scanf("%d",&T);
while(T--)
{
int n,i=0;
scanf("%d",&n);
for(;i<n;i++)
  scanf("%d",(a+i));
for(i=0;i<n;i++)
 {
   scanf("%d",(b+i));
   a[i]=(b[i]-a[i])>=0?b[i]-a[i]:4+b[i]-a[i];
   printf("%d ",a[i]);
 }
 printf("\n");
 int count=0,tmp=a[0];
 for(i=1;i<n;i++)
  {
    if(a[i]>tmp)count+=a[i]-tmp;
    tmp=a[i];
  } 
 printf("%d\n",count);
}

return 0;
}
