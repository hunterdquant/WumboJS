wumbo: y.tab.o lex.yy.o sym_table.o exp_tree.o stmt.o wumbo_utils.o
	gcc -g -o wumbo y.tab.o lex.yy.o sym_table.o exp_tree.o stmt.o wumbo_utils.o -ll -ly

y.tab.o: y.tab.c
	gcc -g -c y.tab.c

lex.yy.o: lex.yy.c
	gcc -g -c lex.yy.c

y.tab.c: wumbo.y sym_table.c exp_tree.c stmt.c
	gcc -g -c sym_table.c exp_tree.c stmt.c
	yacc -dv wumbo.y

stmt.c: exp_tree.c wumbo_utils.c
	gcc -g -c exp_tree.c wumbo_utils.c

exp_tree.c: wumbo_utils.c
	gcc -g -c wumbo_utils.c

lex.yy.c: wumbo.l
	lex -l wumbo.l

clean:
	rm -f *.o wumbo y.tab.c lex.yy.c y.tab.h y.output

