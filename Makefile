CC:=gcc
my.o:my.c func.c
	@echo -e '\nmake my.c\n'
	gcc  $^ -g -o $@
	./my.o "1234+(2*(3+33))+(3+2)"
clean:
	rm ./my.o
atoi.o:atoi.c
	gcc  $^ -o $@ ; ./$@
#div.o:div.c
#	gcc  $^ -o $@ ; ./$@
#convert.o:convert.c
#	gcc  $^ -o $@ ; ./$@
