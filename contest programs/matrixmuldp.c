# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# define SIZE 20
# define MAX 200000

void display_para(unsigned long s[][SIZE], int i, int j)
{
 if (i == j)
  printf(" A%d ",i);
 else
 {
  printf(" ( ");
  display_para(s, i, s[i][j]);
  display_para(s, s[i][j] + 1, j);
  printf(" ) ");
 }
}


void display_mult(unsigned long m[][SIZE], int n)
{
int i,j;
for(i=1;i<=n;i++)
{	
for(j=1;j<=n;j++)
 printf(" %5d ",m[i][j]);
printf("\n\n");
}
printf("\nThe No. of multiplication required is : %d\n",m[1][n]);
}




void matrix_chain(int p[],int num)
{
unsigned long m[SIZE][SIZE] = {0};
unsigned long s[SIZE][SIZE] = {0};
unsigned int q = 0;
int i, j, k, l;
int n = num;

for(i = 1; i <= n; i++)
m[i][i] = 0;

for(l = 2; l <= n; l++)
for(i = 1; i <= (n - l + 1); i++)
{
j = i + l - 1;
m[i][j] = MAX;
for(k = i; k <= j - 1; k++)
{
q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
if(q < m[i][j])
{
m[i][j] = q;
s[i][j] = k;
}
}
}
display_para(s, i-1, j);
printf("\n\n");
printf("\nThe Minimum No. of Multiplication Required is:\n");
display_mult(m,n);
}


void main()
{
int i,num=0,p[SIZE]={0};

printf("\nWELCOME:\nEnter the number of matrix : ");
scanf("%d",&num);

printf("\nEnter %d no. of order sequence for %d matrix :",num+1,num);

for(i=0;i<=num;i++)
 scanf("%d",&p[i]);
printf("\n\n");

printf("\nMULTIPLICATION SEQUENCE IS : \n");
printf("\n\n\t");

matrix_chain(p,num);

}
