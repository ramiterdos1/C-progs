#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>
int main()
{
 initscr();
   raw();
  for(int i=5;i<36;i++)
  { mvprintw(10,i%15,"Hey ram man!\n");
    mvprintw(i,10,"Hojo");
   //time_t t;time(&t);
   //printw("Time now is : %s\n",ctime(&t));
  // sleep(2);
  getch();
   clear();
}
  endwin();
// } 
return 0;
}
