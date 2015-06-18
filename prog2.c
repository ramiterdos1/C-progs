#include <stdio.h>
typedef struct data {int roll; char *name;}d;
d getd();
d getd()
{       struct data d1;
        char *n=(char *)malloc(10*sizeof(char));int r=0;
        printf("Enter the roll number:");
        scanf("%d",&r);d1.roll=r; r=0;
        printf("Enter the name:");
        //while((n[r++]=getchar())!='\n')
        scanf("%s",n);
        d1.name=n;
        return d1;
}        
main()
{
      char c; int n=0,*p=(int *)malloc(sizeof(int)),z,*s;
      printf("Enter an integer,or press e to exit!\n");
      while((c=getchar())!='e')
      {
          z=(int)(c-'0');
          p[n++]=z;
          //n++;
          getchar();
          }
       printf("Entered nos in ascending order r as follows:");z=0;printf("1.\n");n-=1;
       while((n)>=z){ printf("%d,",p[z]);z++;} printf("\n2.\n");
       s=p; s[1]=6;int i=0,j;
       for(;i<z;i++)
          for(j=i+1;j<=z;j++)
              if(p[i]<p[j]){p[i]=p[i]^p[j];p[j]=p[i]^p[j];p[i]=p[i]^p[j];}
       printf("Entered nos in descending order r as follows:");
       while((z--)>=0) {printf("p%d->%d\t",z,*(p+z));   printf("s%d->%d\n",z,*(s+z)); }
       
        struct data *list=(d *)malloc(3*sizeof(d));int size=0;c='Y';
        do
           {
              printf("Do u want to enter the data:(Y/N)");c=getchar();
              getchar();printf("%c",c);
              list[size++]=(d)getd();
           } while(c=='Y');
        //int i=0,j;   
        for(i=0 ;i<size;i++)
           for(j=i+1;j<=size;j++)
               if(list[i].roll>list[j].roll)
                 {
                    struct data temp;
                    list[i]=temp;
                    list[i]=list[j]; list[j]=temp;
                 }  
        for(i=0;i<=size;i++) 
           printf("Roll:%d \t|\tName:%s",list[i].roll,(list[i].name));
                          
}// end of main()       
      
