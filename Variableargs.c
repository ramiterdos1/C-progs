//flawed program
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
void F(int argc,...)
{
  unsigned char *s=(unsigned char *)malloc(sizeof(unsigned char));
  va_list va;
  va_start(va,argc);
  s=(unsigned char *)va;
  printf("%s\n",s);
  while(argc--)
  {
    switch(sizeof(*va))
     {
        case sizeof(int):printf("INT_>%d,",va_arg(va,int));//va+=sizeof(int);
                         break;
        case sizeof(double):printf("FLOAT_>%f,",va_arg(va,int));//va+=sizeof(float);
                           break;
        case sizeof(char):printf("CHAR_>%c,",va_arg(va,int));//va+=sizeof(char);
                          break;
      }
   }; printf("\n");   

  va_end(va);
}
int main()
{
 F(5,'R','A','m','I','T');
 F(3,'a',"pop",8.9);
 F(4,'T',"pop",8,9.0);
 F(7,3,'T',5,8.9,'o','p',"pop");
 F(0);   
}
 
