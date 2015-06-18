#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdio>
#define ModNum 1000000007
#define sum(a,b) 
using namespace std;
typedef struct {
 int pos; int val;
}arr;
int search(arr *,int , int);
int summ(int ,int);
int search(arr *A,int L,int H){
int i=0;
for(i=L;i>=0;i--)
  if(A[i].val<H)break;
return i;
}
extern ssize_t getline(char**,size_t,FILE);
arr a[1000];
//int a[1000];
char input[15000];
extern int getchar_unlocked(void);
extern int putchar_unlocked(int c);
int inpint();
long long inplong();
inline int inpint()
{
int noRead=0;
char p=getchar_unlocked();
for(;p<33;){p=getchar_unlocked();};
while(p>32)
{
noRead = (noRead << 3) + (noRead << 1) + (p - '0');
p=getchar_unlocked();
}
return noRead;
}
inline long long inplong()
{
long long noRead=0;
char p=getchar_unlocked();
for(;p<33;){p=getchar_unlocked();};
while(p>32)
{
noRead = (noRead << 3) + (noRead << 1) + (p - '0');
p=getchar_unlocked();
}
return noRead;
}
inline int summ(int a, int b)
{
 int sum, carry;
 sum=a^b;carry=a&b;
 while(carry!=0)
  { 
    carry<<=1;
    a=sum;b=carry;
    sum=a^b;carry=a&b;
  } 
 return sum; 
}

int comparison(const void *a,const void *b)
{
  if((((arr *)a)->val)>(((arr *)b)->val))
    return 1;
  else if((((arr *)a)->val)<(((arr *)b)->val))
           return -1;
       else if((((arr *)a)->pos)<(((arr *)b)->pos))
             return -1;
            else return 1; 
 return 0;
}
int main()
{
 int T,i,j,k;
  size_t max=11001;
  char *input= (char *) malloc(max);
 char* tok_1;
 // int* tok_1;x
 for(T=inpint();T>0;T--)
     { int N=inpint(),L=inpint(),H=inpint(),count=0;

       getline(&input,&max,stdin);
    
       tok_1 = strtok(input," ");

       for(i=0;tok_1;i++)
       {
         a[i].val = atoi(tok_1);
         a[i].pos = i; 
         tok_1 = strtok(NULL," ");
       }
   // for(i=0;i<N;i++) {a[i].val=inpint();a[i].pos = i;}
    qsort(a,N,sizeof(arr),comparison);
   int pos=search(a,N-1,H);
    
   for(i=0;i<=pos-2;i++){
     for(j=i+1;j<=pos-1;j++){
       for(k=j+1;k<=pos;k++){
         int sum=summ(summ(a[k].val,a[i].val),a[j].val);    
        //int sum=a[k].val+a[i].val+a[j].val; 
       //x printf("~Sum: %d\n",sum);
        if(sum>=L && sum <=H && a)
           { count++;printf("i,j,k-->%d,%d,%d\n",i,j,k);}    
         }
       } 
    }printf("%d\n",count);
    
}return 0;
}
