mycalc: y.tab.o lex.yy.o sym_table.o
	gcc -g -o wumbo y.tab.o lex.yy.o sym_table.o -ll -ly

y.tab.o: y.tab.c
	gcc -g -c y.tab.c

lex.yy.o: lex.yy.c
	gcc -g -c lex.yy.c

y.tab.c: wumbo.y sym_table.c
	gcc -g -c sym_table.c
	yacc -dv wumbo.y

lex.yy.c: wumbo.l
	lex -l wumbo.l

clean:
	rm -f *.o wumbo y.tab.c lex.yy.c y.tab.h y.output

