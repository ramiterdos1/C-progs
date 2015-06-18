#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000


char line[MAX];


char *Get_line(FILE *file)
{
 strcpy(line,"");
 fgets(line,MAX,file);
 return line;
}


char *data(char *line1,int pos)
{
 char *data_type1;
 strcpy(data_type,"");
 strncat(data_type,line,pos);
 retrun data_type1;
}


int STORE(char *line1,int pos)                                            //.......................INCOMPLETE.........................//
{
 int i;
 char ver[200];
 
 for(i=pos;i<strlen(line1);i++)
  ver_list[i-pos]=line[1];
  ver_list[i]='\0';
 
 ver=strtok(ver_list,",=;");
 if(isdigit(ver) && !isalpha(ver))
  {
   //............DO NOP..........//
  }
 else
  {
   
  }
 while(ver!=NULL)
  {
   ver=strtok(NULL,",=;");
  if(isdigit(ver) && !isalpha(ver))
  {
   //............DO NOP..........//
  }
  else
  {
  
  }
         
  }
}

     
main()
{
 int pos=0;
 char *arg,line1[MAX];
 FILE *fp;

 printf("\nWelcome.\nEnter the file name.");
 scanf("%s",arg);
 
 fp=fopen(arg,"r+");
 
 
 while(!feof(fp))
 {
  line1=Get_line(fp);
  
  while(line1[i]!=' ')  
  {
   i++;
   pos++;
  }
  
  data_type=data(line1,pos);
  
  

  int m=0;
  if((m=CHECK(data_type))==0)                                     //......................CHECK IF THE DATA TYPE IS PRESENT IN THE LIST......................//
   printf("\nError!! Unknown Datatype.");
  else
   {
    STORE(pos+1,line1);                                           //......................STORE THE VARIABLES OF THAT TYPE IN THE ARRAY.....................//
    
     
    





























































































