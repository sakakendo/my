CC:=gcc
INC =-I.
INC+=-Iinc
SRC =my.c  calc.c 
SRC+=src/func.c src/eval.c src/digit.c
obj/my.o:$(SRC)
	@echo -e '\nmake my.c\n'
	gcc $(INC) $^ -g -o $@ -lm
	obj/my.o "1234+(2*(3+33))+(3+2)" > obj/result
obj/calc.o:$(SRC)
	gcc $(INC) $^ -o $@ -lm -D__CALC__
	./$@ 1234+2
dbg:my.c func.c
	@echo -e '\n debug mode \n'
	gcc  -D DBG $^ -g -o $@ -lm
	./my.o "1234+(2*(3+33))+(3+2)"

clean:
	rm obj/calc.o
#div.o:div.c
#	gcc  $^ -o $@ ; ./$@
#convert.o:convert.c
#	gcc  $^ -o $@ ; ./$@
