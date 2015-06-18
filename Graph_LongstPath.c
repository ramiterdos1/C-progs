//
//  Graph_LongstPath.c
//  calculates the longest path between any two vertices of the Graph
//  
//  Created by Ramit on 25/05/13.
//
//

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
long int max(long, long);
long int sum(long, long);
void DFS(long int *m[],int r, int c);
void DFS_print(long int *m[],int * visited,int V,int v);
void BFS(long int *m[],int r, int c);
void BFS_print(long int *m[],int * visited,int V,int v);

long int neg_inf=LONG_MIN;
long int max(long int a,long int b)
{
    return (a>=b)?a:b;
}
long int sum(long int a,long int b)
{
    long int sum=0;
    if(a==neg_inf || b==neg_inf)
        sum=neg_inf;
    else sum=a+b;
    return sum;
}
void DFS(long int *m[],int r, int c)
{
int V=r,i=0,j=0;
int *visited=(int *)malloc(sizeof(int)*V);
while(i<V)
visited[i++]=0;
visited[0]=1;
printf("The DFS through the Graph\n1-");
DFS_print( m,visited,V,0);
printf("\n");
while(i<V)
if(visited[i++]!=1)
   {printf("DISCONNECTED GRAPH!\n");break;}
if(i==V)printf("CONNECTED GRAPH!\n");
}
void BFS(long int *m[],int r, int c)
{
int V=r,i=0,j=0;
int *visited=(int *)malloc(sizeof(int)*V);
while(i<V)
visited[i++]=0;
visited[0]=1;
printf("The BFS through the Graph\n1-");
BFS_print(m, visited, V,0);
printf("\n");
while(i<V)
if(visited[i++]!=1)
   {printf("DISCONNECTED GRAPH!\n");break;}
if(i==V)printf("CONNECTED GRAPH!\n");
}
void BFS_print(long int *m[],int * visited,int V,int v)
{
  int i=0,j=0;
  for(i=0;i<V;i++)
     if(visited[i]==0)break;
  if(i!=V)
  {   

  for(i=0;i<V;i++)
    { if(m[v][i]==1 && visited[i]!=1 && i!=v)
        {
             printf("%d.",i+1);
             
         }
       
     } printf("-");
   for(i=0;i<V;i++)
     if(m[v][i]==1 && visited[i]!=1 && i!=v)
        {
            visited[i]=1;
            BFS_print(m,visited,V,i);
            
        }
        
    }
}

void DFS_print(long int *m[],int * visited,int V,int v)
{

  int i=0,j=0;
  for(i=0;i<V;i++)
     if(visited[i]==0)break;
  if(i!=V)
  {   
  for(i=0;i<V;i++)
    { if(m[v][i]==1 && visited[i]!=1 && i!=v)
        {
             printf("%d-",i+1);
             visited[i]=1;
             DFS_print(m,visited,V,i);
        }
        
     }if(i==V)printf(".");
   }
}
void printTable(long int *M[],int r, int c)
{  
    int i=0,j=0;
    printf("\n\n\n%5s\t"," ");
    for(i=0;i<r;i++)
    {
        printf("%5d\t",i+1);
    }
    for(i=0;i<r;i++)
        {
            printf("\n%5d\t",i+1);
          for(j=0;j<c;j++)
              printf("%5ld\t",M[i][j]==neg_inf?0:M[i][j]);
        }
    printf("\n");
    
}

int main()
{
    printf("signed long max :%ld\n",LONG_MAX);
    printf("signed long min :%ld\n",LONG_MIN);
    printf("signed int max :%d...%d\n",INT_MAX,INT_MAX+1);
    printf("signed int min :%d..%x\n",INT_MIN,INT_MIN);
    long int neg_inf=LONG_MIN;int V=0,i=0,j=0,k=0,s=0,t=0;
    printf("How many vertices does the graph have?\n");
    scanf("%d",&V);getchar();
    //declaration
    long int **M;//printf("%d\n",V);
    M=(long int **)malloc(sizeof(void *)*V);
    for(i=0;i<V;i++)
        M[i]=(long int *)malloc(sizeof(long int)*V);
    //initializing the array
    for(i=0;i<V;i++)
        for(j=0;j<V;j++)
            M[i][j]=neg_inf;
    //taking input weights
    for(i=0;i<V;i++)
        {
            char c='y';
            while(c=='y'|| c=='Y')
                {
                    printf("Is the vertex %d connected to another vertex?(Y/N):",i+1);
                    c=getchar();getchar();//printf("here %c\n",c);
                    if(c=='y'||c=='Y')
                        {
                            printf("\nEnter the Vertex to which Vertex-%d is connected and its edge weight\n",i+1);
                            int edge_wt=0,oth_vrtx=0;
                            scanf("%d %d",&oth_vrtx,&edge_wt);getchar();
                            M[i][--oth_vrtx]=edge_wt;
                            M[oth_vrtx][i]=edge_wt;
                        }
                    }
        }
    printTable(M,V,V);

    //other ways to print the graph!
    DFS(M,V,V);
    BFS(M,V,V);

    printf("\nBetween which two vertices do you wish to see the longest distance?\n");
    
    scanf("%d %d",&s,&t);s--;t--;getchar();
    for(i=0;i<V;i++)
        for(j=0;j<V;j++)
            {
                if(j==i)continue;
                for(k=j+1;k<V;k++)
                    {
                      if(k==i || k==j)continue;  
                      M[i][j]=max(sum(M[i][k],M[k][j]),M[i][j]);
                      M[j][i]=M[i][j];
                    }
                }
    /*
    //changing all neg_infinities to 0
    for(i=0;i<V;i++)
        for(j=i;j<V;j++)
            if(M[i][j]==neg_inf)M[i][j]=0;
    /*char prt[100000]; have 2 learn the use of variadic functions
    prt[0]='%';prt[1]='5';prt[2]='s';//prt[3]='5';prt[1]='5';
    printf("%5s\t%5d\t"," ")
    printf("\n\n\n%5s\t"," ");
    for(i=0;i<V;i++)
    {
        printf("%5d\t",i+1);
    }
    for(i=0;i<V;i++)
        {
            printf("\n%5d\t",i+1);
          for(j=0;j<V;j++)
              printf("%5ld\t",M[i][j]);
        }*/
        printTable(M,V,V);
        
    printf("\n\nThe longest distance between the two vertices - V-%d and V-%d is %ld.\n",s+1,t+1,M[s][t]);
}
