#include <stdio.h>
int i,q,div;//global variables
//declaring function prototypes
int powr(int ,int);// returns m^n
int root(int,int);// return integral part of root n
void root2(int,int);// returns decimal part of the root n
int nodig(int);// returns the no of digits of a no n
//function definitions
int nodig(int n)
{    int j;
     for(;1;j++)
        if((n/powr(10,j))==0)
           break;
      return j;
}// end of nodig()              
    

int powr(int m,int n)
{
     int p=1;
     for(;n>0;n--)
         p*=m;
     return p;    
}//end of powr
int root(int ans,int n)
{    int r;
     if(i>0){
     i=i-2;div=div*100+((n>0)?(n/powr(10,i)):0);
     for(r=1;r<=10;r++)
         if(((q*10+r)*r)>div) 
             break;
     r=r-1;
     ans=ans*10+r;
     q=q*10+2*r;
     div=div-(q-r)*r;
     n=((n>0)?(n%powr(10,i)):0);
     return root(ans,n);}//end of if
     else return ans; 
}//end of root

      
main()
{
      double inp;
      int n,j,ans=0,lim=4;
      i=q=div=0;
      printf("Enter the number:\n");
      scanf("%lf",&inp);
      printf("input=%f\n",inp);
      n=(int)inp;
      printf("Integral part=%d\n",n);
      i=nodig(n);//checking no of digits
      //modifying initial checkings        
      if(i%2==0)
         {lim=10;i=i-2;}
      else i=i-1;  
      
        
      for(j=1;j<=lim;j++)
           if((j*j)>(n/powr(10,i)))
               {j-=1;ans=j;
                 q=(2*j); div=(n/powr(10,i)-j*j);
                ans=root(ans,n%powr(10,i));
                break;}
            
     n=(int)((inp-n)*powr(10,8));printf("floating part %lf n=%d\n",(inp-n),n);
     printf("The square root of %f is %d.",inp,ans);ans=0;
     if(div!=0){i=16;ans=root(ans,n);}
     
     lim=nodig(ans);
     
     for(j=1;j<=(8-lim);j++) printf("0");
     printf("%d\n",ans);  
}//end of main()                       
              
