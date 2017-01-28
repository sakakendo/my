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

#ifdef __CALC__
int main(int argc,char *argv[]){
	char *(str[128]);
	*str=argv[1];
//	calc( argv[1]);
	calc(*str);
    return 0;
}
#endif //__CALC__

char* calc(char *exp){
	printf("func : %s %s\n",__func__,exp);
    int pri,s=1,n0,n1,tmp=0;
	//s : state of *exp
	//in the number : 0 
	//disable calculate: 1 
	//enable calculate : 2
	//pri : number of priority operation(*,/)          
    char *exp0;
	char *head=exp;
    char str[128]={};
    ope_t c;
	while(0){
init:
		exp=head;
	}
	c=cntOpe(exp); 
	pri=c.multi+c.div;
	do{
        if(('0'<*exp  && *exp<'9') && s!=0/*s==0 */){
            s=0;
            exp0=exp;
            n0=atoi(exp);
        }else if(Ope(*exp)){
            s=1;
            n1=atoi(exp+1);
            if(*exp=='*' ){
                tmp=n0*n1;
				s=2;
            }else if(*exp=='/'){
                tmp=n0/n1;
				s=2;
			}
			if(*exp=='+'&& !pri){
                tmp=n0+n1;
				s=2;
            }else if(*exp=='-' && !pri) {
                tmp=n0-n1;
				s=2;
            }
			//when tmp is not calucurated don't insert
			if(s==2){
				printf("calculation: %d %c %d= %d\n",n0,*exp,n1,tmp);
				printf("insert : n0=%d n1=%d tmp=%d\n",n0,n1,tmp);
				sprintf(str,"%d",tmp);
				Insert(exp0-1,exp+digit(n1)+1,str);
				printf("%s\n",exp0);
				goto init;
			}
		}
        exp++;
    }while(c.sum && *exp);
//	printf("%s result %s\n",__func__,head);
	return head;
}
