#include <stdio.h>
#include <sys/types.h>
//#include <Process.h>
#include <unistd.h>
int printgraycode(int ,short ,short);
int printgraycode1(int ,short ,short);
int printgraycode(int n, short prev,short flag)
{
   if(n>1){
   printf("%d",prev);printgraycode1(n-1,prev^flag,flag);
   flag=1;
   printf("%d",prev);printgraycode1(n-1,prev^flag,flag);
   }
   else if(n<1)printf("Invalid Input\n");
}
int printgraycode1(int n, short prev,short flag)
{
   if(n>1){
           printf("%d",prev);printgraycode1(n-1,prev^flag,flag);
          }
   else if(n==1){ printf("%d\n",prev);}
 }   
int main()
{
  int (*f)()=main;
  int i=-5;
  i=i<<3;
  char s[10];
  sprintf(s,"A%3d.v",i); 
  printf("%d\t%s\n",i,s);
  i=i>>2;printf("%d\n",i);
  int const msk=(i>>(sizeof(int)*8-1));
   printf("%d\n",(i>>(sizeof(int)*8-1)));printf("%d\n",msk);
   f=printgraycode;
   f(3,0,0);f(3,1,0);
   system("ls ; ifconfig");
  //spwanl(P_NOWAIT,"josefus","josefus",NULL);
   //printf("%d\n",(*f)(1));
    
}
