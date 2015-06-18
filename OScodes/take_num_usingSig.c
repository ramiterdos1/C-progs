#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
struct Data{int num;unsigned long factorial;int pid_tknum;int pid_fact;};
int main()
{
	key_t SomeKey;
	struct Data *c;
	int shm_id;
	char *shm,ch;
	SomeKey=12345;
	if((shm_id=shmget(SomeKey,sizeof(struct Data),IPC_CREAT | 0666))<0)
	{
		printf("shmget\n");
		exit(1);
	}
	if((shm=shmat(shm_id,NULL,0))==(char *)-1)
	{
		printf("shmat\n");
		exit(1);
	}
	c=(struct Data *)shm;
        c->num=c->factorial=c->pid_tknum=c->pid_fact=0;
       sleep(15);
        c->pid_tknum=getpid();
//	c->pid_fact=0;     
	while(c->pid_fact==0)sleep(1);
        printf("tknum pid=%d ... find fact pid=%d\n",c->pid_tknum,c->pid_fact);
	do
	{
		printf("Enter a number to find a Factorial : ");
		scanf("%d",&c->num);getchar();		
	              	kill(c->pid_fact,SIGTERM);    
		pause();
                signal(SIGUSR1,SIG_IGN);
                printf("The Factorial of %d is %lu.\n",c->num,c->factorial);
		printf("Do you want to continue (Y/N)?");
		ch=getchar();getchar();
		   if(ch=='y'||ch=='Y'){;}
		   else 
	              	kill(c->pid_fact,9);    
	}while(ch=='y'||ch=='Y');
	return 0;
}
