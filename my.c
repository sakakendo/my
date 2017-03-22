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

#include "inc/eval.h"
#include "inc/my.h"
#include "inc/digit.h"

#ifndef __CALC__
#pragma message("calc")
int main(int argc,char *argv[]){
    char str[128];
    sprintf(str,"(%s)",argv[1]);
    g_len=(int)(strlen(str));
        //length of exp
    printf("%s length=%d\n",str,g_len);
    if(check(str)){
        printf("exp is correct\n");
    }else {
        printf("exp is incorrect\n");
        exit(1);
    }
    eval(str);
    return 0;
}
#endif //__CALC__
int dbg(/*const char *exp*/){
#ifdef DBG
	printf( "dbg mode");
	printf( "undbg mode");
#endif //__DBG __ 
#ifndef DBG
	printf( "undbg mode");
#endif //__DBG __ 
}

void eval(char *exp){
    int c=0,c0=0,i=0,n,l;
	//i: length of tmp 
    char *tmp,*endp,*result;
	//tmp:strings to eval
    tmp=malloc((int)strlen(exp));
    ope_t cnt=cntOpe(exp);
    l=0;
    while(0){
recheck:
        exp=home(exp);
    }
    printf("%s %d \texp=%s size=%d\n",__func__,__LINE__,exp,l);
    if(cnt.bracket==0){
        calc(exp);
    }else{
        do{
            i++;
            if(*exp=='('){
                i=0;
            }
			if(*exp==')'){
				printf("tmp=%s\n",tmp-i+1);
                eval(tmp-i+1);
                goto recheck;
            }
            *(tmp++)=*exp;
            exp++;
        }while(exp!='\0');
    }
}
