#include <stdio.h>
main()
{
  int i=1,max,freq[10]={0,0,0,0,0,0,0,0,0,0};char c;//intializations
  printf("Enter a string of numbers:(fullstop 2 end)\n");
  while((c=getchar())!='.')
    //printf("%c",c);
    freq[c-'0']++;
   max=freq[0];
  for(;i<10;i++)
      //printf("The frequency of %d is %d.\n",i,freq[i]);
        if(max<freq[i])
          max=freq[i];   
        //printf("max=%d\n",max);
        
   printf("\t\t\t     Frequency Histogram\n");
   
   while(max>0)
    { for(i=0;i<10;i++) 
         /*if(freq[i]-max<0)
             c=' ';
           else c='^';*/
           printf("%c \t",(freq[i]-max<0)?' ':177);
       printf("\n");max--;
     }//end of while() 
    for(i=0;i<10;i++)
        printf("%d \t",i);
    printf("\n");
}  
