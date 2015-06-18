#include <stdio.h>
#include <stdlib.h>
#define Msg printf("No name 2 display!\n")
struct _1dNode{ char *name; struct _1dNode *nxt;};// one directional node
struct _2dNode{ char *name; struct _2dNode *nxt;struct _2dNode *prv;};// two directional node
typedef struct _1dNode N1;
typedef struct _2dNode N2;
typedef struct singly_linked_list{ N1 *start;}sll;
typedef struct doubly_linked_list{ N2 *start;}dll;
sll s;dll d;// global variables
// function signatures
void display_name(char *n);
void display_Nodes(char *n,int flg);
void addNode_sll(char *n);
void addNode_dll(char *n);
void display_list(int i);
int display_menu(int flg);
N1 *getN1(void);
N2 *getN2(void);
void work(void);
//end of function signatures
N1 *getN1()
{  return (N1 *)malloc(sizeof(N1));}
N2 *getN2()
{  return (N2 *)malloc(sizeof(N2));}
void display_name(char *n)
{ while(*n!=0)putchar(*n++);printf("\n");}
void display_Nodes(char *n,int flg)
{ if(flg==1)//indicates sll
    {  N1 *tmp=s.start;if(tmp==NULL)Msg;/*case of no node*/else{
       while(tmp->nxt!=NULL){if(strcmp(tmp->name,n)!=0)tmp=tmp->nxt;
                             else if(tmp->nxt!=NULL && strcmp(tmp->name,n)==0 )
                                      {printf("\nName after %s is ",n);display_name(tmp->nxt->name);printf("\n");break;}
                                  }
       if(tmp->nxt==NULL)Msg;
       }//end of else where minimum one node exists
      }//end of sll
  else 
    {  N2 *tmp=d.start;if(tmp==NULL)Msg;/*case of no node*/else{
       while(tmp!=NULL){if(strcmp(tmp->name,n)!=0){tmp=tmp->nxt;if(tmp==NULL)Msg;}
                    else 
                     { if(tmp->prv!=NULL){printf("\nName before %s is ",n); display_name(tmp->prv->name);}
                       else Msg;
                       if(tmp->nxt!=NULL){printf("\nName after %s is ",n); display_name(tmp->nxt->name);}
                       else Msg;
                       break;
                     }
                            
                 }//end of while
      
      }//end of the case where atleast one node exists
     }//end of dll list name display
}//end of displaying names after and before given name n
void addNode_sll(char *n)
 { 
   N1 *tmp=getN1(),*t=getN1();tmp=s.start;
   if(tmp==NULL)
     { s.start=getN1();s.start->name=n;s.start->nxt=NULL;}
   else { while((tmp->nxt)!=NULL)tmp=tmp->nxt;
             t->name=n;t->nxt=NULL;tmp->nxt=t;
         }
 }
void addNode_dll(char *n)
 {
   N2 *tmp=d.start,*t=getN2();
   if(tmp==NULL)
     { d.start=getN2();d.start->name=n;d.start->nxt=NULL;d.start->prv=NULL;}
   else {while(tmp->nxt!=NULL)tmp=tmp->nxt;
          t->name=n;t->nxt=NULL;t->prv=tmp;tmp->nxt=t;
         }
 }     
void display_list(int i)
{  N1 *t=getN1();N2 *t1=getN2();int c=0;
   if(i==1){t=s.start;
   if(t==NULL)Msg;else{printf("\nNames entered till now!\n");
   while(t!=NULL){printf("%d.",++c);display_name(t->name);t=t->nxt;printf("Pointer of the node is %p.\n",t);}Msg;printf("\n");
    }} else {
            t1=d.start; c=0;
            if(t1==NULL)Msg;else{printf("\nNames entered till now!\n");
            while(t1!=NULL){printf("%d.",++c);display_name(t1->name);t1=t1->nxt;printf("\n");}Msg;printf("\n");
           }} 
}//end of display_list()
int display_menu(int flg)
{
   int ch;char *s=(flg==1)?" ":" before and ";
   printf("1.Insert new Name\n2.Display stored names till now\n3.Display name%safter entered name\n4.Exit\n",s);
   scanf("%d",&ch);getchar();
   return ch;
} 
void work()
{ int ch=0;char *n;
  while(ch!=4)
   { printf("Enter\n1.Work with Singly linked list\n2.Work with Doubly linked list\n3.Continue Working\n4.Exit\n");
     scanf("%d",&ch);getchar();  
      switch (ch)
         {
             case 1:while(ch!=4){
                     ch=display_menu(1);
                     switch(ch)
                       { case 1:
                                printf("Insert The name :");n=(char *)malloc(20*sizeof(char));
                                scanf("%s",n);getchar();
				addNode_sll(n);
				break;
			 case 2:display_list(1);
				break;
			 case 3:printf("Enter The name :");n=(char *)malloc(20*sizeof(char)); 
                                scanf("%s",n);getchar();
				display_Nodes(n,1);
				break;
                         case 4:printf("Thank you 4 using single link list! :)\n");
				break;
			 default:printf("Wrong Choice please re-enter!\n");
                         }//end of switch-case	
                       }//end of while loop and case 1
                       ch=0;
                      break;
              case 2:while(ch!=4){
                      ch=display_menu(2);
                     switch(ch)
                       { case 1:
                                printf("Insert The name :");n=(char *)malloc(20*sizeof(char));
                                scanf("%s",n);getchar();
				addNode_dll(n);
				break;
			 case 2:display_list(2);
				break;
			 case 3:printf("Enter The name :");n=(char *)malloc(20*sizeof(char)); 
                                scanf("%s",n);getchar();
				display_Nodes(n,2);
				break;
                         case 4:printf("Thank you 4 using Doubly link list! :)\n");
				break;
			 default:printf("Wrong Choice please re-enter!\n");
                         }//end of switch-case	
                       }//end of while loop and case 2
                      ch=0;break;
               case 3:continue;
               case 4:printf("\n \t\tThank You for using the program!\n");exit(0);break;
               default:printf("\n\t\tWRONG CHOICE ENTER AGAIN!\n");
          } //end of switch case
   }//end of while()
}//end of work()
main()
{ 
  work();
}
  
    


