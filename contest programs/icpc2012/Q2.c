#include <stdlib>
#include <time>
#include <stdio>
#include <math>
#include <cstring>
#include <cstdio>
#define ModNum 1000000007
int a[1000];
extern int getchar_unlocked(void);
extern int putchar_unlocked(int c);
int inpint();
long long inplong();
inline int inpint()
{
int noRead=0;
char p=getchar_unlocked();
for(;p<33;){p=getchar_unlocked();};
while(p>32)
{
noRead = (noRead << 3) + (noRead << 1) + (p - '0');
p=getchar_unlocked();
}
return noRead;
}
inline long long inplong()
{
long long noRead=0;
char p=getchar_unlocked();
for(;p<33;){p=getchar_unlocked();};
while(p>32)
{
noRead = (noRead << 3) + (noRead << 1) + (p - '0');
p=getchar_unlocked();
}
return noRead;
}

int main()
{
 int T,i,j,k;size_t max=1000;
char* tok_1;
 for(T=inpint();T>0;T--)
     { int N=inpint(),L=inpint(),H=inpint(); int count=0;

    getline(a,&max,stdin);
    
    tok_1 = strtok(a," ");

    for(i=0;tok_1;i++) {
        first_moves[i] = atoi(tok_1); 
        tok_1 = strtok(NULL," ");
}
   for(i=0;i<N-2;i++){
     for(j=i+1;j<N-1;j++){
       for(k=j+1;k<N;k++){
          int sum=a[i]+a[j]+a[k];    
         if((sum>=L && sum <=H  )
         count++;    
     }
       } }printf("%d\n",count);
    
}}
