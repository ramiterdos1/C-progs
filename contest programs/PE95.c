#include <stdlib.h>
#include<stdio.h>
#include<math.h>
#define no_of_primes_below_1k 168
#define pr_len 169

int primes[200]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997,1009};
struct N
{
int p_gr_1009;int p_pow[170];int f_p:2;
};
typedef struct N N;
N arr[1000000];
struct Nrep
{
int p_fact[10];int p_pow[10];int f_p:1;
};
typedef struct Nrep Nrep;
void init2(Nrep n)
{
 n.f_p=0;
 for(int i=0;i<10;i++)
    n.p_fact[i]=n.p_pow[i]=0;
}
void init(N a)
{
a.p_gr_1009=0;
for(int i=0;i<170;i++)a.p_pow[i]=0;
a.f_p=0;
}
void calc(int j)
{
  if(j>1010)
   {
     arr[j].f_p=1;
     int x=j, c=0;
     for(int i=0;i<pr_len;i++)
         {
            c=0;
            while(!(x%primes[i]))
                 {c++;x/=primes[i];
                   if(x==1)break;}
               arr[j].p_pow[i]=c;
               if(c)arr[j].f_p=0;
          }
     if(x>1000)arr[j].p_gr_1009=x;
   }
  else
   {
     static int cnt=0;
     if(primes[cnt]==j)
       {
        arr[j].p_pow[cnt++]=1;arr[j].f_p=1;
        }
     else
       {
         int x=j,c=0;
         for(int i=0;i<cnt;i++)
             { c=0;
               while(!(x%primes[i]))
                   {c++;x/=primes[i];
                      if(x==1)break;}
               arr[j].p_pow[i]=c;
             }
                
       }
   }
}
Nrep a[1000000];
long fast_powr(int x, int y)
{
long prod=1;
while(y>0)
  {
    if(y&1)
      {
        prod*=x;
      }
       y>>=1;
       x*=x;
  }
 return prod;
}
int sigma(int n)
{
 int prod=1;
 for(int i=1;i<a[n].p_fact[0];i++)
     if(a[n].p_pow[i]==1)
       prod*=(a[n].p_fact[i]+1);
      else 
       prod*=(fast_powr(a[n].p_fact[i],a[n].p_pow[i]+1)-1)/(a[n].p_fact[i]-1);
  prod-=n;  
 return prod<1000000?prod:1; 
}
int main()
{
int perfectcycle[1000000];
for(int j=2;j<1000000;j++)
   {
     init(arr[j]);
     init2(a[j]);
     perfectcycle[j]=0;
      calc(j); 
    if(arr[j].f_p)
      { a[j].f_p=1;perfectcycle[j]=-1;}
    else
      { int s=1;
        for(int i=0;i<pr_len;i++)
            if(arr[j].p_pow[i]>=1)
              {
                 a[j].p_fact[s]=primes[i];
                 a[j].p_pow[s]=arr[j].p_pow[i];
                 s++;
              }
       if(arr[j].p_gr_1009>0)
          { 
           a[j].p_fact[s]=arr[j].p_gr_1009;
           a[j].p_pow[s++]=1;
          }
       a[j].p_fact[0]=s;
     }
   }
  int big=1,num=0,nm=0;
 for( int i=4;i<1000000;i++)
   {
     int c=0,j=i;
     if(perfectcycle[i]==0)
       {
       while(j>1)
         {
           j=sigma(j);
           c++;
           if(j==12496)printf("##%d##\n",i);
           if(perfectcycle[j]!=0)break;
           else perfectcycle[j]=1; 
           if(j==i)j=0;
         }  
       }
     if(!j){
             perfectcycle[i]=c;
             printf("%d(%d)\n",i,c);
           }
     else perfectcycle[i]=1;
     if(perfectcycle[i]>big)
       {
         big=perfectcycle[i];
         num=i;
       }
     
    }
   printf("%d->",nm=num);
   for(int i=1;i<big;i++)
      {  printf("%d->",nm=sigma(nm));}
   printf("%d->...\n",num);
return 0;
}
