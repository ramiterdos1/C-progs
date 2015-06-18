#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
extern int getchar_unlocked(void);
int main()
{
  fflush(stdin);
  int k=0,inpt[101],outpt[101];
  char c,flag=1; 
  while(flag)
  { int n=0,num=0,i=0,smoke=0;//n=size of input
    while((c=getchar_unlocked())!='\n')
          n=(n<<3)+(n<<1)+(c-'0');
    //taking the array         
    for( i=1;i<=n;i++)
        {
            do
              {
                  c=getchar_unlocked();
                  num=(num<<3)+(num<<1)+(c-'0');
              }while(c!=' '||c!=EOF||c!='\n');
            inpt[i]=num;
            if(c==EOF)flag=0;
        }
      //calculating smoke
      for(i=1;i<n;i++)
       { int p=inpt[1]*inpt[2],a=(inpt[1]+inpt[2])%100,pos=1,j=0,limit=n-i,combined=0,min=0;
         combined=a*p;
         min=combined;
         for(j=2;j<=limit;j++)
           { 
            p=inpt[i]*inpt[i+1],a=(inpt[i+1]+inpt[i])%100;
            combined=a*p;
            if(min>combined){pos=i;min=combined;}
            else if(min==combined){if(a>((inpt[pos]+inpt[pos+1])%100))pos=i; }  
            }
         smoke+=inpt[pos]*inpt[pos+1];inpt[pos]=(inpt[pos]+inpt[pos+1])%100;
         for(j=pos+1;j<limit;j++)inpt[j]=inpt[j+1];
        }
        outpt[k++]=smoke;
     }
      int i=0;
      for(;i<k;i++)printf("%d\n",outpt[i]); 
  }          
