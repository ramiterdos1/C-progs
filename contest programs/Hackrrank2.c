#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define max(a,b) (((a)>(b))?a:b)
#define min(a,b) (((a)<(b))?a:b)
int start_moves[3]={0,1,21};
int calculate_bid(int player,int pos,int* first_moves,int* second_moves) {
    //Your logic to be put here
     
     int i=0,draw=0,amt_spnt1=0,amt_spnt2=0,f=0,m=0,my_mony_diff=100,r=0,p=0,diff=0;
     int op_mony_diff=100,o_amt=0,o_lmv=0,o_pos=0,oppo=0,val=0;//opponent amount, opponent last move
     
    int *me,*op;
     if(player&1){f=0;me=first_moves;op=second_moves;}
      else {f=10;op=first_moves;me=second_moves;}
    while(*(first_moves+i)!=0)
    {
      amt_spnt1+=(me[i]>op[i])?me[i]:0;
      amt_spnt2+=(me[i]<op[i])?op[i]:0;
      if(me[i]==op[i])
         {
           draw++;
           if((draw&1)==(player&1))amt_spnt1+=me[i];
           else amt_spnt2+=op[i];
          }
       
       // printf("player-%d amt spnt =%d.... oppnt");
       i++; diff+=(op[i-1]-op[i]);
     }
     
     f=f==0?pos:10-pos;
     my_mony_diff-=(2*amt_spnt1-amt_spnt2);
     op_mony_diff-=(2*amt_spnt2-amt_spnt1);
     m=100-amt_spnt1;
     o_amt=100-amt_spnt2; 
     o_lmv=op[i-1];
     o_pos=10-f;
     oppo=(op_mony_diff<=10)?(o_amt/o_pos):(op_mony_diff/o_pos);
     p=(my_mony_diff<=10)?(m/f):(my_mony_diff/f);
     val=i%10+1;

    if(f>=2&&f<8 && i>0)
    { 
     
      if(m==o_amt)
        {   if((player&1)==((draw+1)&1))val=(i>6)?min(o_lmv,p)+1:min(o_lmv,p)-1;
             else {if(player&1)val=(diff==0)?o_lmv+1:min(o_lmv,p);//+1-p2
                   else val=(diff==0)?o_lmv+1:min(o_lmv,p)-1;
                  }
         }
      else {if(m>(o_amt+5) || f>3){if(p<oppo)val=(diff==0)?o_lmv+1:min(o_lmv,p);
                                else   val=(diff==0)?o_lmv+1:min(min(o_lmv,12+i/10),oppo)+i%2;//o_lmv chk can b used
                              }
            else val=1; 
           }
      
    }
    else if(f>=8)
          {
            if(m>oppo)
               { if((player&1)==((draw+1)&1))val=oppo;
                else val=oppo+1;
                }
            else if(m>=o_amt)val=min(o_lmv,((o_amt/o_pos)+1));
            else val=(diff==0)?o_lmv+1:min(m,((o_amt/o_pos)+1));  
            }
     else if(f<2)
             { 
               if(m>(o_amt+8))
                {if((player&1)==((draw+1)&1))val=oppo;
                 else val=p;
                }
               else val=2; 
              }
    
    if(val<=0)val=1;
    if(m<=0)val=0;
    else if(m<val)val=rand()%m+1;
    return (val);
}
int main() {

    int player;                                          //1 if first player 2 if second
    int scotch_pos;                                      //position of the scotch 
    int bid;                                             //Amount bid by the players
    size_t buf_limit = 500;
    char *first_move = (char *) malloc(buf_limit);      //previous bids of the first player
    char *second_move = (char *) malloc(buf_limit);     //prevous bids of the second player
    char *remove_new_line = (char *) malloc(2);
    char *tok_1,*tok_2;
    int first_moves[100] = {0};
    int second_moves[100] = {0};
    int i,j;
    scanf("%d",&player);
    scanf("%d",&scotch_pos);
    getline(&remove_new_line,&buf_limit,stdin);      //removes a new line from the buffer for getline to work.
    getline(&first_move,&buf_limit,stdin);
    getline(&second_move,&buf_limit,stdin);
    tok_1 = strtok(first_move," ");

    for(i=0;tok_1;i++) {
        first_moves[i] = atoi(tok_1); 
        tok_1 = strtok(NULL," ");
    }

    tok_2 = strtok(second_move," ");

    for(i=0;tok_2;i++) {
        second_moves[i] = atoi(tok_2); 
        tok_2 = strtok(NULL," ");
    }
   // printf("Hello World!\n");
    bid = calculate_bid(player,scotch_pos,first_moves,second_moves);
    printf("%d",bid);
    return 0;

}
