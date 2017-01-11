//to do list
    //count the brackets number
    //make the function to go to toop of the char[]
    //I can make shorter slassify() with clear str1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my.h"
enum{NUM=1,OPERATION,LEFT,RIGHT};
int g_len;

int main(int argc,char *argv[]){
    char str[128];
    sprintf(str,"(%s)",argv[1]);
    g_len=(int)(strlen(str));
        //length of exp
    printf("%s length=%d\n",str,g_len);
    if(check(str)){
        //normal    1
        //abend     0
        printf("exp is correct\n");
    }else {
        printf("exp is incorrect\n");
        exit(1);
    }
//    printf("exp=%s,eval result=%s\n",str,eval(str));
    eval(str);
    return 0;
}
char* home(char *str){
    while(*(--str));
    (str++);
    return str;
}

char *eval(char *exp){
    int c=0,c0=0,i=0,n,l;
    char *tmp,*endp,*result;
    tmp=malloc((int)strlen(exp));
    while(0){
recheck:
        printf("recheck\n");
        exp=home(exp);
    }
    l=(int)strlen(exp);
    printf("%s\texp=%s size=%d\n",__func__,exp,l);
    if(returnOpe(exp)<=2){
        //when the exp is the minmum
        return calc(exp);
    }else{
        do{
            c0=c;
            *(tmp++)=*exp;
            i++;
            if(*exp=='('){
                c++;
                i=1;
            }
            if(*exp==')'){
                result=eval(tmp);
                // recrusion '(' , ')' exp to eval()
//                printf("insert : bp=%c,ap=%c,str=%s\n",*(exp-i),*(exp+1),result);
                Insert((exp-i),(exp+1),result);
                /***after insert you should reentry this function in order to recount 'i','tmp' and so on.***/
                goto recheck;
                c--;
            }
            exp++;
//            printf("i=%d c0=%d c=%d *exp=%c *tmp=%s\n",i,c0,c,*(exp++),(tmp-i));
        }while(/*!(c==0 && c0==1) &&*/ *exp!='\0');
    }
//    printf("exp :%p\n",--exp);
}
int* numify(char *exp){
    int *n,c=0,c0=0;
    char *tmp;
    tmp=malloc(128);
    while(*exp){
        if(checkNum(*exp)){
            //start of a number
            *tmp=*exp;
            tmp++;
/*
        }else if(c==NUM && c0==NUM){
            //midstram of a number
*/

        }else if(!checkNum(*exp)){
            //out of a number
            *tmp='\0';
            tmp=home(tmp);
            *n=atoi(tmp);
            printf("num=%d\n",*n);
            n++;
        }
        c0=c;
        exp++;
    }
    return n;
}

char* calc(char *exp){
    printf("%s exp=%s\n",__func__,exp);
    char *str;
    int c;
    int *n;
    n=malloc(100);
    n=numify(exp);
/*    while(*n){
//        printf("%d",*n);
        n++;
    }
*/
/*    while(*exp){
//        if(checkOpe(*exp)==1){
//        c=classify(*exp);
        if(c==OPERATION){
            printf("%c",*exp);
            switch (*exp){
                case('+'):
                    break;
                case('-'):
                    break;
                case('*'):
                    break;
                case('/'):
                    break;
            }
         }else if(c==NUM){
         }
        exp++;
    }
*/
    return str="111";
}

void Insert(char *bp,char *ap,char *str){
//    printf("%s %c %c %s\n",__func__,*bp,*ap,str);
    int l=0;
    bp++;
    while(*str){
        *(bp++)=*(str++);
        l++;
    }
    while(*ap){
        *(bp++)=*(ap++);
        l++;
    }
    *bp='\0';
}

int check(char *exp){
//    char token[128]="default";
    int class,class0=-1;
    while(*exp!='\0'){
        class=classify(&exp/*,token*/);
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

int classify(char **str/*,char *str1*/){
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
int checkOpe(char c){
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
int returnOpe(char *exp){
    int cnt=0;
    while(*exp){
        if(*exp=='(' || *exp==')'){
            cnt++;
        }
        exp++;
    }
//    printf("%s %s",__func__,exp);
    return cnt;
}
