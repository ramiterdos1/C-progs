#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{//fork();
if(fork()==0){fork();printf("Ramit\n");}
printf("Das\n");
}
