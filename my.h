
int check(char *exp);
        //normal    1
        //abend     0

//int classify(char **str,char *str1);
int classify(char **str/*,char *str1*/);
    // classify move the current pointer
    // enum{NUM=1,OPERATION,LEFT,RIGHT};
    // **str    :target string
    // *str1    : used to debug. so it
char *eval(char *exp);
char *calc(char *exp);
int* numify(char *exp);
int checkOpe(char c);
    //if character is Operation , return 1 
char checkNum(char c);
    //if character is Number
int returnOpe(char *exp);
    //return Operation '(',')' number
void Insert(char *bP,char *ap,char *str);


