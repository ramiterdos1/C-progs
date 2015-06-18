#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main()
{
char c[1000];int i=0,countr=0;char cand;
printf("Enter a sequence of alphabets\n");
scanf("%s\n",c);
getchar();
for(i=0;i<strlen(c);i++)
 {
  if(countr==0){countr=1;cand=c[i];}
  else {
      if(c[i]==cand)countr++;
      else countr--; 
    }
  }
 printf("%d\n",strlen(c));
 countr=0; 
 for(i=0;i<strlen(c);i++)
    {
       if(c[i]==cand)countr++;
    }
 if(countr>(strlen(c)>>1))
  printf("Majority Elem: %c\n",cand);
else printf("NO Maj Elem!\n");
}
