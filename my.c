#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum{NUM=1,OPERATION,LEFT,RIGHT};
/**ptototype**/
int check(char *exp);
int classify(char **str,char *str1);
int checkOpe(char c);
char *eval(char *exp);
//int eval();
    //pass the exp to calc
char *calc(char *exp);
//int calc();
int returnOpe(char *exp);
void Insert(char *bP,char *ap,char str);

int main(int argc,char *argv[]){
    char str[128];
    sprintf(str,"(%s)",argv[1]);
    printf("%s\n",str);
    if(check(str)){
        //normal    1
        //abend     0
        printf("exp is correct\n");
    }else {
        printf("exp is incorrect\n");
        exit(1);
    }
    eval(str);
//    eval(&str);
    return 0;
}

//int eval(char *exp){
char *eval(char *exp){
    int c=1,c0=0,i=0,n;
//    int c=0,c0=0,i=0,n;
    char *tmp,*endp;
    printf("%s\t%s\n",__func__,exp);
    if(returnOpe(exp)==1){
        //no more '(' , ')'
        return calc(exp);
//        printf("%d",n);
    }else{
        exp++;
        do{
            if(*exp=='(') c++;
            if(*exp==')') c--;
            printf("i=%d c0=%d c=%d *exp=%c\n",i,c0,c,*exp);
//            if(c==2 && c0==1) endp=exp;
            if(c>=2 && c0!=1){
                *tmp=*exp;
                tmp++;
                i++;
            }
            exp++;
            c0=c;
        }while(c!=0 && *exp!='\0');
        *tmp='\0';
        tmp-=i;
        printf("tmp=%s\n",tmp);
        //insert the result recrusion
//        printf("I think here is Segment\n%c",*endp);
        eval(tmp);
//        printf("bp=%c ap=%c str=%s length of str=%d\n",'a','b',eval(tmp),(int)strlen(tmp));
//        Insert(,eval(tmp))
        printf("I think here is Segment");
    }
}

void Insert(char *bP,char *ap,char str){

}


char* calc(char *exp){
    printf("%s\t%s\n",__func__,exp);
    char *str="123";
    return str;
//    *exp=10;
    //sample return 10
//    int n,m;
/*    while(*exp){
        if(checkOpe(*exp)==1){
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
        }
        exp++;
    }
*/   
}

int check(char *exp){
    char token[128]="default";
    int class,class0=-1;
    while(*exp!='\0'){
        class=classify(&exp,token);
//        printf("%p,%5s%3d%3d\n",&exp,token,class,(int)strlen(token));
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

int classify(char **str,char *str1){
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
    return 0;
}
int checkOpe(char c){
    if(c=='+')  return 1;
    if(c=='-')  return 1;
    if(c=='*')  return 1;
    if(c=='/')  return 1;
    return 0;
}

int returnOpe(char *exp){
    while(*exp){
        if(*exp=='(' || *exp==')'){
            return 0;
        }
        exp++;
    }
//    printf("%s %s",__func__,exp);
    return 1;
}
