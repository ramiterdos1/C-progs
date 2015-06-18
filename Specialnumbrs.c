/* This program displays numbers whose sum of digit factorials 
is equal to  that no. or the fifth power of their digits is
equal to that number!
*/
//time ./a.out
#include <stdio.h>
#include <time.h>
long fact(long n);
long powr5(long n);
long powr5(long n)
{
     long p=1,i=0;
     for(;i<5;i++)p*=n;
     return p;
}//end of powr5()     
long fact(long n)
    {if(n==0)return 1;
      else return n*fact(n-1);
    }// enf of factorial function
main()
{
  clock_t begin=clock(),end;time_t b=time(&b),e;FILE *f;
  f=fopen("outpt.doc","a");
  long l=1000000000;long i=1,s=0;printf("billion=%d.\n",l);
  fprintf(f,"\t\t Factorial nos\n");
  for(;i<10000000;i++)
  {
    int n=i,sum=0;
    while(n>0 && sum<i)
    {
      sum+=fact(n%10);
      n/=10;
    }
    if(sum==i && n==0){printf("%d\n",i);fprintf(f,"%d\n",i);s+=i;}
   }
   printf("The total of all factorial nos is %d.\n",s);
   fprintf(f,"\t\t power nos\n");
   s=0,i=1;
   for(;i<10000000;i++)
  {
    int n=i,sum=0;
    while(n>0 && sum<i)
    {
      sum+=powr5(n%10);
      n/=10;
    }
    if(sum==i && n==0){printf("%d\n",i);fprintf(f,"%d\n",i);s+=i;}
   }
   printf("The total of all 5th power nos is %d.\n",s);
   
   fclose(f);
   end=clock();e=time(&e);
   printf("Processor Time taken is %f.\n",(double)((end-begin)/(double)CLOCKS_PER_SEC));
   printf("Time taken is %f.\n",difftime(e,b));
      
}
              
    
