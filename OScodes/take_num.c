#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
struct Data{int num;int factorial;int flag;int exit};
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
	c->exit=0;
	do
	{
		printf("Enter a number to find a Factorial : ");
		scanf("%d",&c->num);getchar();		
		c->flag=1;
		while(c->flag!=0);
		printf("The Factorial of %d is %d\n",c->num,c->factorial);
		  printf("Do you want to continue (Y/N) ? ");
		   ch=getchar();getchar();
		   if(ch=='y'||ch=='Y')
		    c->exit=0;
		   else c->exit=1;
	}while(ch=='y'||ch=='Y');
	return 0;
}
