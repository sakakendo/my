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
    l=0; //(int)strlen(exp);
    printf("%s\texp=%s size=%d\n",__func__,exp,l);
    while(0){
recheck:
//        printf("recheck\n");
        exp=home(exp);
    }
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
//            printf("i=%d c0=%d c=%d *exp=%c *tmp=%s\n",i,c0,c,*(exp++),(tmp-i));
        }while(exp!='\0');
    }
}
/*
void calc(char *exp){
//    printf("%s exp=%s\n",__func__,exp);
//    printf("%c,%d\n",*exp,(int)strlen(exp));
    int pri,s=0,n0,n1,tmp=0;
	//s : state of *exp
	//pri : Number of priority operation(*,/)          
    char *exp0;
	char *head=exp;
    char str[128];
    ope_t c;//=cntOpe(exp); 
        // ---stack ope then return result---
//    while(sum && *exp){
	while( 0){
init:
		exp=head;
		printf("%d head=%s\n",__LINE__,head);
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
                tmp=n0*n1;
            }else if( *exp=='/'){
                tmp=n0/n1;
            }else if(*exp=='+' && pri==0){
                tmp=n0+n1;
            }else if(*exp=='-' && !pri){
                tmp=n0-n1;
            }
//            printf("%d %c %d = %d\n",n0,*exp,n1,tmp);
//            printf("exp : %p  %c exp0: %p : %c n0 : %d n1 : %d\n"
//                    ,exp,*exp,exp0,*exp0,digit(n0),digit(n1));
            printf("Insert : n0=%d n1=%d tmp=%d\n",n0,n1,tmp);
            sprintf(str,"%d",tmp);
            Insert(exp0-1,exp+digit(n1)+1,str);
            printf("%s",exp0);
			goto init;
        }
        exp++;
    }while(c.sum && *exp);
    //    return result;
}
*/
/*
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
ope_t cntOpe(char *exp){
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

int digit(int n){
	double i=1;
	while( n/=pow(10,(double)i++) );
	return i-1;
}
*/
