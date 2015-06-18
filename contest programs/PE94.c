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
  if(a<b) return gcd(b,a);
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
int is_Int(FracPointer f)
{
  int flag=((long)sqrt(f->num)-sqrt(f->num))*1000000;
    if(flag)return flag;
   flag=((long)sqrt(f->denom)-sqrt(f->denom))*1000000;
    return flag;    
 }
int main()
{
  clock_t begin=clock(),end;time_t b=time(&b),e;
  long a=3,sum=0;
  long limit=333333333;
  while((a=a+2)<=limit)
   {
     FracPointer f1=get_fraction();
      f1->num=a-1;f1->denom=(3*a+1);
      reduce_to_lowest_terms(f1);
     if(!is_Int(f1)){sum+=3*a+1;//printf("%9ld...%9ld.....%12ld\n",a,a+1,sum);
}
      else { 
       f1->num=a+1;f1->denom=(3*a-1);
       reduce_to_lowest_terms(f1);
       if(!is_Int(f1)){sum+=3*a-1;//printf("%9ld...%9ld..%12ld\n",a,a-1,sum);
}
       }
   }
    printf("%ld\n",sum);
   end=clock();e=time(&e);
   printf(" Processor Time taken is %f.\n",(double)((end-begin)/(double)CLOCKS_PER_SEC));
   printf(" Time taken is %f.\n",difftime(e,b));
} 
