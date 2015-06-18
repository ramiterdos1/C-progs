#include<stdio.h>
#include<stdlib.h>

#define maxsize 100

void get_row_col(int);
void display_dim(int);
void partition(int);
void display_mat(int[][maxsize],int);
void parenthise(int,int,int[][maxsize]);

int dim[maxsize][2];

int main()
{
	int n,i;

	printf("Enter the no. matrics\n");
	scanf("%d",&n);

	printf("Enter row length of the first matrix\n");
	scanf("%d",&dim[1][0]);

	get_row_col(n);
	display_dim(n);
	partition(n);	

	return 0;
}


void get_row_col(int n)
{
	int col,i;
	
	for(i=1;i<=n;i++)
	{
		col=rand()%10 + 1;
		dim[i][1]=col;
	
		if(i<n)
			dim[i+1][0]=col;

	}
}

void display_dim(int n)
{
	int i;

	for(i=1;i<=n;i++)
		printf("(%d,%d)",dim[i][0],dim[i][1]);

	printf("\n");
}

void partition(int n)
{
	int i,k,j,min;
	int m[maxsize][maxsize],s[maxsize][maxsize];
	
	for(i=1;i<=n;i++)
		m[i][i]=0;
	
	for(i=2;i<=n;i++)
	{
		for(k=i;k<=n;k++)
		{
			min=m[k-i+1][k-i+1] + m[k][k-i+2] + dim[k-i+1][0]*dim[k-i+2][0]*dim[k][1];
			s[k][k-i+1]=k-i+1;
			for(j=k-i+3;j<=k;j++)		
			{
				if(min > (m[j-1][k-j+1] + m[k][j] + dim[k-j+1][0]*dim[j][0]*dim[k][1]))
				{
					min = m[j-1][k-j+1] + m[k][j] + dim[k-j+1][0]*dim[j][0]*dim[k][1];
					s[k][k-i+1]=j-1;
				}
			}
			m[k][k-i+1]=min;
			//getchar();
			//display_mat(m,n);
			//printf("***\n");
			//display_mat(s,n);
			//getchar();
		}
	}
	printf("Minimum no of scaler multiplications are %d\n",m[n][1]);

	parenthise(1,n,s);
	printf("\n");

}
	
void display_mat(int m[][maxsize],int n)
{
	int i,j;
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%5d",m[i][j]);
		printf("\n");
	}
}

void parenthise(int start,int stop,int s[][maxsize])
{
	if(start==stop)
		printf(" A%d ",start);
	else
	{
		printf("(");
		parenthise(start,s[stop][start],s);
		parenthise(s[stop][start]+1,stop,s);
		printf(")");
	}
}
	

