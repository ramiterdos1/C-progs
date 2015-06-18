#include <stdio.h>
#include <stdlib.h>

int zigzag(int n)
{
int numstring[100],i=0,val=1;
 while(n)
  {
   numstring[i++]=n%10;n/=10;
   }
 for(int j=0;j<(i/2);j++)
    {int t=numstring[j];numstring[j]=numstring[i-1-j];numstring[i-1-j]=t;}
for(int j=0;j<i-1;j++)
  if((j&1)==0)
      { 
        if(numstring[j]>numstring[j+1])
          {val=0;break;}
       }
   else {
       if(numstring[j]<numstring[j+1])
          {val=0; break;}
   }
  return val;
}

int main()
{
for(int i=101;i<1112;i++)
   {
     //if(zigzag(i))printf("%d is zigzag!!\n",i);
    if(zigzag(i*i*i))printf("%d is has a zigzag cube %d!\n",i,i*i*i); 
   }
   
return 0;
}
