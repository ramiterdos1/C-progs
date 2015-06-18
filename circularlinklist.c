#include <stdio.h>
#include <stdlib.h>
typedef struct j{ int num; struct j *nxt;}Node;
typedef struct C{ Node *ref;}cll;//circular linked list
typedef struct C1{ Node *start;}ll;//linked list
Node *getnode(void);
void addnode(int ,cll *);
void displayNodes(cll *);
int No_of_Nodes(cll *);
void delete(int nth_Node2del,cll *c);
void Ascending_list(Node *,ll *);
cll *Convert_cll_2_ll(ll *);
//end of function prototypes
cll *Convert_cll_2_ll(ll *list)
{ cll *c;
  if(list->start==NULL){printf("No link list to convert!:-|");}
  else {c=(cll *)malloc(sizeof(cll));
  c->ref=list->start;Node *tmp=c->ref,*t=getnode();//*t to create a new circular list altogether..here the list is turned into a circular list by just joining the last with the first thereby not preserving the list
  while(tmp->nxt!=NULL)tmp=tmp->nxt;
  tmp->nxt=c->ref;
   }//end of else
  return c;
}//end of Convert_cll_2_ll()
void Ascending_list(Node *N,ll *l)
{  Node *tmp=l->start,*n=getnode();n->num=N->num;n->nxt=NULL;
   if((tmp->num)>(n->num)){l->start=n;l->start->nxt=tmp;}
   else if(tmp->nxt==NULL)tmp->nxt=n;//takes care of the starting node	
        else{
               while(tmp->nxt!=NULL)if((n->num)>(tmp->nxt->num))tmp=tmp->nxt;else break;
               Node *t=tmp->nxt; tmp->nxt=n;n->nxt=t;
             }//end of insertion of node in ascending order of data present
   
}//end of Ascrnding_list() 
Node *getnode()
{
 return (Node *)malloc(sizeof(Node));
}
void addnode(int n,cll *c)
{
   Node *tmp=c->ref,*t=getnode();t->num=n;t->nxt=NULL;
   if(tmp==NULL){c->ref=getnode();c->ref->num=n;c->ref->nxt=c->ref;}
   else do{ if(tmp->nxt==c->ref){tmp->nxt=t;t->nxt=c->ref;break;}
            else tmp=tmp->nxt;
	   }while(1);
}
void displayNodes(cll *c)
{
   Node *tmp=c->ref;
   if(tmp==NULL)printf("NO NODE 2 DISPLAY!\n");
   else{
   while(tmp->nxt!=c->ref)
    {printf("%d->",tmp->num);tmp=tmp->nxt;}
   printf("%d!!!\n",tmp->num); }
}
int No_of_Nodes(cll *c)
{
   int counter=1;
   Node *tmp=c->ref;
   while(tmp->nxt!=c->ref)
      {tmp=tmp->nxt;counter++;}
   return counter;
}
void delete(int nth_Node2del,cll *c)
{
  int n=nth_Node2del,noe=No_of_Nodes(c),cnt=1;//no of elemnts=noe
  Node *tmp=c->ref; 
  while(noe>=1)
   {  if(tmp==c->ref)displayNodes(c);if(n>noe)noe=No_of_Nodes(c);
      if(cnt==n-1){if(tmp->nxt==c->ref)c->ref=tmp->nxt->nxt;
                    tmp->nxt=tmp->nxt->nxt;
                   cnt=1;tmp=tmp->nxt;
                   noe--;
                  }
      else {tmp=tmp->nxt;cnt++;}
   }
}
main()
{
  char ch='y'; cll *c=(cll *)malloc(sizeof(cll)); int data=0,n=0;c->ref=NULL;
  while(ch=='y' || ch=='Y')
  {
      printf("Do u wish to enter data:(Y/y)");   
      ch=getchar();getchar();
       if(ch=='y' || ch=='Y')
          {    printf("ENTER DATA:");scanf("%d",&data);getchar();addnode(data,c);}    
   }
  
  printf("Enter n which stands for the nth Node to delete in the circular linked list!");
  scanf("%d",&n);getchar();
  ll *l=(ll *)malloc(sizeof(ll));
  l->start=&(Node){c->ref->num,NULL};
  Node *t=c->ref;
  while((t->nxt)!=(c->ref))Ascending_list((t=t->nxt),l);
  cll *d=Convert_cll_2_ll(l);
  delete(n,c);delete(n,d);exit(0);
} 
