#include<stdio.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<stdlib.h>
#define mutexac 1
#define mutexcc 2
#define mutexsl 3
#define bookac 4
#define cnclac 5
#define bookcc 6
#define cnclcc 7
#define booksl 8
#define cnclsl 9
#define check 10
#define ac_sts 50
#define cc_sts 100
#define sl_sts 60

void P_OR_V(int sem_id,int n,int flag)
{ 
 struct sembuf buf;
 buf.sem_num=n;
 buf.sem_op=(flag==1)?-1:1;//issues a wait state if flag=1 else issues the signal to carry on the operations
 buf.sem_flg=0; 
 semop (sem_id,&buf,1);
} //wait=proberen=to test & V=verhogen=signal=to increment
//for booking
void book(int semid,int *ac_avail,int *cc_avail,int *sl_avail)
{
	int c,t;
	printf("Enter the class-->\n 1:ac\n 2:cc\n 3:sl\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:P_OR_V(semid,mutexac,1);
		       P_OR_V(semid,check,1);
		       P_OR_V(semid,cnclac,1);
                       //issued wait to any other process who is cancelling ac chairs,checking for availabilty of seats and accesing this part of the code
		       printf("How many tickets to book?\n");
		       scanf("%d",&t);
		       *ac_avail=(t<=*ac_avail)?(*ac_avail-t):(t=-1,*ac_avail);
			if(t>0){printf("No. of tickets booked in ac :%d\n",t);
			      //printf("Now Available :%d",*ac_avail);
                             }
                        else printf("Shortage of ticket. Tickets can't be Booked!\n");
                        //releasing the critical section
			P_OR_V(semid,mutexac,0);
			P_OR_V(semid,check,0);
			P_OR_V(semid,cnclac,0);
			break;
		case 2: P_OR_V(semid,mutexcc,1);
			P_OR_V(semid,check,1);
			P_OR_V(semid,cnclcc,1);
                        //same as above but this time its for the chair car seats
                        printf("How many tickets to book?\n");
		        scanf("%d",&t);
		        *cc_avail=(t<=*cc_avail)?(*cc_avail-t):(t=-1,*cc_avail);
			if(t>0){printf("No. of tickets booked in chair car :%d\n",t);
			      //printf("Now Available :%d",*ac_avail);
                             }
                        else printf("Shortage of ticket. Tickets can't be Booked!\n");
                        //releasing the critical section
			P_OR_V(semid,mutexcc,0);
			P_OR_V(semid,check,0);
			P_OR_V(semid,cnclcc,0);
			break;
		case 3: P_OR_V(semid,mutexsl,1);
			P_OR_V(semid,check,1);
			P_OR_V(semid,cnclsl,1);
                        //same as above but this time its for the sleeper seats
			printf("How many tickets to book?\n");
		        scanf("%d",&t);
		        *sl_avail=(t<=*sl_avail)?(*sl_avail-t):(t=-1,*sl_avail);
			if(t>0){printf("No. of tickets booked in sleeper :%d\n",t);
			      //printf("Now Available :%d",*ac_avail);
                             }
                        else printf("Shortage of ticket. Tickets can't be Booked!\n");
			//releasing the critical section 
			P_OR_V(semid,mutexsl,0);
			P_OR_V(semid,check,0);
			P_OR_V(semid,cnclsl,0);
			break;
		default: printf("Wrong input!\n");
			 break;
	}
}
//for cancelling tickets
void cancel(int semid,int *ac_avail,int *cc_avail,int *sl_avail)
{
	int c,t;
	printf("Enter the class:\n 1:ac\n 2:cc\n 3:sl\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1: P_OR_V(semid,mutexac,1);
		        P_OR_V(semid,check,1);
		        P_OR_V(semid,bookac,1);
                       //issued wait to any other process who is booking ac chairs,checking for availabilty of seats and accesing this part of the code
			printf("Enter the no. of tickets to be cancelled :");
		        scanf("%d",&t);
		        (*ac_avail)+=t;
			if((*ac_avail)>ac_sts)
			   *ac_avail=ac_sts;
			printf("No. of tickets available in ac :%d\n",*ac_avail);
                        //releasing the critical section   
			P_OR_V(semid,mutexac,0);
			P_OR_V(semid,check,0);
			P_OR_V(semid,bookac,0);
			break;
		case 2: P_OR_V(semid,mutexcc,1);
			P_OR_V(semid,check,1);
			P_OR_V(semid,bookcc,1);
			//same as above but this time its for the chair car seats
			printf("Enter the no. of tickets to be cancelled :");
		        scanf("%d",&t);
                        (*cc_avail)+=t; 
			if((*cc_avail)>cc_sts)
			   *cc_avail=cc_sts;
			printf("No. of tickets available in cc :%d\n",*cc_avail);
			//releasing the C.S.
                        P_OR_V(semid,mutexcc,0);
			P_OR_V(semid,check,0);
			P_OR_V(semid,bookcc,0);
			break;
		case 3: P_OR_V(semid,mutexsl,1);
			P_OR_V(semid,check,1);
			P_OR_V(semid,booksl,1);
                        //same as above but this time its for the sleeper seats
			printf("Enter the no. of tickets to be cancelled :");
		        scanf("%d",&t);
                        *sl_avail+=t;
			if((*sl_avail)>sl_sts)
			   *sl_avail=sl_sts;
			printf("No. of tickets available in sl :%d\n",*sl_avail);
			//releasing the C.S.
                        P_OR_V(semid,mutexsl,0);
			P_OR_V(semid,check,0);
			P_OR_V(semid,booksl,0);
			break;
		default:printf("Wrong input!\n");
			break;
	}
}
//for checking availability				
void checkavail(int semid,int *ac_avail,int *cc_avail,int *sl_avail)
{
	int c,t;
	int count=0;
	printf("Enter the class:\n 1:ac\n 2:cc\n 3:sl\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1: P_OR_V(semid,mutexac,1);
			P_OR_V(semid,bookac,1);
			P_OR_V(semid,cnclac,1);
                        //issuing wait to booking and cancelling ac seats and the access to this part of the code 
			printf("No. of tickets available :%d\n",*ac_avail);
                        //releasing the critical section
			P_OR_V(semid,bookac,0);
			P_OR_V(semid,cnclac,0);
			P_OR_V(semid,mutexac,0);
			break;
		case 2: P_OR_V(semid,mutexcc,1);
			P_OR_V(semid,bookcc,1);
			P_OR_V(semid,cnclcc,1);
			//issuing wait to booking and cancelling chair car seats and the access to this part of the code 
			printf("No. of tickets available :%d\n",*cc_avail);
			//releasing the critical section
                        P_OR_V(semid,bookcc,0);
			P_OR_V(semid,cnclcc,0);
			P_OR_V(semid,mutexcc,0);
			break;
		case 3: P_OR_V(semid,mutexsl,1);
			P_OR_V(semid,booksl,1);
			P_OR_V(semid,cnclsl,1);
			//issuing wait to booking and cancelling sleeper seats and the access to this part of the code 
			printf("No. of tickets available :%d\n",*sl_avail);
			//releasing the critical section
                        P_OR_V(semid,booksl,0);
			P_OR_V(semid,cnclsl,0);
			P_OR_V(semid,mutexsl,0);
			break;
		default:printf("Wrong Input!\n");
			break;
	}
}



int main()
{
         //initializations of shared memory and the semid 
           
	int shmidac,shmidcc,shmidsl,*ac,*sl,*cc,ac_avail,cc_avail,sl_avail,semid,ch=0;
	key_t key1,key2,key3,key4; //key values to the shared memories allocated for ac, cc, and sl seats and the semaphore set id
	key1=1221;
	key2=1111;
	key3=1234;
	key4=2211;
	shmidac=shmget(key1,sizeof(int),IPC_CREAT|0666);
	if(shmidac<0)
	{
		perror("shmget");
		exit(1);
	}
	shmidcc=shmget(key3,sizeof(int),IPC_CREAT|0666);
	if(shmidcc<0)
	{
		perror("shmget");
		exit(1);
	}
	shmidsl=shmget(key4,sizeof(int),IPC_CREAT|0666);
	if(shmidsl<0)
	{
		perror("shmget");
		exit(1);
	}
        //printf("%d...%d...%d...\n",shmid1,shmid2,shmid3);
	system("clear");
         	ac=(int *)shmat(shmidac,NULL,0);
		cc=(int *)shmat(shmidcc,NULL,0);
		sl=(int *)shmat(shmidsl,NULL,0);
		*ac=ac_sts;
		*sl=sl_sts;
		*cc=cc_sts;

		semid=semget(key2,10,IPC_CREAT|0777);//a set of 10 semaphores
		if(semid<0)
		{
			perror("semid");	
			exit(1);
		}
		semctl(semid,mutexac,SETVAL,1);
		semctl(semid,mutexcc,SETVAL,1);
		semctl(semid,mutexsl,SETVAL,1);
		semctl(semid,bookac,SETVAL,1);
		semctl(semid,cnclac,SETVAL,1);
		semctl(semid,bookcc,SETVAL,1);
		semctl(semid,cnclcc,SETVAL,1);
		semctl(semid,booksl,SETVAL,1);
		semctl(semid,cnclsl,SETVAL,1);
		semctl(semid,check,SETVAL,1);
          
         //process area
       
	
	while(ch!=4)
	{
        printf("%20selcome to the railway reservation system","W");
	printf("\nEnter your choice:\n 1:book\n 2:check\n 3:cancel\n 4:quit\n");
	scanf("%d",&ch);   
	switch(ch)
	{
		case 1: book(semid,ac,cc,sl);
                        sleep(10);system("clear"); 
			break;
		case 2: checkavail(semid,ac,cc,sl);
			sleep(10);system("clear");break;
		case 3: cancel(semid,ac,cc,sl);
			sleep(10);system("clear");break;
		case 4: printf("\n%20s..Thank You...Exitting system...\n",".");
			exit(0);break;
                default:printf("Wrong input!\n");
			break;
	}
	}
	
	
}
