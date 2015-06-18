#include <stdio.h>
#include <stdlib.h>
int main()
{
int i=0,j=0;int ax[6]={0,1,1,3,5,4};
int a[1000000]={0};
while((j++)<50){a[j]=ax[j%6];
i+=a[j];
printf("%d\n",i);
}

j=50;
while((j++)<551)
    {a[j]=i+a[j-50];i+=a[j]-a[j-50];}
j=0;
while((j++)<551)
  printf("%d.%d=%d!\n",j,a[j],a[j]%7);
return 0;
}

