#include <stdio.h>
#include <stdlib.h>

//200-digit numbers
struct Bignum
{
  int num[200];
  int len;
};

typedef struct Bignum Bignum;

void reverse(Bignum *b)
{
 // printf("Rev\n");
  int i,val=b->len;
  for(i=0;i<(val>>1);i++)
    { int tmp=b->num[val-1-i];
      b->num[val-1-i]=b->num[i];
      b->num[i]=tmp;
    }
  
}

void display(Bignum *b)
{ //printf("Disp\n");
  int i=b->len-1;
   for(;i>=0;i--)
    {
     printf("%d", b->num[i]);
     
     }
    printf("\n");

}
void convert(long long i,Bignum *b)
{
  int j=0;
  while(i)
  {
     b->num[j++]=i%10;
    i/=10;
   }
  b->len=j;
}

Bignum add( Bignum *n1, Bignum *n2)
   {
    if(n1->len < n2->len)return add(n2,n1);
    Bignum summand;
    //printf("Inside add!");
    int i=1,j=n2->len-1;
    int c=n1->num[0]+n2->num[0];
    summand.num[0]=c%10;
    //printf("yooo-- %d->%d\n",0,summand.num[0]);
    c=c/10;
    while(i<=j)
     {
        c=c+n1->num[i]+n2->num[i];
       summand.num[i]=c%10;
   // printf("yooo--- %d->%d\n",i,summand.num[i]);
       c/=10;
       i++;
     }
     j=n1->len-1;
    while(i<=j)
      {
        c+=n1->num[i];
        summand.num[i]=c%10;
    //printf("yooo---%d->%d\n",i,summand.num[i]);
        c/=10;
        i++;
       }
    if(c!=0){summand.num[i]=c;i++;}
    summand.len=i;
    //display(&summand);
    return summand;
  }

Bignum minus( Bignum *n1, Bignum *n2) //absolute
   {
    if(n1->len < n2->len)return minus(n2,n1);
    if(n1->len==n2->len && n2->num[n2->len-1] >n1->num[n1->len-1]) 
        return minus(n2,n1);
    Bignum minuend;
    //printf("Inside add!");
    int i=1,j=n2->len-1;
    int c=n1->num[0]-n2->num[0];
    minuend.num[0]=c<0?10+c:c;
    //printf("yooo-- %d->%d\n",0,minuend.num[0]);
    c=c<0?-1:0;
    while(i<=j)
     {
        c=c+n1->num[i]-n2->num[i];
       minuend.num[i]=c<0?10+c:c;
       c=c<0?-1:0;
       i++;
     }
     j=n1->len-1;
    while(i<=j)
      {
        c+=n1->num[i];
        minuend.num[i]=c<0?10+c:c;
    //printf("yooo---%d->%d\n",i,summand.num[i]);
        c=c<0?-1:0;
        i++;
       }
    //if(c!=0){minuend.num[i]=c;i++;}
    minuend.len=i;
    //display(&minuend);
    return minuend;
}
 Bignum mult(Bignum *n1,Bignum *n2)
{
    if(n1->len < n2->len)return mult(n2,n1);
    Bignum ans;
    int i=0,j=0,l=0,limit=n2->len,l2=n1->len;
     n1->num[l2]=0;l2++;
    for(i=0;i<200;i++)
       {
          ans.num[i]=0;
       } 
   for(i=0;i<limit;i++)
      {
        int cary=0,cary1=0;
        for(j=0;j<l2;j++)
           {
               cary=cary+(n2->num[i])*(n1->num[j]);
               cary1=cary1+ans.num[j+i]+cary%10;
               ans.num[j+i]=cary1%10;
               cary/=10;
               cary1/=10;
            }
        if(cary1!=0){
           ans.num[i+l2]=cary1; 
           if(l<i+l2)l=i+l2+1;
        }
           if(l<i+l2)l=i+l2+1;
        
      }
    ans.len=l;while(ans.num[ans.len-1]==0)--ans.len;
   return ans;
}   
 
 
int main()
{
 char c=0;int len=0; 
 Bignum a,b,sum,prod,sub;
 printf("Enter first number :");
 while(c!='\n'){c=getchar();a.num[len++]=c-'0';};
 printf("Enter second number :");c=0;a.len=len-1;len=0;
 while(c!='\n'){c=getchar();b.num[len++]=c-'0';};b.len=len-1;
//  display(&a);
 // display(&b);
// printf("hello\n");
 reverse(&a);
  display(&a);
 reverse(&b);
  display(&b);
 sum=add(&a,&b);
 prod=mult(&a,&b);
  display(&sum);
  display(&prod);
sub=minus(&a,&b);
  display(&sub);
 return 0;
}

