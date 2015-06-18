#include <stdio.h>
char s[]={' '};
#if defined(__unix__)||defined(__APPLE__)
//s={'a'};
int main()
{
printf("%s\n","app");
}
#endif
#if defined(__linux__)
//s={'l'};
int main()
{
printf("%s\n","linu");
}
#endif
