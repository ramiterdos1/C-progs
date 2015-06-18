#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int main()
{
clock_t begin=clock(),end;time_t b=time(&b),e;
for(int i=1;i<1000000;i++)printf("%d\n",i);
end=clock();e=time(&e);
   printf("Processor Time taken is %f.\n",(double)((end-begin)/(double)CLOCKS_PER_SEC));
   printf("Time taken is %f.\n",difftime(e,b));
return 0;
}
