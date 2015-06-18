#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
struct frac{
  long long num;long long denom;
   };
typedef struct frac * FP; //fraction-ponter
FP get_fraction()
{
   FP f=(FP)malloc(sizeof(struct frac));
   return f;
}
long long gcd(long long a,long long b)
{
  if(a<b)return gcd(b,a);
  else {
         if(b==0)return a; 
         else return gcd(b,a%b); 
       } 
}
void reduce_to_lowest_terms(FP f)
{
long long hcf=gcd(f->num,f->denom);
f->num/=hcf;
f->denom/=hcf;
}
FP add( FP f1, FP f2)
{
  FP f=get_fraction();
  int g=gcd(f1->denom,f2->denom);
  int l=((f1->denom)/g)*f2->denom;
  f->denom=l;
  f->num=f1->num*(l/f1->denom) + f2->num*(l/f2->denom);
  reduce_to_lowest_terms(f);
  return f; 
}
void inv ( FP f)
 {
    long long tmp=f->num;
    f->num=f->denom;
    f->denom=tmp;
 }
int chk(FP f)
{
   long long n=f->num,i=0;
   while(n){n/=10;i++;}
   n=f->denom;
   while(n){n/=10;i--;}
   return i;
} 
void copy(FP c1, FP c2) //c2 's values get copied to c1
{
  c1->num=c2->num;
  c1->denom=c2->denom;
}
int main()
{
//starting
   clock_t begin=clock(),end;time_t b=time(&b),e;
//middle-actual code
FP f=get_fraction();

int i=1,count=0;
FP strt=get_fraction(),two=get_fraction(),one=get_fraction(),tmp=get_fraction();
    two->num=2;one->num=1;two->denom=one->denom=1;
    copy(strt,two);
while(i<=1000)
 {
    if(i>1)
     { 
        copy(strt,tmp);
        //inv(strt);
        //strt=add(strt,two);
         strt->num+=((strt->denom)<<1);
         reduce_to_lowest_terms(strt);
      }
    
    inv(strt);
    copy(tmp,strt);
    //printf("b4add1.. %ld--%ld\n",strt->num,strt->denom);
    strt->num+=strt->denom;
    //printf("before:gcd--%ld:%ld\n",strt->num,strt->denom);
    reduce_to_lowest_terms(strt);

    if(chk(strt)){
         count++;
         printf("%d, %d--> %lld:%lld\n",count,i,strt->num,strt->denom);
    }   
   i++;       
 }   

//ending
    end=clock();e=time(&e);
   printf(" Processor Time taken is %f.\n",(double)((end-begin)/(double)CLOCKS_PER_SEC));
   printf(" Time taken is %f.\n",difftime(e,b));

return 0;
}
