//to do list
    //I can make shorter slassify() with clear str1
    //printf("%s\n",__func__);
    //#define checkOpe(X) _Generic((X),char :Ope,char *: Ope_p)(X)
    // make calc() eval() to return void
//Done
    //char cntOpe(char c){
    //count the brackets number
    //make the function to go to toop of the char[]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "eval.h"
#include "my.h"
#include "digit.h"

int main(int argc,char *argv[]){
	calc( argv[1]);
    return 0;
}

void calc(char *exp){
//    printf("%s exp=%s\n",__func__,exp);
//    printf("%c,%d\n",*exp,(int)strlen(exp));
    int pri,s=0,n0,n1,tmp=0;
	//s : state of *exp
	//pri : number of priority operation(*,/)          
    char *exp0;
	char *head=exp;
    char str[128];
    ope_t c;//=cntope(exp); 
        // ---stack ope then return result---
//    while(sum && *exp){
	while( 0){
init:
		exp=head;
//		printf("%d head=%s\n",__line__,head);
	}
	c=cntOpe(exp); 
	pri=c.multi+c.div;
	//        printf("exp= %c\n",*exp);
	do{
        if(('0'<*exp  && *exp<'9') && s==0){
            s=1;
            exp0=exp;
            n0=atoi(exp);
        }else if(Ope(*exp)){
            //		printf("pri=%d",pri);
            s=0;
            n1=atoi(exp+1);
            if(*exp=='*' ){
                tmp=n0/n1;
            }else if(*exp=='+' && pri==0){
                tmp=n0+n1;
            }else if(*exp=='-' && !pri){
                tmp=n0-n1;
            }
//            printf("%d %c %d = %d\n",n0,*exp,n1,tmp);
//            printf("exp : %p  %c exp0: %p : %c n0 : %d n1 : %d\n"
//                    ,exp,*exp,exp0,*exp0,digit(n0),digit(n1));
            printf("insert : n0=%d n1=%d tmp=%d\n",n0,n1,tmp);
            sprintf(str,"%d",tmp);
            Insert(exp0-1,exp+digit(n1)+1,str);
            printf("%s",exp0);
			goto init;
        }
        exp++;
    }while(c.sum && *exp);
    //    return result;
}
