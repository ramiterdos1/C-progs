#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100
void bucketSort(int array[], int n) {
  int i, j;
  int count[n];
  for(i=0; i < n; i++) {
    count[i] = 0;
  }
 
  for(i=0; i < n; i++) {
    (count[array[i]])++;
  }
 
  for(i=0,j=0; i < n; i++) {
    for(; count[i]>0; (count[i])--) {
      array[j++] = i;
    }
  }
 
}
void countingSort(int A[], int n, int k)
{
        int i,j,C[k+1],B[n];
        
                for (i=0; i <= k; i++)
                C[i] = 0;
 
        for (j=0; j< n; j++)
                C[A[ j]] = C[A[ j]] + 1;
       
 
        for (i = 1; i <= k; i++)
                C[i] = C[i] + C[i-1];
       
 
        for (j = n-1 ; j>=0; j--)
        {
                B[C[A[ j]] - 1 ] = A[ j];
                C[A[ j]] = C[A[ j]] - 1;
        }
        
}
void selection_sort(int *a,int *b)
{
int i,j,Min;
for (j = 1; j <=a[0]; j++) {
    Min = j;
    for ( i = j+1; i<=a[0]; i++) {
        if (a[i]< a[Min]) 
            Min = i;
       }
    if ( Min != j ) 
       {
          // comparisons++;exchanges++; 
        a[j]=a[j]^a[Min];
        a[Min]=a[j]^a[Min];
        a[j]=a[j]^a[Min];
        b[j]=b[j]^b[Min];
        b[Min]=b[j]^b[Min];
        b[j]=b[j]^b[Min];
      }
       
  }
}

void radixsort(int *a, int n-digit)
{ 
  int j=1,m=1;
  for(;j<=n-digit;j++)
   {    
    int i=1,*b,m*=10;                                     
    for(;i<=a[0];i++)
    {
      b[i]=a[i]%m;
    }b[0]=a[0];
   selection_sort(b,a);
}
   
   
 


 
 
int main()
 {
  int array[100];
  int n,k,choice;
  int i;
          
    printf("Enter How many Numbers : ");
    scanf("%d",&n);
    printf("Enter the elements to be sorted:\n");
    for(i = 0; i < n; i++ ){
   scanf("%d",&array[i]);
  }
  printf("\nThe array of elements before sorting : \n");
  for (i = 0;i < n;i++) {
    printf("%d ", array[i]);
  }
 printf("\nThe array of elements after sorting : \n");
    bucketSort(array, n);
 
  for (i = 0;i < n;i++) 
  {
    printf("%d ", array[i]);
   
  }
   
  printf("\n");
  /*break;
   case 3:*/
    printf("\nThe array of elements after sorting : \n");
   countingSort( array, n, k);
  for (i = 0;i < n;i++) {
    printf("%d ", array[i]);
   
  }
   
  printf("\n");
 /* break;
  case 4:
    printf("\nThe array of elements after sorting : \n");
 
      radixsort(array,n);
  for (i = 0;i < n;i++)
   {
    printf("%d ", array[i]);
   
  }
   
  printf("\n");
  break;
  default:
          printf("wrng");
          exit(1);
}
}*/
getchar();
return 0;
}
