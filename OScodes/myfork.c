#include <stdio.h> 
#include <sys/resource.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
int main(int argc,char *argv[])
{
   if(argc!=2)
    { 
      while(argc--)printf("%3d--->%15s\n",argc,argv[argc]);
      printf("Please Input A Proper No. of Command Line Arguments!\n");
    }
  else {
         printf("%5s,%5s\n",argv[0],argv[1]);
         pid_t p;
         p=fork();
         if(p<0)
          {printf("Error in Forking!\n");
           exit(EXIT_FAILURE);
          }
         else if(p==0)
                {
                 char* c[6];c[0]="cat";
                 c[1]="-t";
                 c[2]="-b";
                 c[3]="-v";
                 c[4]=argv[1];
                 c[5]=(char *)0;  
                 //strcpy(c,"cat -b -v -t ");
                 //strcat(c,argv[1]);
                 //strcat(c,"\0");
                 // printf("%s\n",c); 
                 setpriority(PRIO_PROCESS,0,10);
                 printf("%s\n","\t\tCHILD PROCESS");
                 printf("%20s=%4d\n","(c)Process Id",getpid());
                 printf("%20s=%4d\n","(c)Process Group ID",getpgid(getpid()));
                 printf("%20s=%4d\n","(c)Parent Process Id",getppid());
                 printf("(C) Priority -->%d\n",getpriority(PRIO_PROCESS,0));
                 execv("/bin/cat",c);
                 printf("BLAAAAAAAA... :p :p..\n");  
                 // execlp("/bin/cat","cat","-b","-v","-t",argv[1],NULL);--this works too
                 // execlp("/bin/cat","cat -b -v -t ",argv[1],NULL);--this takes only cat as the process call
                // execlp("/bin/cat",c,(char *)0);--this cannot happen
                }
              else
                  { 
                    nice(-5);
                    printf("Time Sleeping..%d",sleep(10));
                    printf("%s\n","\t\tPARENT PROCESS");
                    printf("%20s=%4d\n","(p)Process Id",getpid());
                    printf("%20s=%4d\n","(p)Process Group ID",getpgid(getpid()));
                    printf("%20s=%4d\n","(p)Parent Process Id",getppid());
                    printf("(P) Priority -->%d\n",getpriority(PRIO_PROCESS,0));
                  }
        
       }
}
