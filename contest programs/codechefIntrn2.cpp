//
//  codechefIntrn2.cpp
//  
//
//  Created by Ramit on 09/02/13.
//
//

//#include "codechefIntrn2.h"
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stl>
#include <map>
#define BUFLIMIT 65560
using namespace std;

char U[11]={0,7,8,9,3,2,1,6,5,4};
char D[11]={0,6,5,4,9,8,7,1,2,3};
char R[11]={0,2,3,1,6,4,5,8,9,7};
char L[11]={0,3,1,2,5,6,4,9,7,8};

int chk_escape(char *s,int k)
{
    int flag=0,flag1=0;//U=1,D=2,L=3,R=4
    switch(s[0])
    {
        case '9':
        case '8':
        case '7':
            flag0=2;break;
    }
    switch(s[0])
    {
        case '1':
        case '2':
        case '3':
            flag0=1;break;
            
    }
    switch(s[0])
    {
        case '3':
        case '4':
        case '9':
            flag0=4;break;
    }
    switch(s[0])
    {
        case '1':
        case '6':
        case '7':
            flag0=3;break;
    }

    for(int i=1;i<k;i++)
    {
        switch(s[i])
        {
                case '9':
                case '8':
                case '7':
                flag1=2;break;
        }
        switch(s[i])
        {
            case '1':
            case '2':
            case '3':
            flag1=1;break;
                
        }
        switch(s[i])
        {
            case '3':
            case '4':
            case '9':
                flag1=4;break;
        }
        switch(s[i])
        {
            case '1':
            case '6':
            case '7':
                flag1=3;break;
        }
        if(flag0==flag1)continue;
        else {flag0=-1;break;}
    }
    return flag0;
}
int main()
{
    int T;
    char s[210],num[210];
    size_t buf_limit = BUFLMT;
    char ans[200];
    ans="the day is saved";
    int u,l,d,r;
    int go_up,go_down,go_left,go_right;
    char *sentence = (char *) malloc(buf_limit);
    char *tok_1;
    scanf("%d",&T);int k=0;
    while(T--)
    {
        scanf("%s",s);
        tok_1=strtok(s," ");
        int k=atoi(tok_1);
        num=strtok(NULL," ");
        scanf("%s",s);
        len=strlen(s)-1;
        u=l=d=r=0;
        for(int i=0;i<len;i++)
        {
            switch(s[i])
            {
                case 'U':u++;break;
                case 'D':d++;break;
                case 'L':l++;break;
                case 'R':r++;break;
            }
        }
            go_up=(u>d)?(u-d):0;
            go_down=(d>u)?(d-u):0;
            go_left=(l>r)?(l-r):0;
            go_right=(r>l)?(r-l):0;
       
        if(go_up>0)
        {
            if(go_left>0)
            {
                while(go_left--)
                {
                    for(int i=0;i<len;i++)
                        s[i]=L[s[i]-'0']+'0';
                }
            }
            else
            {
                while(go_right--)
                {
                    for(int i=0;i<len;i++)
                        s[i]=R[s[i]-'0']+'0';
                }
            }
            while(go_up--)
            {
                for(int i=0;i<len;i++)
                    s[i]=U[s[i]-'0']+'0';
            }
        }
        else
        {
            if(go_left>0)
            {
                while(go_left--)
                {
                    for(int i=0;i<len;i++)
                        s[i]=L[s[i]-'0']+'0';
                }
            }
            else
            {
                while(go_right--)
                {
                    for(int i=0;i<len;i++)
                        s[i]=R[s[i]-'0']+'0';
                }
            }
            while(go_down--)
            {
                for(int i=0;i<len;i++)
                    s[i]=D[s[i]-'0']+'0';
            }
        }
    }
}