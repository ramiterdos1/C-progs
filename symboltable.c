#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 10000

char *** symb_tbl,name[100][20],type[100][20];
int m,size[100],flag_bit[100];//m->hash table sizek
int addrs,c_name,pos,a_len;
char a_name[40];
char *datatypes[]={"short","int","long","char","float","double","unsigned"};
int d_size[]={2,4,4,1,4,8,4};

char *Getline(FILE* filename)
{ char *line[MAX]
 strcpy(line,"");
 fgets(line,MAX,filename);
 return line;
}

char *copy(char *line,int pos)
{
 char s[MAX]; 
 strcpy(s,"");
 strncat(s,line,pos);
 return s;
}

int is_array(char str[])
{
   char arr_len[9];
   int i,j,k,start_pos,end_pos,flag=0;
        for(i=0;i<strlen(str);i++)
               {
                  if(str[i]=='[')
                     {
                       start_pos=i;
                       flag=1;
                      }
                   if(str[i]==']')
                     end_pos=i;
               }
         if(flag)
          {
            strcpy(a_name,copy(str,start_pos));
            k=0;
            for(j=start_pos+1;j<end_pos;j++)
               {
                  arr_len[k]=str[j]; k++;
               }
            arr_len[k]='\0';
            a_len=atoi(arr_len);
          }
    return flag;
}


void VARIABLES(int pos,char* line,char *datum)
{
 int i,k=0;
 char new_line[200],*pch,dat[60];
 strcpy(dat,datum);
 for(i=pos;i<strlen(line);i++)
     new_line[i-pos]=line[i];

 new_line[i]='\0';
 pch=strtok(new_line,"  ,=;0123456789{}");
while(pch!=NULL){
if(isdigit(pch[0])){//do nothing
}
if(isalpha(pch[0]) && is_array(pch)){
strcpy(name[c_name],a_name);
strcpy(type[c_name],dat);
size[c_name]=a_len*d_size[pos];
flag_bit[c_name]=1;
c_name++;
}

else if(isalpha(pch[0])){
strcpy(name[c_name],pch);
strcpy(type[c_name],datum);
size[c_name]=d_size[pos];
flag_bit[c_name]=0;
c_name++;
}
pch=strtok(NULL,"                ,=;");
}
return;
}



int is_data_type(char* s){
int i;
for(i=0;i<7;i++){
if(strcmp(s,datatypes[i])==0){
pos=i;
return(i+1);
}
}
return 0;
}

int NEXT_PRIME(int c){
int i,j=2;
for(i=c;;){
for(;j<i;j++){
if(i%j==0){
i++;
j=2;
}
}
return i;
}
}

int COMPUTE_KEY(char *s)
{
  int i,value=0,d;
  for(i=0;i<strlen(s);i++)
  {
    d=(int)s[i];
    value=value*10+d;
  }
  return value;
}
//xxxx

int H1(char* s)
{
  return(COMPUTE_KEY(s)%m);
}

int H2(char* s)
{
return (1+(COMPUTE_KEY(s)%(m-1)));
}

int GENERATE_KEY(char *s,int i)
{
   return (H1(s)+i*H2(s))%m;
}

void HASH_INSERT(char* s,int index){
int i=0,j,k,SIZE,p;
char buffer[20],TYPE[40],buffer1[10],buffer2[10];
do{
j=GENERATE_KEY(s,i);
if(strcmp(symb_tbl[0][j]," ")==0)
{
   for(k=0;k<c_name;k++)
      {
        if(strcmp(s,name[k])==0)
            {
              strcpy(TYPE,type[k]);
               SIZE=size[k];
                p=k;
            }
       }
if(!flag_bit[p]){
sprintf(buffer1,"%d",addrs);
addrs=addrs+SIZE;
sprintf(buffer,"%d",SIZE);
strcpy(symb_tbl[0][j],s);
strcpy(symb_tbl[1][j],TYPE);
strcpy(symb_tbl[2][j],buffer);
strcpy(symb_tbl[3][j],buffer1);
}
else{
     sprintf(buffer1,"%d",addrs);
     addrs=addrs+SIZE;
     sprintf(buffer2,"%d",addrs);
     sprintf(buffer,"%d",SIZE);
     strcpy(symb_tbl[0][j],s);
     strcpy(symb_tbl[1][j],TYPE);
     strcpy(symb_tbl[2][j],buffer);
     strcpy(symb_tbl[4][j],buffer1);
     strcpy(symb_tbl[5][j],buffer2);
     }
return;
}
else i++;
}while(i<=m);
printf("HASH TABLE OVERFLOW");
return;
}

void HASH_SEARCH(char *su){
int i=0,j,k=0;
char s[100];
while(k<strlen(su)-1){
s[k]=su[k];
k++;
}
s[k]='\0';
do{
j=GENERATE_KEY(s,i);
if(strcmp(symb_tbl[0][j],s)==0)
{
  printf("Symbol %s is present in SYMBOL TABLE at %d position\n",s,j);
  return;
}
else i++;
}while((strcmp(symb_tbl[0][j]," ")!=0) && (i<=m));
printf("Symbol %s is not present in SYMBOL TABLE\n",s);
return;
}



int main(int argc,char* argv[])
{
 FILE *fp;
 int i,pos,j;
 char* data_type_name,*line;
 char COPY[100];
 addrs=0;
 if(argc!=3)
 {
 printf("WRONG FORMAT!\n");
 exit(1);
 }
 c_name=0;
 if((fp=fopen(argv[1],"r+"))==NULL)
    printf("CANT open file\n");


while(!feof(fp))
{
line=Getline(fp);
pos=0;
if(strlen(line)>=1)
{
  i=0;
  while((line[i]!=' ')&&(i<=strlen(line)))
     { pos++;i++;}
//checks data type or not..if data type then the variables extracted
 data_type_name=copy(line,pos);
 if(is_data_type(data_type_name))
   {
     VARIABLES(strlen(data_type_name)+1,line,data_type_name);
   }
}
}
  printf("\n%20sEXTRACTING COMPLETE\n\n\n"," ");
  m=NEXT_PRIME(c_name);
symb_tbl=(char ***)malloc(6*sizeof(char**));
for(i=0;i<6;i++){
symb_tbl[i]=(char **)malloc(m*sizeof(char*));
}
for(i=0;i<6;i++){
for(j=0;j<m;j++){
symb_tbl[i][j]=(char *)malloc(20*sizeof(char));
}
}

for(i=0;i<6;i++){
for(j=0;j<m;j++){
strcpy(symb_tbl[i][j]," ");
}
}

for(i=0;i<c_name;i++)
  HASH_INSERT(name[i],i);

printf("%20sSYMBOL TABLE\n"," ");
printf("%10s   %10s  %10s   %10s","INDEX","NAME","TYPE","SIZE"\n");
for(j=0;j<m;j++)
          printf("\n%10d	%10s	%10s	%10s\n",j,symb_tbl[0][j],symb_tbl[1][j],symb_tbl[2][j]);



printf("All the symbols are succesfully hashed\n");
fclose(fp);
fp=fopen(argv[2],"r+");
while(!feof(fp))
{
 line=Getline(fp);
 i=0;
  while(line[i]!='\n')
   {
     COPY[i]=line[i];
      i++;
   }
 COPY[i]='\0';
if(isalpha(COPY[0]))
  HASH_SEARCH(COPY);
}
}

