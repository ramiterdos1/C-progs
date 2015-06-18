#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int comparisons;
FILE *f;
void bubble_sort(int *);
void selection_sort(int *);
void insertion_sort(int *);
//trying bubble sort
void bubble_sort(int *a)
{
 int i=1,j;
for(i=1;i<=a[0];i++)
{
    for(j=a[0];j>i;j--)
      if(a[i]>a[j])
         { 
           comparisons++; 
 	   a[i]=a[i]^a[j];
 	   a[j]=a[i]^a[j];
 	   a[i]=a[i]^a[j];
         }
       else comparisons++;  
}
}

//selection sort algorithm
void selection_sort(int *a)
{
int i,j,Min;
for (j = 1; j <=a[0]; j++) {
    Min = j;
    for ( i = j+1; i <=a[0]; i++) {
        if (a[i] < a[Min]) {
           comparisons++; 
            Min = i;
        }
       else comparisons++;  
    }
    if ( Min != j ) {
           comparisons++; 
        a[j]=a[j]^a[Min];
        a[Min]=a[j]^a[Min];
        a[j]=a[j]^a[Min];
    }
       else comparisons++;  
  }
}

//trying insertion sort
void insertion_sort(int *a)
{
  int i,j,tmp;
  for(i=2;i<=a[0];i++)
     {
       tmp=a[i];j=i-1;
       while (j>0 && tmp<a[j])
         {
             a[j+1]=a[j--];comparisons++; 
         }
        a[j+1]=tmp;
       }
}

int main()
{
  comparisons=0;
  int *a=(int *)malloc(51*sizeof(int)),j;
  a[0]=50;
  for(j=1;j<=a[0];j++)
    {
     a[j]=rand()%100;
     printf("%2d\n",a[j]); 
    }
  pid_t p;
  p=fork();
  if(p<0)printf("Error creating 1st subtree!\n");
  else if(p==0){
    //f=fopen("a1","w");
    comparisons=0;
    pid_t p1;
    p1=fork();
    if(p1<0)printf("Error creating 2nd subtree!\n");
    else if(p1==0)
      {
      comparisons=0;
      f=fopen("a2","w");
      for(j=1;j<=a[0];j++)
      {
       fprintf(f,"%d\n",a[j]); 
       }
      selection_sort(a);
      fprintf(f,"\n\n");
      for(j=1;j<=a[0];j++)
      {
       fprintf(f,"%d\n",a[j]); 
       }
      fclose(f);  
      //fwrite(a,sizeof(int),sizeof(a),f);
      printf("a2--hihihih--Level 2 Child says hi--%d\n",comparisons);
      } 
     else {
      comparisons=0;
      printf("a3--hihihih\n");
      f=fopen("a3","w");
      for(j=1;j<=a[0];j++)
      {
       fprintf(f,"%d\n",a[j]); 
       }
       fprintf(f,"\n\n");
      insertion_sort(a);
      for(j=1;j<=a[0];j++)
      {
       fprintf(f,"%d\n",a[j]); 
       }
      //fwrite(a,sizeof(int),sizeof(a),f);
      fclose(f);
      printf("a3--hihihih--Level 1 Child says hi--%d\n",comparisons);
      }
      }
    else{
      comparisons=0;
      f=fopen("a1","w");
      for(j=1;j<=a[0];j++)
      {
       fprintf(f,"%d\n",a[j]);
      } 
      selection_sort(a);
      fprintf(f,"\n\n");
      for(j=1;j<=a[0];j++)
      {
       fprintf(f,"%d\n",a[j]); 
       }
      
      //fwrite(a,sizeof(int),sizeof(a),f);
      fclose(f);
      printf("a1--hihihih--Parent says hi--%d\n",comparisons);
      }
}
