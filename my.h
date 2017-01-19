//declation of variable
enum{NUM=1,OPERATION,LEFT,RIGHT};
int g_len;
    //exp's length
//char **ope_t;
//char *ope_t
typedef struct {
    //operation counter table
    int add;
    int sub;    //subtract
    int multi;  //multiply;
    int div;    //divide;
    int sum;    //cnt of all operation
    int right;
    int left;
    int bracket;
}ope_t;//op

//prototype declation
int Ope(char c);
int Ope_p(char *c);
#define checkOpe(X) _Generic((X),char :Ope,char *: Ope_p)(X)
//#define checkOpe(X) _Generic((X),char :Ope,char *: Ope_p)(X)

char* home(char *str);
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
//int checkOpe(char c);
    //if character is Operation , return 1 
char checkNum(char c);
    //if character is Number
int returnOpe(char *exp);
    //return Operation '(',')' number
void Insert(char *bP,char *ap,char *str);

ope_t cntOpe(char *exp,ope_t cnt);

int cntBracket(char *exp);

