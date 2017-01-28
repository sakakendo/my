CC:=gcc
FLAGS=-nostartfiles
SRC=src/func.c  src/digit.c src/eval.c
HEADER=inc/my.h inc/digit.h inc/eval.h
my.o:my.c calc.c $(SRC) $(HEADER)

	@echo -e '\nmake my.c\n'
	@gcc  $^ -g -o $@ -lm 
	@./my.o "1234+(2*3*3+33)+(3+2)"

calc.o:calc.c $(SRC) $(HEADER)
	gcc $^ -o $@ -lm -D __CALC__
	# $(FLAGS)
	./$@ 1234+2*3+99
dbg:my.c func.c
	@echo -e '\n debug mode \n'
	gcc  -D DBG $^ -g -o $@ -lm
	./my.o "1234+(2*(3+33))+(3+2)"

clean:
	rm ./my.o
#div.o:div.c
#	gcc  $^ -o $@ ; ./$@
#convert.o:convert.c
#	gcc  $^ -o $@ ; ./$@
