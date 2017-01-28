CC:=gcc
my.o:my.c my.h calc.c func.c
	@echo -e '\nmake my.c\n'
	gcc  $^ -g -o $@ -lm
	./my.o "1234+(2*(3+33))+(3+2)"
calc.o:my.h calc.c func.c digit.h digit.c
	gcc   $^ -o $@ -lm
	./$@ 1234+2
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
