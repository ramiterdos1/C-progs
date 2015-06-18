#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc,char *argv[])
{
if(argc==3)
{
FILE *fp;
char arg1[50],arg2[50];
printf("%s------%s\n",argv[1],argv[2]);
memset(arg1,0,50);
memset(arg2,0,50);
arg1[0]=arg2[0]='.';
arg2[1]=arg1[1]='/';
printf("%s------%s\n",arg1,arg2);
strcat(arg1,argv[1]);
strcat(arg2,argv[2]);
printf("%s------%s\n",arg1,arg2);
int pfd[2];
pipe(pfd);
pid_t pid=fork();
if(pid==0)
{
close(pfd[0]);//close read end
dup2(pfd[1],1);// write end=stdout
close(pfd[1]);//write end closed thereby, stdout is its write end
execlp(arg1,arg1,NULL);
}
else
{
wait(NULL);
close(pfd[1]);//closed write end
dup2(pfd[0],0);//read end duplicated with stdout
close(pfd[0]);//close read end, stdin ->read end
execlp(arg2,arg2,NULL);
return (0);
}
}
else printf("Too few arguments!!\n");
}
