#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
int main()
{
double d;
int i=2,s,j,int_part;long sum=0;
 for(;i<10;i++)
    {
      s=0;
      switch(i)
       {
          case 4:
          case 9:
          case 16:
          case 25:
          case 36:
          case 49:
          case 64:
          case 81:break;
          default:
               d=sqrt(i);printf("%100f\n",d);
               for(j=1;j<=100;j++)
                  {int_part=(int)d;
                   printf("%d\n",int_part);
                   d-=int_part;
                   printf("%f\n",d);
                   //printf("%d",(int)10*d);
                   s+=10*d;
                   d*=10;
                   }//printf("\n");
               break;
         }
         printf("%d...%d\n",i,s);
         sum+=s;    
            
       }
    printf("The Digital Sum...%ld\n",sum);
}
