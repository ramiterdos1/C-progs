#include "NewsBasicStructures.h"
#include <string.h>
typedef struct editor
{ 
   char *name; char *passwd;}*ed;
FILE *f;//file to store the list of editors
char *fn="Edz";
void create_account(char *n,char *pass)
{
   f=fopen(fn,"a");
   fprintf(f,"%s,%s\n",n,pass);
   fclose(f);
}
int login(char *n,char *pass)
{
   f=fopen(fn,"r");char *nchk,*pchk;int flag=0;//0->login failure
   fscanf(f,"%s,%s\n",nchk,pchk);if(nchk==EOF)printf("create an account first!!!");
   else{
   while(nchk!=EOF && strcmp(n,nchk)!=0 )
    {
      if(strcmp(n,nchk)==0)
          {if(strcmp(pass,pchk)==0)
             {printf("YOU HAVE SUCCESFULLY LOGGED IN!\n");  flag=1;}
            else printf("PASSWORD IS ENTERED INCORRECTLY!");
	  }
     }
    } if(nchk==EOF)printf("create an account first!!!");
    return flag;
}
void addBeginnning(News n)
{
  Q tmp;tmp->n=n;tmp->nxt=null;//creating Quenode
  extern Qunewz qn;
  qn->head=qn->tail=tmp;
}//creating first news
void add(News n)
{
  Q_nd *tmp=(Q_nd *)malloc(sizeof(Q_nd);tmp->n=n;tmp->nxt=null;
  extern Qunewz *qn;
   qn->tail->nxt=tmp;
}//creating news queue
void newsentry(int flag)//flag denotes first entry or not
{  News *n=(News *)malloc(sizeof(News));char *s[5];
  printf("\nDAY:");scanf("%d",&(n->day));getchar();
  printf("\nMONTH:");scanf("%d",&(n->month));getchar();
  printf("\nYEAR:");scanf("%d",&(n->year));getchar();
  printf("\nENTER THE POLITICAL NEWS:" );scanf("%s",s[0]);
  printf("\nENTER THE TECHNOLOGY NEWS:" );scanf("%s",s[1]);
  printf("\nENTER THE SPORTS NEWS:" );scanf("%s",s[2]);
  printf("\nENTER THE INTERNATIONAL NEWS:" );scanf("%s",s[3]);
  printf("\nENTER THE ENTERTAINMENT NEWS:" );scanf("%s",s[4]);
  n->news=s;
  if(flag==0)addBeginning(*n);
   else add(*n);
}//news entry being made

  
