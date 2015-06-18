#include <unistd.h>
#include <stdio.h>
int main()
{
pid_t p;
p=fork();
if(p<0)
{printf("Error!\n");
 exit(-1);
}
else if(p==0){
printf("HIII HAAA HUU\n");
execlp("/bin/ls","ls",NULL);
}else {
wait(NULL);
printf("Child hihihihi\n");
exit(0);
}
}
