#include <stdio.h>
#include <unistd.h>
#include  <sys/types.h>
#include  <stdlib.h>
#include  <sys/wait.h>
#include <string.h>
typedef struct shellargs
{
 char c[100];  
}shellargs;
int main()
{
      shellargs s[20];
      char c1=0;
      while(1)
    {
      int i=0,j=0,no_pipes=0;
      printf("\nMYSHELL$");
      do{ c1=getchar();
         if(c1==' ' || c1=='\n')
             {s[i].c[j]=0;i++;j=0;}
         else 
             s[i].c[j++]=c1;
         if(c1=='|')no_pipes++;
         }
      while(c1!='\n');
      /*pid_t p;
      p=fork();
      if(p==0)
        {//printf("%d\n",getpid());
           //sleep(50);
           execlp("/bin/echo","echo",c,(char *)NULL);}
      *///printf("%d\n",wait((int *)0)); 
       printf("No of Arguments=%d\n",i);
       printf("No of pipes=%d\n",no_pipes);
      pid_t p;
      p=fork();
      if(p==0)
       {
         if(no_pipes)
           execlp("./pipe1","pipe1",s[0].c,s[2].c,(char *)0);
          else {
                 char arg0[50];
                 memset(arg0,0,50);
                 arg0[0]='.';
                 arg0[1]='/';
                 strcat(arg0,s[0].c);
                 char *c[20];
                 j=-1;
                 while(++j<i){c[j]=s[j].c;printf("%10d-->%s\n",j,c[j]);}
                 c[j]=(char *)0;  
                 //strcpy(s[0].c,arg0);
                 execv(arg0,c);
                 }
         
       }
      wait(NULL); //i--;
      while(i>0){//j=0;
              // while(j<strlen(s[i].c))s[i].c[j++]=0;
               memset(s[i].c,0,strlen(s[i].c));
               i--;} 
      
      }
}
