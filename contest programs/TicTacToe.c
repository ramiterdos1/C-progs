{\rtf1\ansi\ansicpg1252\cocoartf1187\cocoasubrtf340
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural

\f0\fs24 \cf0 #include <stdio.h>\
#include <string.h>\
#include <math.h>\
\
/* Complete the function below to print 2 integers separated by a single space which will be your next move \
 */\
void nextMove(char player, char ar[3][3])\{\
if(player=='X')\
\{\
    if(board[1][1]=='_')printf("%d %d\\n",1,1);\
    else \
\}\
\
\}\
\
\
int main() \{\
\
    int i;\
    char player;\
    char board[3][3];\
\
    //If player is X, I'm the first player.\
    //If player is O, I'm the second player.\
    scanf("%c", &player);\
\
    //Read the board now. The board is a 3x3 array filled with X, O or _.\
    for(i=0; i<3; i++) \{\
        scanf("%s[^\\n]%*c", board[i]);\
    \}\
  \
	nextMove(player,board);\
    return 0;\
\}}