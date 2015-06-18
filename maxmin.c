#include <stdio.h>
#include <time.h>
int * a,*mx,*mn;
void max(int *);void min(int *);
void ntrElemnt(int *A, int a);
void brk(int *);
void brk(int *arr)
{  int len=0,c=1;
   if(arr[0]%2==0)len=arr[0]/2;
   else{ len=(arr[0]+1)/2; arr=(int *)realloc((void *)arr,(arr[0]+1)*sizeof(int));arr[arr[0]+1]=arr[arr[0]];}
   mx=(int *)realloc((void *)mx,sizeof(int));
   mn=(int *)realloc((void *)mn,sizeof(int));
   mx[0]=mn[0]=0;
   while(c<=arr[0])
   {
    if(arr[c]<=arr[c+1]){ntrElemnt(mx,arr[c+1]);ntrElemnt(mn,arr[c]);}
     else {ntrElemnt(mx,arr[c]);ntrElemnt(mn,arr[c+1]);}
    c+=2;mx[0]++;mn[0]++;
   } 
   max(mx);min(mn);
}
void max(int *m)
{
   if(m[0]==1)printf("Maximum entered element is %d.\n",m[1]);
   else{ 
         int len=0,c=1,*M;
        if(m[0]%2==0)len=m[0]/2;
        else{ len=(m[0]+1)/2;m=(int *)realloc((void *)m,(m[0]+1)*sizeof(int));m[m[0]+1]=m[m[0]];}
      
      M=(int *)realloc((void *)M,(len+1)*sizeof(int));
      M[0]=0;
   while(c<=m[0])
   {
    if(m[c]<=m[c+1])ntrElemnt(M,m[c+1]);
     else ntrElemnt(M,m[c]);
    c+=2;M[0]++;
   } 
   max(M);
   }
}
   
void min(int *m)
{
   if(m[0]==1)printf("Minimum entered element is %d.\n",m[1]);
   else{ 
         int len=0,c=1,*M;
        if(m[0]%2==0)len=m[0]/2;
        else{ len=(m[0]+1)/2;m=(int *)realloc((void *)m,(m[0]+1)*sizeof(int));m[m[0]+1]=m[m[0]];}
      
      M=(int *)realloc((void *)M,(len+1)*sizeof(int));
      M[0]=0;
   while(c<=m[0])
   {
    if(m[c]>=m[c+1])ntrElemnt(M,m[c+1]);
     else ntrElemnt(M,m[c]);
    c+=2;M[0]++;
   } 
   min(M);}
}          
      
void ntrElemnt(int *A, int a)
{
     A=(int *)realloc((void *)A,(A[0]+1)*sizeof(int));
     A[A[0]+1]=a;
}
main()
{
  
  a=(int *) malloc(sizeof(int));
  int inp=0,ch=0;a[0]=0;
  do{
      
      printf("Enter 0 to stop ..\t any other number to continue.\n");
      scanf("%d",&ch);
      if(ch!=0)
      {
          printf("Enter the number:\n");
          scanf("%d",&inp);ntrElemnt(a,inp);a[0]++;
      }else printf("Thank you!\n");
    }while(ch!=0);
    for(;ch<=a[0];ch++) printf("\n %d\n",a[ch]);
    brk((int *)(5,1,2,4,3,5));
}    
