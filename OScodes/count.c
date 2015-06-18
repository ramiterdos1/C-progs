#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
main(int argc,char *argv[])
{
FILE *fp;
char c;
int w_c=1,l_c=1,line_c=0;
if(argc<4)
{
  if(argc>2)
{
fp=fopen(argv[2],"r");

while((c=fgetc(fp))!=EOF)
{
if(c==' ')
w_c++;
else if(c=='.')
line_c++;
else if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9'))
l_c++;
}
fclose(fp);int i;
for(i=1;i<4;i++)
 { if(argv[1][i]!=0)
   switch(argv[1][i])
   {
    case 'c' : 
              printf("Number of alphanumeric characters: %d\n",l_c-1);
              break;
    case 'w' : 
              printf("Number of words : %d\n",w_c);
              break;
    case 'l' :
              printf("Number of lines : %d\n",line_c);
              break;
    default : printf("Wrong Choice  of switch!\n");
    }else break;
 }
}//argc=3
 else
   {
    fp=stdin;
    while((c=fgetc(fp))!=EOF)
     {
    if(c==' ')
       w_c++;
    else if(c=='.')
          line_c++;
          else if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9'))
                 l_c++;
     }
    fclose(fp);
              printf("\nNumber of alphanumeric characters: %d\n",l_c-1);
              printf("Number of words : %d\n",w_c);
              printf("Number of lines : %d\n",line_c);
    
   }
}
 else printf("WRONG NUMBER OF ARGUMENTS\n");
 
}//end of main()

