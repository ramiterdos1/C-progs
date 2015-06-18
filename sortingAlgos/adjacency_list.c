#include<stdio.h>
#include<stdlib.h>
struct graph{
 int vertex;
struct graph *next;
};

struct adj_list{
int vertex;
struct graph *next;
};




void addnode(struct adj_list* t,int data){
struct graph *p,*q; 
p=(struct graph*)malloc(sizeof(struct graph));
p->vertex=data;
p->next=NULL;
if(t->next==NULL){
t->next=p;
return;
}
else{
q=t->next;
while(q->next!=NULL)
q=q->next;
q->next=p;
return;
}
}
//not repeating same entered vertex
int chk_vertex_exist(struct adj_list *t[],int ver,int n)
{
int i;
for(i=0;i<n;i++)
{
if(t[i]->vertex==ver)return 1;
}
return 0;
}


int main()
{
printf("%50s\n","*******************Displaying the transpose of a graph*********************");
int ver,n,i,j;
struct graph *q;
struct adj_list* HEAD[20];
struct adj_list* HEAD_Trans[20];
printf("Enter the number of vertices:\n");
scanf("%d",&n);
printf("Enter the vertices of the graph:\n");
for(i=0;i<n;i++)
{
HEAD[i]=(struct adj_list *)malloc(sizeof(struct adj_list));
scanf("%d",&HEAD[i]->vertex);
HEAD[i]->next=NULL;
}
for(i=0;i<n;i++)
{
printf("Enter the vertices directed from  vertex %d(enter 0 to stop):\n",HEAD[i]->vertex);
scanf("%d",&ver);
while(ver)
{
if(chk_vertex_exist(HEAD,ver,n)){
addnode(HEAD[i],ver);
}
else printf("wrong input\n");
scanf("%d",&ver);
}
}
printf("The ADJACENCY LIST of the graph entered\n");

for(i=0;i<n;i++){
q=HEAD[i]->next;
printf("%3d :",HEAD[i]->vertex);
while(q!=NULL){
printf(" %3d ",q->vertex);
q=q->next;
}
printf("\n");
}
printf("\n");
//allocating memory for transpose of a graph
for(i=0;i<n;i++){
HEAD_Trans[i]=(struct adj_list *)malloc(sizeof(struct adj_list));
HEAD_Trans[i]->vertex=HEAD[i]->vertex;
HEAD_Trans[i]->next=NULL;
}

//transposing the graph
for(i=0;i<n;i++){
q=HEAD[i]->next;
ver=HEAD[i]->vertex;
while(q!=NULL){
j=0;
while(q->vertex!=HEAD_Trans[j]->vertex){j++;}
addnode(HEAD_Trans[j],ver);
q=q->next;
}
}

printf("\t\tTRANSPOSED ADJACENCY LIST\n");

for(i=0;i<n;i++){
q=HEAD_Trans[i]->next;
printf("%3d :",HEAD_Trans[i]->vertex);
while(q!=NULL){
printf(" %3d ",q->vertex);
q=q->next;
}
printf("\n");
}
printf("\n");
for(i=0;i<n;i++){
free(HEAD[i]);
free(HEAD_Trans[i]);
}
}
