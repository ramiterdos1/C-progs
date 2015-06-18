#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
int main(int argc,char *argv[])
{
 if(argc!=3)
   {printf("Wrong No of Arguments!\n");
   }
else{
 void *f=malloc(sizeof(void));
  FILE *fp1,*fp2;
 fp1=fopen(argv[1],"r");
 fp2=fopen(argv[2],"w");
 int i=0,j;
 //printf("%s----%s\n",argv[1],argv[2]);
 while(j!=EOF)
   {
    /*fread(f,sizeof(void),1,fp1);
    fwrite(f,sizeof(void),1,fp2);
    printf("%d\n",i++);
    getchar();
   
   */  putc((j=getc(fp1)),fp2);
 //   printf("%d\n",i++);
   }
   fclose(fp1);fclose(fp2);
   chmod(argv[2],00711);
   printf("Done!\n");
  }
}
