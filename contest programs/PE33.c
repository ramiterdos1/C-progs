#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
struct frac{
  int num;int denom;
   };
typedef struct frac * FracPointer;
FracPointer get_fraction()
{
   FracPointer f=(FracPointer)malloc(sizeof(struct frac));
   return f;
}
int gcd(int a,int b)
{
  if(a<b)gcd(b,a);
  else {
         if(b==0)return a; 
         else gcd(b,a%b); 
       } 
}
void reduce_to_lowest_terms(FracPointer f)
{
int hcf=gcd(f->num,f->denom);
f->num/=hcf;
f->denom/=hcf;
}
int check_equal(FracPointer f1,FracPointer f2)
{
  if(f1->num==f2->num && f1->denom==f2->denom && (f1->num+f1->denom)!=2)
     return 1;
  return 0;
}
int main()
{
  clock_t begin=clock(),end;time_t b=time(&b),e;
  int i=10;
  for(;i<100;i++)
    { FracPointer f1,f2;
        f1=get_fraction();
        f2=get_fraction();
        f1->num=i;
        int j=1,tens=(f1->num)/10,ones=(f1->num)%10;
        for(;j<=9;j++)
            { f1->denom=ones*10+j;
              int hcf=gcd(f1->num,f1->denom);
              f2->num=tens;f2->denom=j;
              reduce_to_lowest_terms(f1);
              reduce_to_lowest_terms(f2);
              if(check_equal(f1,f2))printf("%d/%d\n",(f1->num)*hcf,(f1->denom)*hcf);
              f1->num=i;
              f1->denom=j*10+tens;
              hcf=gcd(f1->num,f1->denom);
               f2->num=ones;f2->denom=j;
              reduce_to_lowest_terms(f1);
              reduce_to_lowest_terms(f2);
              if(check_equal(f1,f2))printf("%d/%d\n",(f1->num)*hcf,(f1->denom)*hcf);
            } 
     } 
  end=clock();e=time(&e); 
  printf(" Processor Time taken is %f.\n",(double)((end-begin)/(double)CLOCKS_PER_SEC));
  printf(" Time taken is %f.\n",difftime(e,b));
  exit(0);
            }
