#include <stdlib.h>
#include <stdio.h>
typedef struct newsNode{
   int day,month,year;
   char *news[5]; 
    /* news characterised by date and 5 different category of news
       namely Politics,Technology,Sports,International,Entertainment
    */
   }News;
typedef struct Queuenode{News n;struct Queuenode *nxt;}Q_nd;
typedef struct newsQueue{
  Q_nd *head; Q_nd *tail;}Qunewz;
typedef usernode{
   char *name; int pref1,pref2,pref3; Q head;}*usr;
usr usrs;
Qunewz *qn=(Qunewz *)malloc(sizeof(Qunewz));
int usr_cnt=0;


