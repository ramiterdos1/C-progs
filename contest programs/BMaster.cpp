#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define hash(i,k) ((i+k)%103)
#define bounds(i,j,M,N) (((i+j)-2)<=((N+M)-2))

extern int getchar_unlocked(void);
extern int putchar_unlocked(int c);
extern size_t strlen(const char *s);
unsigned long inp();
void mirror(unsigned long A[35][35],unsigned long N,unsigned long M,int img);
int Search(long val,unsigned long SearchArray[],int Alength);
int NoOfImg(unsigned long A[35][35],unsigned long N,unsigned long M);
struct Coordinate{int i;int j;};
//u,d,l,r
enum Dir{U=1,D,L,R};
unsigned long P[7][3];
int X[6][3]={{0,U,D},{0,L,R},{0,U,R},{0,R,D},{0,D,L},{0,L,U}};
Coordinate list_2chk[35];
  
inline unsigned long inp()
{
unsigned long noRead=0;
char p=getchar_unlocked();
for(;p<33;){p=getchar_unlocked();};
while(p>32)
{
noRead = (noRead << 3) + (noRead << 1) + (p - '0');
p=getchar_unlocked();
}
return noRead;
}
inline int NoOfImg(unsigned long A[35][35],unsigned long N,unsigned long M)
{
 unsigned long i=1,j=1;int count=0;
  for(i=1;i<=N;i++)for(j=1;j<=M;j++)
      if(A[i][j]&1)
        {
           list_2chk[count].i=i;list_2chk[count].j=j;
           count ++;
        }
  return count;
}

void mirror(unsigned long A[35][35],unsigned long N,unsigned long M,int img)
{//xxxx
  
  int sum_r[35],sum_c[35],m=0,i=0;
  for(;i<35;i++)sum_r[i]=sum_c[i]=0;
    
  for(m=0;m<img;m++)
    {    unsigned long k,l,n;
         //1s in cross of (i,j)
         int i=list_2chk[m].i,j=list_2chk[m].j;  
         
         if(A[i][j])
         {
         for(k=1;k<=M;k++)if(A[i][k])sum_r[i]++;
         for(k=1;k<=N;k++)if(A[k][j])sum_c[j]++;
         unsigned int x=(sum_r[i]+sum_c[j]-1)%6;//union
         unsigned int I=0,J=0;

         for(k=1;k<3;k++)
         { 
          I=i;J=j;
          printf("%u...X[%u][%lu]=%d..I=%u..J=%u\n",x,x,k,X[x][k],I,J); 
         
          switch(X[x][k])
          {  
             case 1:while(1){I=I-P[x][1];
                              if(I>=1)A[I][J]=(A[I][J]+1)&1;
                              else break;
                            }
                                            break;
             case 2:while(1){I=I+P[x][1];
                            if(I<=N)A[I][J]=(A[I][J]+1)&1;
                              else break;
                            }
                            break;
             case 3:while(1){J=J-P[x][1];
                               if(J>=1)A[I][J]=(A[I][J]+1)&1;
                              else break;
                            }
                                            break;
             case 4:while(1){J=J+P[x][1];
                             if(J<=M)A[I][J]=(A[I][J]+1)&1;
                              else break;
                            }
                                            break;
          };
          for(l=1;l<=N;l++){for(n=1;n<=M;n++)printf("%lu ",A[l][n]);printf("\n");}
      
         } 
       }       
    }
}
int main()
{
 //long T=inp(),ouput[Tmax],i=1;
 //n--rows,m--col..Q--queries,Q-mx=maxSizeof 
 unsigned long N=inp(),M=inp(),Q=inp(),Qmax=0,i=1;
 unsigned long Sx=inp(),Sy=inp();//starting pos
 
   for(i=0;i<6;i++){P[i][1]=inp();P[i][2]=inp();}
 unsigned long Queray[102];long HashQ[103][2];//query array
   for(i=0;i<103;i++)HashQ[i][0]=-1;
   for(i=1;i<=Q;i++){Queray[i]=inp();
                     HashQ[hash(Queray[i],0)][0]=Queray[i];
                     HashQ[hash(Queray[i],0)][1]=i;  
                     if(Queray[i]>Qmax)Qmax=Queray[i];
                    }
 unsigned long Grid[35][35],j=1;
  for(i=1;i<=N;i++)for(j=1;j<=M;j++)Grid[i][j]=0;
  Grid[Sx][Sy]=1;//starting point 
  unsigned long find=0,C=1,output[101];int tmp=0;
   tmp=NoOfImg(Grid,N,M);
  for(i=1;i<=Qmax;i++)
     {
      mirror(Grid,N,M,tmp);
        
      tmp=NoOfImg(Grid,N,M);
      C+=tmp;
      printf("C=%lu\n",C);
      if(HashQ[hash(i,0)][0]==i)output[HashQ[hash(i,0)][1]]=C;
      }
 for(i=1;i<=Q;i++)
   printf("%lu\n",output[i]); 
  exit(0);
}
