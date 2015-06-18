#include <stdio.h>
#include "pe1.h"
//function prototypes
int inputs(void);
void calculation(int i,int div);
void display(int div,int r);
void wrk1(void);
int *num,*q;int nod=0,r=0;//number,quotient & no of digits
int inputs()
{
    num=(int *)malloc(5*sizeof(int));
    int i=0,x=0;char c;printf("Enter the number:");
    while((c=getchar())!='\n')
       if(c!='\n'){if(i>=5) num=(int *)realloc((void *)num,(i+1)*sizeof(int));num[i++]=c-'0';}
    nod=i;// no of digits
    printf("\nEnter the divisor:");scanf("%d",&x);
    return x; 
}//end of inputs()
void calculation(int i,int div)
{    
    if(i<nod)
    {
        q[i]=(r*10+num[i])/div;
        r=(r*10+num[i])%div;
        i++;calculation(i,div);}
    }//end of calculation
void display(int div,int r)
{
     int i=0,chk=0;
     printf("\n");
     for(;i<nod;i++)
         printf("%d",num[i]);
     printf(" / %d = ",div);
     for(i=0;i<nod;i++)
        {if(q[i]!=0)chk=1;
         if(q[i]!=0||chk)  
            printf("%d",q[i]); 
        }
      printf(" with remainder %d.\n",r);  
              
}//end of display()       
void wrk1()
{
      
      int div=0,rem=0;div=inputs();
      
      q=(int *)malloc(nod*(sizeof(int)));
      calculation(0,div);
      display(div,r);
      free((void *)num);free(q);
}//end of main()
