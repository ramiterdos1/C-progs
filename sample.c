#include <stdio.h>
#include <time.h>
#define mama(s) (s*s) 
//#define swap(x,y) {printf("SWAPPING\n");printf(#x" =%d\n",x);printf(#y" =%d\n",y);t temp=x;y=temp;printf(#y" =%d\n",y); x=y; printf(#x" =%d\n",x); }
int m1(int ,int);
void m3(int); int ram(int i,char *c);int s=5;
int m1(int m,int n)
{
    printf("hey1\n");
    
     int p=1;
     for(;n>0;n--)
         p*=m;
     return p;    
    return 5;
}
m2(int a)
{
       printf("hey\n");
       return ;
}
void m3(int a)
{
     printf("%d\n",(a=a*a));
     printf("%d\n");
     printf("global s=%d\n",s=a);
     return;
}       
int ram(int r,char *c)
{
    printf("%s%d\n",c,r);
    return *c;
}
main()
{ 
      clock_t begin=clock(),end;time_t b=time(&b),e;
      
     /*for( i =0;i<60;i++)
          printf("%d-%c \t",i,i);
     printf("\n");
     for( i =60;i<120;i++)
          printf("%d-%c \t",i,i);
     printf("\n");
     for( i =120;i<=180;i++)
          printf("%d-%c \t",i,i);
     printf("\n");
     for( i =181;i<=270;i++)
          printf("%d-%c \t",i,i);*/
     printf("\n");
     //printf("%d\n",m1(i*2,3));
     m2(3);
     m3(7);
     
     
   
     int x =3;
     if(x)
      { printf("hi");
         int x=5;
         printf("\ninternal x=%d\n",x);}
     else printf("world\n");
     printf("external x=%d\n",x);
     printf("global s= %d ,s*s=%d\n",s, s*s);
     printf("global s*s=%d\n",mama(1+s));
     printf("square of 4=%d\n",mama(4));
     #undef mama
     //printf("square of 4=%d\n",mama(4)); cant b operated since mama gets undefined
     //swap( s, x);swap(4,5);swap(3.4,2.3);
     static int s=9;

     { extern int s;
        printf("global ++s=%d\n",++s);}       
      printf("external to block s(9)=%d\n",s);    m3(s); 
      printf("external s=%d\n",s);
      /*char *c=(char *)malloc(1*sizeof(char)),c1;int len=0;
      printf("Enter ur name:");
      while((c[len++]=getchar())!='\n');c[len-1]=0;
      for(i=0;i<len-1;i++)
          printf("%c... in addrss %c\n",c[i],&c[i]);printf("%s-> length=%d\n",c,len);
      */struct l { char *n;int r;}l1={"ramit",9};
      printf("%s, %d ...size.=%d",l1.n,l1.r,sizeof(struct l)); 
      printf("%d\n",ram(8,"poll"));
      printf("%o...%x",16,16);
      long p=2,n=7830457,a=9999999999+1,i=2;
       for(;i<=n;i++)
         p=(p*2>a)?(p*2)%a :p*2;
      printf("\n2^%d=%d\n",i-1,p);   
      end=clock();e=time(&e);
      printf(" Processor Time taken is %f.\n",(double)((end-begin)/(double)CLOCKS_PER_SEC));
      printf(" Time taken is %f.\n",difftime(e,b));
      
}

