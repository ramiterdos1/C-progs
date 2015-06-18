#include <stdio.h>
#include <string.h>
main()
{
      struct s{char *n; int r;};
      typedef struct s s;int i=0,j=1;
      s *sl;
      sl[0]=(s){"jagan",5};
      sl[1]=(s){"joshua",1};
      sl[2]=(s){"poka",6};
      sl[3]=(s){"polka",3};
      /*for(i=0 ;i<3;i++)
          for(j=i+1;j<=3;j++)
             if(sl[i].r>sl[j].r)
                 {
                    s temp={0,0};
                    temp=(s)sl[i];
                    sl[i]=(s)sl[j]; sl[j]=(s)temp;
                    printf("%d roll=%d",i,sl[i]);
                    printf("%d roll=%d",j,sl[j]);
                 }*/
        for(i=0;i<=3;i++) 
           printf("Roll:%d \t|\tName:%s\n",sl[i].r,(sl[i].n));
        int a[3]={7,8};   int *b;
        b=(int *)(7,9,0);//technique for writing instant arrays with pointer
           
}     
        
