#include <stdio.h>
#include <unistd.h>

#define a1 a+5+a2
#define a2 3
int a=8;
void f()
{
if(fork()==0)
{
fork();
printf("hello 4m f\n");
}wait(NULL);
return;
}
int main()
{
int result=0,*c=-3*a;
//f();
fork();f();
/*{
printf("child:%d\n",a);
}*/
a+=a1;
asm("setae %%bl;movzbl %%bl,%0" 
     : "r="(result)
     :
     :  "%ebx"
   );
printf("hello 4m main:%d\n",a);
//printf("RESULT:%d\n",result);
}
