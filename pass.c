#include<stdio.h>
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>

char pw[25],ch;
int i;
static struct termios stored_settings;
void echo_off(void)
{
struct termios new_settings;
tcgetattr(0,&stored_settings);
new_settings = stored_settings;
new_settings.c_lflag &= (~ECHO);
tcsetattr(0,TCSANOW,&new_settings);
return;
}

void echo_on(void)
{
struct termios new_settings;
tcgetattr(0,&stored_settings);
new_settings = stored_settings;
new_settings.c_lflag &= (ECHO);
tcsetattr(0,TCSANOW,&new_settings);
return;
}

void main()
{
//clrscr();
echo_off();
 printf("Enter Password :");
while((ch=getchar())!='\n')
{
  if(ch=='\b') /*ASCII value of BACKSPACE*/
   {
     echo_on();putchar(ch);echo_off();
   }
  else pw[i++]=ch;
  echo_on();putchar('?');echo_off();
}
   pw[i]='\0';
   printf("\n\n %s",pw);
   echo_on();
}
