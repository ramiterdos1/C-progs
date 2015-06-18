#include <stdio.h>
void swp(int*,int *);
int max=0,n=0;//global variables
void Max(int cyc,int n1);
void swp(int* a, int* b)
{    if(*a<*b)
     {int t=*b;
      *b=*a;
      *a=t;}
}
void Max(int c,int n1)
{
     if(c>max){ max=c;n=n1;}
}//end of Max()
int main()
{
    int i,j;
    printf("Enter the two integers:");
    scanf("%d %d",&i,&j);
    swp(&i,&j); printf("%d %d",i,j);
    while((i++)<=j) 
    {   int n=i-1,cyc=0;
        while(n!=1)
         { if(n%2==0){ n/=2;cyc++;}
            else if(n%2==1){n=3*n+1;cyc++;}
            };
       Max(cyc,i-1);
    }printf(" %d\n",max+1);
    printf("The longest cycle is of %d of length %d.",n,max+1); 
    return 0;
}//end of main()                           
