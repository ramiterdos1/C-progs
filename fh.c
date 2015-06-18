#include <stdio.h>
main()
{
      FILE *fp,*fp2;int c;char *f;
      fp=fopen("fh.c","r");
      f=(char *)malloc(100*sizeof(char));
      if(fp==NULL)
         printf("No such file exists!! :(");
      else   while((c=getc(fp))!=EOF)
                  putc(c,stdout);
      fclose(fp);
      printf("Enter the name of the file u wish to open!");
      scanf("%s",f);
      fp2=fopen(f,"r");
      
      if(fp2==NULL)
         printf("can't open %s!! :(",f);
      else   while((c=getc(fp))!=EOF)
                  putc(c,stdout);
      fclose(fp2);
}                  
