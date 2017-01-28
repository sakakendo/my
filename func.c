#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char* home(char *str){
    while(*(--str));
    (str++);
    return str;
}
void Insert(char *bp,char *ap,char *str){
    printf("%sbp=%cap=%cstr=%s\n",__func__,*bp,*ap,str);
    char *bp0=bp;
    bp++; while(*str){
        *(bp++)=*(str++);
    }
    while(*ap){
        *(bp++)=*(ap++);
    }
    *bp='\0';
    printf("Insert result : %s\n",bp0);
}
int Ope_p(char *c){
    printf("%s\n",__func__);
}
int Ope(char c){
    if(c=='+')  return 1;
    if(c=='-')  return 1;
    if(c=='*')  return 1;
    if(c=='/')  return 1;
    return 0;
}

char checkNum(char c){
    if('0'<c && c<'9') return c;
    return '\0';
}

ope_t cntOpe(char *exp/*,ope_t cnt*/){
    //check whether or not exp has any operator
        //if no ,return to eval
        //else if find '*','/' then find'+','-'
//    printf("%s\n",__func__);
    ope_t cnt={};
    while(*exp){
        if(*exp=='+') cnt.add++;
        if(*exp=='-') cnt.sub++;
        if(*exp=='*') cnt.multi++;
        if(*exp=='/') cnt.div++;
        cnt.sum=(cnt.add+cnt.sub+cnt.multi+cnt.div);
        if(*exp=='(') cnt.left++;
        if(*exp==')') cnt.right++;
	cnt.bracket=cnt.right+cnt.left;
        exp++;
    }
//    printf("%s\n",__func__);
    return cnt;
}
/*** eval() 
int check(char *exp){
//    char token[128]="default";
    int class,class0=-1;
    while(*exp!='\0'){
        class=classify(&exp);
//        printf("%p,token=%5s%3d%3d\n",&exp,token,class,(int)strlen(token));
        exp++;
        switch (class){
            case(NUM):
                if(class0==-1 || class0==LEFT ||class0==OPERATION){
                }else {
                    printf("__NUM_ERROR__");
                    return 0;
                }
                break;
            case(OPERATION):
                if(class0==NUM || class0==RIGHT){
                }else {
                    printf("__OPERATION_ERROR__\n");
                    return 0;
                }
                break;
            case(LEFT):
                if(class0==-1 || class0==OPERATION || class0==LEFT){
                }else{
                    printf("__LEFT_BRACKET_ERROR__\n");
                    return 0;
                }
                break;
            case(RIGHT):
                if(class0==NUM || class0==RIGHT){
                }else{
                    printf("__RIGHT_BRACKET_ERROR__\n");
                    return 0;
                }
                break;
        }
        class0=class;
    }
    return 1;
}
int classify(char **str){
//    printf("%s\n",__func__);
//    char *str1="aaaaaa";
    char *str1;
    str1=malloc(g_len);
    if(**str=='('){
        *str1=**str;
        *(str1+1)='\0';
        return LEFT;
    }else if(**str== ')'){
        *str1=**str;
        *(str1+1)='\0';
        return RIGHT;
    }else if('0'<=**str && **str<='9'){
        while('0'<=**str && **str<='9'){
            *str1=**str;
            (*str)++;
            (str1)++;
        }
        (*str)--;
        *str1='\0';
        return NUM;
    }else if(checkOpe(**str)){
        *str1=**str;
        *(str1+1)='\0';
        return OPERATION;
    }
    printf("%s\n",__func__);
    return 0;
}
	eval() ***/
