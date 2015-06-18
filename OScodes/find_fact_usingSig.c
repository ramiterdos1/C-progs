#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
unsigned long Factorial(int num)
{
   int i=0;unsigned long fact=1;
   for(;i<num;i++)
       fact*=i;
   return fact;
}
struct Data{int num;unsigned long factorial;int pid_tknum;int pid_fact;};
void takeAction()//struct Data *c)
{
    	//c->factorial=Factorial(c->num);
	//printf("%lu\n",c->factorial);
       sleep(1);
}
void exitting()
{
 exit(1);
}
int main()
{
	key_t SomeKey;
	struct Data *c;
	int shm_id;
	char *shm;
	SomeKey=12345;
    	signal(SIGTERM,SIG_IGN);//takeAction);
	if((shm_id=shmget(SomeKey,sizeof(struct Data),0666))<0)
	{
		printf("shmget\n");
		exitting();
	}
	if((shm=shmat(shm_id,NULL,0))==(char *)-1)
	{
		printf("shmat\n");
		exitting();
	}
	c=(struct Data *)shm;
        c->num=c->factorial=c->pid_tknum=c->pid_fact=0;
        void (*f)();sleep(10);    
        c->pid_fact=getpid();
        //c->pid_tknum=0;
        while(c->pid_tknum==0)sleep(1);
        printf("%d..%d..MYpid=%d\n",c->pid_tknum,c->pid_fact,getpid());
	while(1)
	{
          pause(); 
    	  signal(SIGTERM,SIG_IGN);//takeAction);
           c->factorial=Factorial(c->num);
	   printf("%lu\n",c->factorial);
          kill(c->pid_tknum,SIGUSR1);
           f=exitting;
	  // signal(SIGUSR2,f);
	}
}
