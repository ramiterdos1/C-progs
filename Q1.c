#include <stdio.h>
#include <math.h>
#include <time.h>
//this question is linked to Nsp
FILE *f;int *ps_fct;
void display(int *);
int *pfact(int m,int);
int *fctmul(int m,int *);
int *psieve(long m);
int *join(int *, int *);
void work1(void);
int totNofact(int *n)
{
    int p=1,i=1;
    for(;i<n[0];i++)p*=(n[i]+1);
    return p;
}// total no of factors
int *join(int *p1, int *p2)
{
    p1=(int *)realloc(p1,(p1[0]+p2[0]-1)*sizeof(int));
    int i=p1[0];for(;i<p1[0]+p2[0]-1;i++)p1[i]=p2[i-p1[0]+1];
    p1[0]=p1[0]+p2[0]-1;
    return p1;
}//joins 2 arrays
int *fctmul(int m,int *p)
{
  int *f=(int *)malloc(p[0]*sizeof(int)),i=1;
  f[0]=p[0];
   for(;i<f[0];i++)
       {int c=1,n=m;for(;((n/=p[i])%p[i])==0;c++);f[i]=c;} 
  return f;     
}//multiplicity of the factors
void display(int *p)
{ 
   int i=1;fprintf(f,"%d-->\n",p[0]);
   for(;i<p[0];i++)
      fprintf(f,"%d\n",p[i]);
   fprintf(f,"\t\t-----------THE END------------\n");   
     
}//displayz an array   
int *pfact(int m,int max)
{
    int i=0,cnt=1,p=1;
    int *pf=(int *)malloc(sizeof(int));
     fprintf(f,"NUMBER-%d\n",m);
    for(;i<max&& p*ps_fct[i]<=m;i++)
        if(m%ps_fct[i]==0){ pf=(int *)realloc((void *)pf,(cnt+1)*sizeof(int));
          pf[cnt++]=ps_fct[i];p*=ps_fct[i];}
    pf[0]=cnt;
    return pf;
}// an array of factorz      
    
int *psieve(long m)
{
    int cnt=1,i=0;unsigned long n=1;
    int *ps=(int *)malloc(sizeof(int));
    ps[0]=2;
    while((n+=2)<m)
    {  
       int flag=1;
       for(i=0;i<cnt;i++)if(n%ps[i]==0){flag=0;break;}
       if(flag){ps=(int *)realloc((void *)ps,(cnt+1)*sizeof(int));
                if(f!=NULL)fprintf(f,"%d\n",(ps[cnt++]=n));
                }
    }//end of while()
    
    //fprintf(f,"\t\t-----------THE END------------\n");
    
    long int s2=0;int j;
    unsigned long long int s1=0;
    //printf("size of long int=%d, long long int=%d!\n",sizeof(long int),sizeof(long long int));
    //for(i=0,j=1;i<cnt;i++,j++)s1+=ps[i];
        //  printf("i=%d,j=%d,s1=%u,s2=%d\n",i,j,s1,s2);
     //printf("The sum of primes under %d is %u.\n",m,sum);
    ps[0]=cnt;
    return ps;
}//prime sieve array list       
int sol (int n)
{
    int a=1,b=0,ns=0;
    for(;a<=n;a++)
        for(b=a+1;b<n;b++)
             if(2*a*b==n*(n-(int)2*sqrt(a*a+b*b)))ns++;
    return ns;
}//solution to a q
void work1()
{
      int *t=psieve(2000000),max=0,num=12,m=0;
      
      for(;num<1000;num++)
          if(max<sol(num)){max=sol(num); m=num;}
      printf("The perimeter %d has a maximum of %d solutions.\n",m,num);
} 
main()
{
      clock_t begin=clock(),end;time_t b=time(&b),e;
      int *pf1,*pf2;f=fopen("outpt.doc","a");
      unsigned long n=12375;ps_fct=psieve(2000000);int mx=ps_fct[0];ps_fct[0]=2;
      
      /*while(n++) 
        { pf1=pfact(n,mx);
          if(pf1[0]==5)
              {int i=1;display(pf1);
                for(;i<4;i++)
                    {pf2=pfact(n+i,mx);
                      if(pf2[0]!=5) break;
                      else{ display(pf2); pf1=join(pf1,pf2);}
                      }//end of for
               }//end of if
          if(pf1[0]==17){printf("The number n is %d.\n",n); break;}
         }        
      display(pf1);*/fclose(f);
      end=clock();e=time(&e);
      printf(" Processor Time taken is %f.\n",(double)((end-begin)/(double)CLOCKS_PER_SEC));
      printf(" Time taken is %f.\n",difftime(e,b));
      
}
