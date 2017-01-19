//to do list
    //I can make shorter slassify() with clear str1
    //printf("%s\n",__func__);
    //#define checkOpe(X) _Generic((X),char :Ope,char *: Ope_p)(X)
//Done
    //char cntOpe(char c){
    //count the brackets number
    //make the function to go to toop of the char[]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my.h"

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

char *eval(char *exp){
    int c=0,c0=0,i=0,n,l;
    char *tmp,*endp,*result;
    tmp=malloc((int)strlen(exp));
    ope_t cnt;
    while(0){
recheck:
        printf("recheck\n");
        exp=home(exp);
    }
    l=(int)strlen(exp);
    printf("%s\texp=%s size=%d\n",__func__,exp,l);
    if(cntOpe(exp,cnt).bracket<=2){
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
char* calc(char *exp){
    printf("%s exp=%s\n",__func__,exp);
//    char *str,*tmp,result="100";
    char *tmp;	
    int pri;
	//s : state of *exp
	//pri : Number of priority operation(*,/)          
    ope_t c; 
        // ---stack ope then return result---
    while(cntOpe(exp,c).sum){
	pri=c.multi+c.div;
	if('0'<*exp  && *exp<'9'){
		*tmp=*exp;	
		tmp++;
	}else{
		a=atoi(tmp);
//		b=;
		if(*exp=='*' ){
		
		}else if( *exp=='/'){

		}else if(*exp=='+' && !pri){
		
		}else if(*exp=='-' && !pri){

		}
	}
	exp++;
    }
    return result;
}
/*
int* numify(char *exp){
    int *n,c=0,c0=0;
    char *tmp;
    tmp=malloc(128);
    while(*exp){
        if(checkNum(*exp)){
            //start of a number
            *tmp=*exp;
            tmp++;
        }else if(!checkNum(*exp)){ //out of a number *tmp='\0'; tmp=home(tmp); *n=atoi(tmp); printf("num=%d\n",*n); n++;
        }
        c0=c;
        exp++;
    }
    return n;
}

void hoge(char *exp){
	int a,b;
	//left and right value
	value(exp);
	if(*exp=='*'){
		return a*b;	
	}
}
int* value(char *exp){
	//return left and right value
	int *n;

	return n;
}
*/
int Ope_p(char *c){
    printf("%s\n",__func__);
}
int Ope(char c){
//    printf("%s\n",__func__);
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
ope_t cntOpe(char *exp,ope_t cnt){
    //check whether or not exp has any operator
        //if no ,return to eval
        //else if find '*','/' then find'+','-'
    printf("%s\n",__func__);
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
    return cnt;
}
/*
int cntBracket(char *exp){
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
*/
