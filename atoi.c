#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int digit(int n){
	int i=0;
	while((n/=10)>=10){
		i++;
	}
	return i;

}

int main(){
	int i=0,n,l;
	char exp[128]="123+456*789";
	printf("%p\n",exp);
	n=atoi(exp);
	l=digit(n);
	printf("%d:%d\n",n,l);
	printf("%p\n",exp);
	return 0;
}

