/*
GrayCode Generation
1-06-13
*/
#include <stdio.h>
#include <stdlib.h>
#define f(a,n) { for(i=a;i<n;(i)+=1) }
#define f_(a,n) { for(i=a;i>n;(i)-=1) }
struct bit{
unsigned int a : 1;
};
typedef struct bit bit;

int main(int argc,char *argv[])
{
   if(argc!=2)
   {
     printf("Enter the graycode length and nothing else!\n");
     
   }
   else {
	   int n=atoi(argv[argc-1]),i=0;
	   if(n<=0){printf("Enter a number greater than zero!\n");exit(0);}
	   bit *g_code,flag;flag.a=1;
	   g_code=(bit *)malloc(n*sizeof(bit));
	   //for(i=0;i<n;i++)
	   //f(0,n)
	   for(i=0;i<n;i++)
	     {
	     	g_code[i].a=0; 
	     }
	   while(flag.a)
	      {  
	         for(i=n-1;i>=0;(i)-=1)printf("%d",g_code[i].a);
	         printf("\n");
	       
	         bit sum;sum.a=0;
	         //f(0,n)
	         for(i=0;i<n;i++)
	         {
	            sum.a+=g_code[i].a;
	         }
	         if(sum.a)
	         {
	            if(g_code[n-1].a)
	               {
	                 flag.a=0;
	                 //f(0,n-1)
	                   for(i=0;i<n-1;i++)
	                     if(g_code[i].a)
	                      {flag.a=1;i=n;}
	               }
	            //f(0,n)
		    for(i=0;i<n;i++)
	            {
	              if(g_code[i].a)
	                 {
	                   g_code[i+1].a++;break;
	                 }
	            }   
	         }
	         else
	         {
	           g_code[0].a++;
	         }
	         }  
	   }
   	   
}
