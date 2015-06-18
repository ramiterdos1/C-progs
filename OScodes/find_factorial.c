#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
int factorial(int num)
{
	if(num==1)
		return 1;
	else
		return factorial(num-1)*num;
}
struct Data{int num;int factorial;int flag;int exit};
int main()
{
	key_t SomeKey;
	struct Data *c;
	int shm_id;
	char *shm;
	SomeKey=12345;
	if((shm_id=shmget(SomeKey,sizeof(struct Data),0666))<0)
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
	while(1)
	{
		if(c->flag==1)
		{
			c->factorial=factorial(c->num);
			printf("%d\n",c->factorial);
			c->flag=0;
		}
		if(c->exit)
		  exit(0);
	}
	return 0;
}
