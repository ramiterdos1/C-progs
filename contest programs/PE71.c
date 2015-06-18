#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
struct frac{
  long num;long denom;
   };
typedef struct frac * FracPointer;
FracPointer get_fraction()
{
   FracPointer f=(FracPointer)malloc(sizeof(struct frac));
   return f;
}
int gcd(long a,long b)
{
  if(a<b)return gcd(b,a);
  else {
         if(b==0)return a; 
         else return gcd(b,a%b); 
       } 
}
void reduce_to_lowest_terms(FracPointer f)
{
int hcf=gcd(f->num,f->denom);
f->num/=hcf;
f->denom/=hcf;
}

int main()
{
   clock_t begin=clock(),end;time_t b=time(&b),e;
   FracPointer f=get_fraction();
   f->num=2;f->denom=5;
   while(f->denom<=1000000-7)
   { f->num+=3;f->denom+=7;reduce_to_lowest_terms(f);}
   printf("%ld/%ld\n",f->num,f->denom);
   end=clock();e=time(&e);
   printf(" Processor Time taken is %f.\n",(double)((end-begin)/(double)CLOCKS_PER_SEC));
   printf(" Time taken is %f.\n",difftime(e,b));

}
