#include <stdio.h>
#include <stdlib.h>
#define max(a,b) ((a>b) ? a : b)
struct node
{
int data;
struct node *lchild, *rchild;
};
//LL insertion
struct node *LL(struct node *pivot)
{
struct node *aptr;
aptr=pivot->lchild;
pivot->lchild=aptr->rchild;
aptr->rchild=pivot;
pivot=aptr;
return pivot;
} 
//RR insertion
struct node *RR(struct node *pivot)
{
struct node *aptr;
aptr=pivot->rchild;
pivot->rchild=aptr->lchild;
aptr->lchild=pivot;
pivot=aptr;
return pivot;
}
//LR insertion
struct node  *LR(struct node *pivot)
{
pivot->lchild=RR(pivot->lchild);
pivot=LL(pivot);
return pivot;
}
//RL insertion
struct node  *RL(struct node *pivot)
{
pivot->rchild=LL(pivot->rchild);
pivot=RR(pivot);
return pivot;
}
//calculate height
int height(struct node *root)
{
if(root==NULL)
return 0;
else
return max(height(root->lchild),height(root->rchild))+1;
}
//calculate balance factor
int get_balance(struct node *root)
{
return (height(root->lchild)-height(root->rchild));
}
//balance the tree
struct node *balance(struct node *root)
{
int bl=get_balance(root);
if(bl==2)
{
if((get_balance(root->lchild))>0)
root=LL(root);
else
root=LR(root);
}
else if(bl==-2)
{
if((get_balance(root->rchild))<0)
root=RR(root);
else
root=RL(root);
}
return root;
}
//insertion of unique elements
void insert(struct node **root, int key)
{
struct node *p;
if(*root==NULL)
{
p=(struct node *)malloc(sizeof(struct node));
p->data=key;
p->lchild=NULL;
p->rchild=NULL;
*root=p;
}
else if(key<(*root)->data)
{
insert(&((*root)->lchild),key);
*root=balance(*root);
}
else if(key>(*root)->data)
{
insert(&((*root)->rchild),key);
*root=balance(*root);
}
else
printf("Sorry, duplicate number\n");
return;
}
//Display Preorder
void display(struct node *root)
{
    printf("How Do you wish to display?\n1.Preorder\n2.Postorder\n3.Inorder\n");
    char c=getchar();getchar();
    switch(c)
     {
      case '1':
	if(root!=NULL)
	{
	printf("%d\t",root->data);
	 display(root->lchild);
	display(root->rchild);
        }
       break;
      case '2':
	if(root!=NULL)
	{
	 display(root->lchild);
	 display(root->rchild);
	 printf("%d\t",root->data);
        }
       break;
      case '3':
	if(root!=NULL)
	{
	 display(root->lchild);
         printf("%d\t",root->data);
	 display(root->rchild);
        }
       break;
      default: printf("Wrong Choice of Input!\n"); 
       }
     return;
}

int main()
{
struct node *head=NULL;
int ch,key;
while(1)
{
printf("Press 1 for Insert\nPress 2 for Display\nPress any other integer to Exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\nEnter the number: ");
scanf("%d",&key);
insert(&head,key);
break;
case 2:
display(head);
printf("\n");
break;
default:
exit(1);
}
}
}
		

