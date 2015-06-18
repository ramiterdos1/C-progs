#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
int comparisons,exchanges;
FILE *f2,*f1;

void bubble_sort(int *);
void selection_sort(int *);
void insertion_sort(int *);
void getTheJobDone(void (*)(),int *);
void mergesort(int A[],int i);
int partition(int A[],int l,int r,int pivot);//divison algorithm of Quicksort
void quicksort(int A[],int l,int r);//performs Quicksort 
void exchange(int *a,int *b);
int compare(int d1,int d2);
//trying bubble sort
void bubble_sort(int *a)
{
 int i=1,j;
for(i=1;i<=a[0];i++)
{
    for(j=a[0];j>i;j--)
      if(a[i]>a[j])
         { 
           comparisons++;exchanges++; 
 	   a[i]=a[i]^a[j];
 	   a[j]=a[i]^a[j];
 	   a[i]=a[i]^a[j];
         }
       else comparisons++;  
}
}
//mergesort algorithm
void Mergesort(int A[])
{
  mergesort(A,1);
}
void mergesort(int *A,int i)
{
   if(i>=A[0]){;}
    else
          {  int B[A[0]];
             int j=1,c=0;
             for(;j<A[0];j+=i*2) 
                 {   int k=0,cnt=0;
		      //if((j+i+cnt)>=No_of_items)
		        while(cnt<i && k<i && (j+i+cnt)<A[0])
                         {if(A[j+k]>A[j+i+cnt])
			    { B[c++]=A[j+i+cnt];cnt++;comparisons++;}
                          else{ B[c++]=A[j+k];k++;}
                               //exchange((A+j+k),(A+j+i+cnt));cnt++;break;}
                         }
			 while(k<i && (j+k)<A[0]){B[c++]=A[j+k];k++;}
			for(;cnt<i &&(j+i+cnt)<A[0];cnt++)B[c++]=A[j+i+cnt];
                   }
             
             A=B;
             mergesort(A,2*i);
           }
}
//QuickSort Algorithm....
void exchange(int *a,int *b)
{
  int tmp= *a;
  *a=*b;
  *b=tmp;
}
int compare(int d1,int d2)
{  int i=0;
   if(d1==d2)i=0;
    else if(d1>d2)i=1;else i=-1;
  return i;
}
void Quicksort(int A[])
{
  quicksort(A,1,A[0]);
}
void quicksort(int A[],int l,int r)
{ if(l<r){
  int pivot_pos=rand()%10;
  while(pivot_pos==0)pivot_pos=rand()%10;
  pivot_pos=l+1+(r-l)/pivot_pos;
  pivot_pos=partition(A,l,r,pivot_pos);
  
    quicksort(A,l,pivot_pos-1);
    quicksort(A,pivot_pos+1,r);
  
  }
}
int partition(int A[],int l,int r,int pivot)
{
   
   int storeindex=l,i=l;int pivotval=A[pivot];
   exchange((A+pivot),(A+r));exchanges++;
    for(;i<r;i++)//exchanges all values smaller than pivotval to the left
        if(compare(pivotval,A[i])>0)
          {exchange((A+storeindex),(A+i));storeindex+=1;comparisons++;exchanges++;}
   if(storeindex!=r)
   {exchange((A+storeindex),(A+r));exchanges++;}
   return storeindex;
    
}
//heap sort algorithm.....


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
           comparisons++;exchanges++; 
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
             a[j+1]=a[j--]; comparisons++;exchanges++;
         }
        a[j+1]=tmp;exchanges++;
       }
}
void getTheJobDone(void (*func)(),int *a)
{
    func(a);
    fprintf(f1,"%d,",comparisons);
    comparisons=0;
    fprintf(f2,"%d,",exchanges);
    exchanges=0;
}

int main()
{
  clock_t begin=clock(),end;time_t bgn=time(&bgn),e;
  f1=fopen("SortingGraph.csv","w");
  f2=fopen("SortingExchng.csv","w");
  fprintf(f1,"No. Of Items,\t n^2,Bubble Sort,Insertion Sort,Selection Sort,MergeSort,QuickSort,HeapSort\n");
  fprintf(f2,"No. Of Items,\t n^2,Bubble Sort,Insertion Sort,Selection Sort,MergeSort,QuickSort,HeapSort\n");
  exchanges=0;
  comparisons=0;
  int i,j,*a,*b,*c,*x,*y,*z;
  void (*func)();
  for(i=1;i<=200;i++)
  {
    a=(int *)malloc((i*10+1)*sizeof(int));
    b=(int *)malloc((i*10+1)*sizeof(int));
    c=(int *)malloc((i*10+1)*sizeof(int));
    x=(int *)malloc((i*10+1)*sizeof(int));
    y=(int *)malloc((i*10+1)*sizeof(int));
    z=(int *)malloc((i*10+1)*sizeof(int));
    a[0]=b[0]=c[0]=i*10;
    x[0]=y[0]=z[0]=i*10;
   for(j=1;j<=a[0];j++)
    { 
     a[j]=rand()%1000;
    // srand(i*2);
     b[j]=rand()%1000;
     //srand(i+1);
     c[j]=rand()%1000;
     x[j]=rand()%100;
     y[j]=rand()%1000;
     z[j]=rand()%1000;
     }
    /* if(i==10)for(j=1;j<=a[0];j++)printf("%5d,%5d,%5d\n",a[j],b[j],c[j]);
     if(i==11)for(j=1;j<=a[0];j++)printf("--\n",a[j],b[j],c[j]);
     if(i==12)for(j=1;j<=a[0];j++)printf("%5d,%5d,%5d\n",a[j],b[j],c[j]);
   */
    fprintf(f1,"%d,%d,",i*10,i*i*100);
    fprintf(f2,"%d,%d,",i*10,i*i*100);
    func=bubble_sort;
    getTheJobDone(func,a);
    func=insertion_sort;
    getTheJobDone(func,b);
    func=selection_sort;
    getTheJobDone(func,c);
    func=Mergesort;
    getTheJobDone(func,x);
    func=Quicksort;
    getTheJobDone(func,y);
    //func=heapsort;
    //getTheJobDone(func,z);
    fprintf(f2,"\n");
    fprintf(f1,"\n");
   }//end of outer for loop
  fclose(f1);
  fclose(f2);
  end=clock();
  e=time(&e);
  printf(" Processor Time taken is %f.\n",(double)((end-begin)/(double)CLOCKS_PER_SEC));
  printf(" Time taken is %f.\n",difftime(e,bgn)); 
}
