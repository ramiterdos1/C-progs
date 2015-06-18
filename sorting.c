#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#define No_of_items 99900

#define data int //data signifies the type of data to be stored

int compare(data d1,data d2);//compares two instances of type data return *)1 if d1>d2 *)0 if d1=d2 *)-1 for last case
void initialize_array(data Array[]);//initalizes the elements of the array
void display_array(data Array[]);//displays the elements of the array
void Mergesort(data A[],int i);//perform mergesort on the elemnts of the array
void Display_data(data A);//displays data as requited to be displayed
void exchange(data *a,data *b);//interchanges a and b
void Bubblesort(data *A);//bubble sorts
int partition(data A[],int l,int r,int pivot);//divison algorithm of Quicksort
void QuickSort(data A[],int l,int r);//performs Quicksort 
time_t b,e1,e2;//difftime(e,b);
int compare(data d1,data d2)
{  int i=0;
   if(d1==d2)i=0;
    else if(d1>d2)i=1;else i=-1;
  return i;
}
void Display_data(data A)
{
  printf("%d\n",A);
}
void initialize_array(data Array[])
{
  int i=0;
  for(;i<No_of_items;i++)
       {//Array[i]= (int)rand_r(&i);
          if(i+1%2)srand(i%10);Array[i]=rand()/(No_of_items*100);
       }
}
main()
{
  data Array[No_of_items]; data A2[No_of_items];
  //b=time(&b);
  //clock_t begin=clock(),end1,end2,end3,end4;
  initialize_array(Array);initialize_array(A2);
  //display_array(Array);
  //e1=time(&e1);end1=clock();
  //printf(" Time taken to initialize %f.\n",difftime(e1,b));
  //printf(" Processor Time taken is %f.\n",(double)((end1-begin)/(double)CLOCKS_PER_SEC));
  Mergesort(Array,1); 
  //display_array(Array);
  //e2=time(&e2);end2=clock();
  //printf(" Time taken to sort %f.\n",difftime(e2,e1));
  //printf(" Processor Time taken 2 Msort is %f.\n",(double)((end2-end1)/(double)CLOCKS_PER_SEC));
  //Bubblesort( Array);
  //display_array(Array);
  //end3=clock(); 
  //printf(" Processor Time taken 2 Bsort is %f.\n",(double)((end3-end2)/(double)CLOCKS_PER_SEC));
  QuickSort(A2,0,No_of_items-1);
  display_array(A2);
  //end4=clock(); 
  //printf(" Processor Time taken 2 Qsort is %f.\n",(double)((end4-end3)/(double)CLOCKS_PER_SEC));
  exit(0);
}
void display_array(data Array[])
{
   int i=0;
   for(;i<30;i++)printf("-");printf("\n");
   for(i=0;i<No_of_items;i++)
       Display_data(Array[i]);
   for(i=0;i<30;i++)printf("-");printf("\n");
}
void exchange(int *a,int *b)
{
  data tmp= *a;
  *a=*b;
  *b=tmp;
}
void Mergesort(data *A,int i)
{
   if(i>=No_of_items){display_array(A); return ;}
    else
          {  data B[No_of_items];
             int j=0,c=0;
             for(;j<No_of_items;j+=i*2) 
                 {   int k=0,cnt=0;
		      //if((j+i+cnt)>=No_of_items)
		        while(cnt<i && k<i && (j+i+cnt)<No_of_items)
                         {if(compare(A[j+k],A[j+i+cnt])>0)
			    { B[c++]=A[j+i+cnt];cnt++;}
                          else{ B[c++]=A[j+k];k++;}
                               //exchange((A+j+k),(A+j+i+cnt));cnt++;break;}
                         }
			 while(k<i && (j+k)<No_of_items){B[c++]=A[j+k];k++;}
			for(;cnt<i &&(j+i+cnt) < No_of_items;cnt++)B[c++]=A[j+i+cnt];
                        
		 }
             
               A=B;
             return Mergesort(A,2*i);
           }
}
void Bubblesort(data *A)
{
   int i=0,j=0;
   for(;i<No_of_items-1;i++)
      for(j=i+1;j<No_of_items;j++)
         if(compare(A[i],A[j])>0)
            exchange(&A[i],&A[j]);
}
void QuickSort(data A[],int l,int r)
{ if(l<r){
  int pivot_pos=rand()%10;
  while(pivot_pos==0)pivot_pos=rand()%10;
  pivot_pos=l+1+(r-l)/pivot_pos;
  pivot_pos=partition(A,l,r,pivot_pos);
  
    QuickSort(A,l,pivot_pos-1);
    QuickSort(A,pivot_pos+1,r);
  
  }else return;
}
int partition(data A[],int l,int r,int pivot)
{
   
   int storeindex=l,i=l;data pivotval=A[pivot];
   exchange((A+pivot),(A+r));
    for(;i<r;i++)//exchanges all values smaller than pivotval to the left
        if(compare(pivotval,A[i])>0)
          {exchange((A+storeindex),(A+i));storeindex+=1;}
   if(storeindex!=r)
   exchange((A+storeindex),(A+r));
   return storeindex;
    
}

