#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/* this program displays the Number
 as a Sum of Primes in all its possible ways
*/
int *primes;int cnt;
FILE *f;//to store the output
int *psieve(unsigned long m);
void PrimeSum(int n,int,int,int);
int chk(int n1,int n2);
void PrimeSum(int n,int c,int no,int flag)
{
    int i=c;
    for(;flag==1?primes[i]<n:primes[i]<=n;i++)
        {if(n==primes[i] && n!=no)
          {(cnt)++;fprintf(f,"%d+",primes[i]);}
         else if((n-primes[i])!=1 && no>=2*primes[i])
               {  PrimeSum(n-primes[i],i,no,0);
                  fprintf(f,"%d",primes[i]);
                 if(flag!=1)fprintf(f,"+");
               }
         if(no>=2*primes[i+1]&& flag)
            fprintf(f,"=");
         else if(flag==1)fprintf(f,"\n");
         }         
           
}

int *psieve(unsigned long m)
{    
    int cnt=1,i=0;unsigned long int n=1;
    int *ps=(int *)malloc(2*sizeof(int));
    ps[0]=2;ps[1]=3;
    while((n+=2)<m)
    {  
       int flag=1;
       for(i=1;i<cnt;i++)if(n%ps[i]==0){flag=0;break;}
       if(flag){ps=(int *)realloc((void *)ps,(cnt+1)*sizeof(int));
                if(f!=NULL)fprintf(f,"%d ",(ps[cnt++]=n));
                }
    }//end of while()
    
    fprintf(f,"\n");
    ps[0]=cnt;
    return ps;
}//prime sieve array list
main()
{
      clock_t begin=clock(),end;time_t b=time(&b),e;
      f=fopen("primes1000000.doc","w");
      //primes=psieve(10000);int mx=primes[0];int i=3;
      
      //primes[0]=2;cnt=0;PrimeSum(7,0,7,1);
      /*for(;cnt<=5000;i++)
          {  cnt=0;
             fprintf(f,"%d=",i);PrimeSum(i,0,i,1);
             fprintf(f,"\n");
             printf("\n%d--->%d\n",i,cnt);
          }*/
      printf("%lu\n",1000000);
      primes=psieve(1000000);    
      fclose(f);
      
      end=clock();e=time(&e);
      printf(" Processor Time taken is %f.\n",(double)((end-begin)/(double)CLOCKS_PER_SEC));
      printf(" Time taken is %f.\n",difftime(e,b));
      
}             
