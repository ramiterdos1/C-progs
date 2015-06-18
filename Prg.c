#include <stdio.h>
#include <stdlib.h>
typedef struct node{ int n;int *a;}N;
//typedef struct node N;
void init(N *n1)
{
  n1->n=0;
  //n1->a=(int *)calloc(sizeof(int),sizeof(int));
}//end of initialization

N *input(int cnt)
{ //declaration and then initialization
  N *n1=(N *)malloc(sizeof(N)); init(n1);
  n1->n=cnt;
  int c=1,ch=0,*a=(int *)malloc(sizeof(int));a[0]=0;
  printf("\nDo u want to enter the elements of the array?press '0' for NO\n");
  scanf("%d",&ch);getchar();
  while(ch!=0)
   {  c++;a=(int *)realloc((void *)a,c*sizeof(int));
      a[0]=c; 
      printf("Enter the number:");
      scanf("%d",&a[c-1]);getchar();
   // storing logic: a[0] contains the no of elements in the array where no of inputs is a[0]-1; a[1] is d 1st inp;
       printf("\nDo u want to enter the elements of the array?press '0' 4 'NO'\n");
       scanf("%d",&ch);getchar();
    }n1->a=a;
   return n1;
}//end of taking inputs
  
void display(N *n1)
{
  printf("\n\nDisplaying contents of node %d. \n",n1->n);int *a=n1->a;
  printf("It contains an array of %d elements.\n",a[0]==0?a[0]:a[0]-1);
  int i=1;
  printf("Array:{");
  for(;i<a[0];i++)printf("%d%c",a[i],i<a[0]-1?',':' ');
  printf("}\n\n");
}//end of display()
main()
{
  int ch=0,c=0,i=0;N *n_arry=(N *)malloc(sizeof(N));
  while(ch!=1)
   {
     printf("\n\n Do you want to enter an array? enter '1' for NO : ");
     scanf("%d",&ch);getchar();
     if(ch!=1)
       { c++; n_arry=(N *)realloc((void *)n_arry,c*(sizeof(N)));
         n_arry[c-1]=*input(c);
       }
     else printf("Thank U 4 using this storing program! :)\n"); 
    }
   for(;i<c;i++)
      display(&n_arry[i]);
}


