#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#define lim 1000000
long nos[lim],pr[lim];
struct frac{
  long num;long denom;
   };
typedef struct frac * FracPointer;
FracPointer get_fraction()
{
   FracPointer f=(FracPointer)malloc(sizeof(struct frac));
   return f;
}
void init()
{
int i=0;
do{
nos[i]=i%2?0:1;pr[i]=0;
}while(i++<1000000);
pr[0]=2;
}
long gcd(long a,long b)
{
  if(a<b)return gcd(b,a);
  else {
         if(b==0)return a; 
         else return gcd(b,a%b); 
       } 
}
void gen_pr()
{
    int cnt=1,i=0;long n=1;
    while((n+=2)<lim)
    {  
       int flag=1;
       if(nos[n])flag=0;
       else
          for(i=0;i<cnt;i++)if(n%pr[i]==0){flag=0;break;}
       if(flag){
                  pr[cnt++]=n;
                  int i=3;
                  while(i*n<lim)
                  {
                    nos[i*n]=0;
                    i+=2;	
                  }
                }
    }//end of while()
    
    
}
void reduce_to_lowest_terms(FracPointer f)
{
long hcf=gcd(f->num,f->denom);
f->num/=hcf;
f->denom/=hcf;
}
int main()
{
//starting
   clock_t begin=clock(),end;time_t b=time(&b),e;
//middle-actual code
   init();gen_pr();int i=0,j=0;
   FracPointer f=get_fraction();
    f->num=f->denom=1;
   do
    {  f->num*=pr[i++];
       //printf("%d. is %ld ..%d.\n",i,f->num, f->num<=lim);
    } while(f->num<=lim);
   
    printf("The Number n is %ld.\n",f->num/pr[--i]);
    f->num=1;
    while(j<i)
    {
       f->num*=pr[j];
       f->denom*=(pr[j++]-1);
       reduce_to_lowest_terms(f);
    }
    printf("The Value of n/Euler_Tot(n) n is %ld/%ld =%ld/100000\n",f->num,f->denom,(f->num*100000)/f->denom);
    
   //ending
    end=clock();e=time(&e);
   printf(" Processor Time taken is %f.\n",(double)((end-begin)/(double)CLOCKS_PER_SEC));
   printf(" Time taken is %f.\n",difftime(e,b));

}