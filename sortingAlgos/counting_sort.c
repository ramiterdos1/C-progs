#include<stdio.h>
void main()
{
	int i,j,m,a[20],b[20],c[20],max;
	printf("enter no of elements");
	scanf("%d",&m);
	printf("enter elements");
	for(i=0;i<=m;i++)
		scanf("%d",&a[i]);
	max=a[i];
	for(i=0;i<=m;i++)
		if(max<a[i])
			max=a[i];
	for(i=0;i<=max;i++)
		c[i]=0;
	for(j=0;j<=m;j++)
		c[a[j]]=c[a[j]]+1;
	for(i=0;i<=max;i++)
		c[i]=c[i]+c[i-1];
	for(j=m;j>=1;j--)
	{
		b[c[a[j]]]=a[j];
		c[a[j]]=c[a[j]]-1;
	}	
	printf("AFTER SORTING");
	for(i=0;i<=m;i++)
		printf("%d",b[i]);
}
