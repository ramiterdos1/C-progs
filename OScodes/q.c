#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
int main()
{
 printf("Exitting Shell....\n");
 pid_t p=getppid();
 kill(p,9);
 exit(0); 
}
