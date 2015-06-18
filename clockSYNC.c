#include <stdio.h>
#include <stdlib.h>
//displays the times when the hour hand equals the minute hand!
int main()
{
int i=1;
printf("displays the times when the hour hand equals the minute hand!\n00:00\n");
for(;i<11;i++)
printf("%2d:%2d{%2d/11}\n",i,(60*i)/11,(60*i)%11);
printf("12:00\n");
return 0;
}