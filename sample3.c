#include <stdio.h>
#include <stdlib.h>
FILE *f;
const int i=3;
#define t double
#define swap(x,y) {printf("SWAPPING\n");printf(#x" =%d\n",x);printf(#y" =%d\n",y);t temp=x;x=y;y=temp;printf(#y" =%d\n",y);printf(#x" =%d\n",x);} 
void change(int *x,int *y)
{int tmp=*x;*x=*y;*y=tmp;}
void change_address(int *x,int *y)
{int *tmp=x;x=y;y=tmp;}
main()
{
   /*checks how character streams are accessed in files in fscanf and getc dis logic can b extended to scanf and getchar
    a cursor to a datastream is not forwarded by scanf getchar does the cursor forwarding while accessing a character
   eg. char stream-> 8,9,0. scanf(%d) used twice successively yields 8 twice since cursor forwarding is not done 
      scanf(%d) getchar() scanf(%d)yields 8n9.since getchr does the forwarding of the cursor position of the char/data stream 
   */int x=5,*p,y;
   p=&x;
   printf("%d is in location %p.\n",x,p);
   printf("%p contains %d.\n",p,*p); 
   f=fopen("a","w");
   fprintf(f,"%d,%d\n%d,%d,%d,%d,%d,%d.\n",x,x+1,x+2,x+=2,x+2,x+=2,x+3,x);//right 2 left evaluation
   fclose(f);
   f=fopen("a","r");
   int *p2;char c;
   fscanf(f,"%d,%d\n",&x,&y);c=getc(f);//if nocoma btwn %d then the int is a garbage value 
   printf("%d,%d,charactr got after scanf ends%c.\n",x,y,c);
   fscanf(f,"%d\n",&x);
   printf("%d,charactr got after scanf ends%c.\n",x,c);
   fscanf(f,"%d\n",&x);c=getc(f);
   printf("%d,charactr got after scanf ends%c.\n",x,c);
   fscanf(f,"%d\n",&x);c=getc(f);
   printf("%d,charactr got after scanf ends%c.\n",x,c);
   printf("%p contains %d.\n",p2,*p2);fclose(f);  
   int *po=(int *)malloc(sizeof(po));//po->replaced as int
   po=p;printf("%p holds %d\n",po,*po);
   /*successfully checks whether pointers stored in a file can be used to refer to the original data.A bit of manipulation is required to get the desird result. note this is only possible since the program is accessing the data while executing, those memories are not freed they are still in use by the ram so we get back the data.
   apart from that pointer pointing logic is checked out too! changing p to point to something else
   //pointers are data types that store the addresses of other data types
   int x=6,y,*p,*p3;
   p=&x; f=fopen("a","w");
   fprintf(f,"%d,%p\n",x+=2,p);
   fclose(f);printf("%c\n",0);//null character printing
   f=fopen("a","r");
   void *p2;char c;//void pointers are those that cannot be deferenced!!! since they point to void which is nothing..they simply reprent memory addresses
   fscanf(f,"%d",&y);c=getc(f);
   printf("%d,charactr got after scanf ends%c.\n",y,c);
   fscanf(f,"%p",&p2);c=getc(f);x+=1;//changes in x will reflect in p,which points to x, is equal to p3 
   printf("%p,charactr got after scanf ends%c.\n",p2,c);
   c=getc(f); p3=(int *)p2;//conversion of a void pointer to a int pointer ie it points to int data type
   printf("%c,%p,%d.\n",c,p3,*p3);*p+=1;//equivalent to x+=1
   printf("%p,%d.\n",p3,*p3);
   *(p+=1);//this indic8s pointer memory adressed is incremented ie p now points to something else change in p should not affect p3. p3 points to x changes in x will reflect on p3. also p++ increments p pointer by 4 bytes since this is an int pointer and sizeof int for this machine is 4 bytes
   printf("size f int for this machine:-%d\n",sizeof(int));
   printf("%p,%d.\n",p3,*p3);printf("p->%p,%d.\n",p,*p);
   fclose(f);*/
   /*
   //checks the use of constant qualifier,how free() works
    printf("%d\n",i);int x=7,z=i;
   printf("%d\n",i);swap(z,x);f=fopen("a","w");
   printf("z=%d,x=%d!!\n",z,x);//this shows that the swap function called from the define function swaps the values permanently like call by reference
    change (&x,&z);//swaps the contents of the addresses so that address of x now contains contents of adress of y
   
    printf("z=%d its address %p,x=%d its address %p!!\n",z,&z,x,&x);
    change_address(&x,&z);//attempts to change addresses but cannot addresses cant be changed contents of addresses can!
    printf("z=%d its address %p,x=%d its address %p!!\n",z,&z,x,&x);
    int  *p=&x,*q,*s=&z;//s=&i doesnt work since const qualifier discards pointer access to it as it may so happen that it gets manipulated through the pointer use rather than it directly so to prevent this the pointer creation is discarded
   fprintf(f,"%p %p \n",p,s);
   char *n;
   printf("Enter: ");scanf("%s",n);printf("\nU entered :%s\n",n);
   //int *a,b;means *a, b are of int type.. a contains an address to an integer
   //bit-wise manipulations
   fclose(f);free(p);//free(f); 
   f=fopen("a","r");void *p2;
   fscanf(f,"%p",&p2);getc(f);
   printf("%p %d.\n",q=(int *)p2,*q);//shouldnt work corrctly as the printf evaluates right to left here 
   fscanf(f,"%p",&p2);getc(f);
   printf("%d %p.\n",*q,q=(int *)p2);//shouldnt work corrctly as the printf evaluates right to left here 
   fclose(f);
   exit(0);*/
}
