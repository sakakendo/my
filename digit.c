#include<math.h>
#include "digit.h"

int digit(int n){
	double i=1;
	while( n/=pow(10,(double)i++) );
	return i-1;
}
