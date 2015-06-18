#include "Editor.c"
void create_account(usr a)
{
   extern int usr_cnt;extern usr usrs;extern Qunewz qn;
   if(usr_cnt==0){usrs=(usr)malloc((usr_cnt+1)*sizeof(*usr));a->head=qn->head;usrs[usr_cnt]=a;usr_cnt++;}
   else {usrs=(usr)realloc((void *)usrs,(usr_cnt+1)*sizeof(*usr));usrs[usr_cnt]=a;usr_cnt++;}
}
void update(int d,int m,int y)
{
  extern Qunewz qn;
}
void display_news(int indx_of_usr)
{
 extern Qunewz qn;extern usr usrs;int i=indx_of_usr;char ch='';
  
}
 
void login(char *n)
{
 extern int usr_cnt;extern usr usrs;extern Qunewz qn;int i=0,d,m,y;
  for( ;i<usr_cnt;i++)
     if(strcmp(usrs[i].name,n)==0)
        {printf("\n\nWELCOME %s!\n",n);
         printf("ENTER THE DATE FROM WHICH YOU WISH TO SEE THE NEWS IN (DD/MM/YYYY)\n");
         scanf("%d/%d/%d",d,m,y);getchar();update(d,m,y);display_news(i);
         }
  if(i==usr_cnt)printf("\n\nYOU AREN'T REGISTERED YET! PLZ CREATE YOUR USER ACCOUNT!!\n");
}//end of login()
    
