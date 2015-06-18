#include <stdio.h>
int stcmp(char *s, char *t);
int lngt(char *s);
char *rev(char *s);
char *rev(char *s)
{
     char *t=(char *)malloc(lngt(s)*sizeof (char));int i=lngt(s)-1,j=0;
     for(t[j]=s[i];i>=0;i--,j++)t[j]=s[i];
     return t;
}
int lngt(char *s)
  {
     int len=0;
     while(*(s++))len++;
     return len;
  }
int stcmp(char *s, char *t)
{
    for(;*s==*t;s++,t++)
        if(*s==0)return 0;
    return *s-*t;
}
    
main(int argc,char *argv[])
{
   int i=0,j=0,cnt=0;
   for(;i<argc;i++)
       printf("(%d)\t%s\tlength=%d\titz addrs-%u\n",i+1,argv[i],lngt(argv[i]),(argv+i));
   for(i=1;i<argc-1;i++)
       for(j=i+1;j<=argc-1;j++)
           if(stcmp(argv[i],argv[j])>0)
              {char *tmp=argv[j];argv[j]=argv[i];argv[i]=tmp;}
                   
   for(i=0;i<argc;i++)
       printf("(%d)%s-%u\n",i,argv[i],(argv+i));
     for(i=0;i<argc;i++)
       printf("(%d)\t%s\titz rvrs-%s.. kpt at adrs\n",i,argv[i],(char *)rev(argv[i]));//rev(argv[i]));
     
     
}    
