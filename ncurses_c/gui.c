#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>
int main()
{
 initscr();
 for(;;)
{
   clear();
   raw();
   printw("Hey ram man!\n");
   time_t t;time(&t);
   printw("Time now is : %s\n",ctime(&t));
   //sleep(100);
  if( getch()=='x')exit(0);
   else endwin();
 } 
return 0;
}
