wumbo: y.tab.o lex.yy.o sym_table.o exp_tree.o stmt.o wumbo_utils.o decl.o
	gcc -g -o wumbo y.tab.o lex.yy.o sym_table.o exp_tree.o stmt.o decl.o wumbo_utils.o -ll -ly

dwumbo: y.tab.o lex.yy.o sym_table.o dexp_tree.o stmt.o wumbo_utils.o decl.o
	gcc -g -o wumbo y.tab.o lex.yy.o sym_table.o exp_tree.o stmt.o decl.o wumbo_utils.o -ll -ly

y.tab.o: y.tab.c
	gcc -g -c y.tab.c

lex.yy.o: lex.yy.c
	gcc -g -c lex.yy.c

y.tab.c: wumbo.y sym_table.c exp_tree.c stmt.c decl.c
	gcc -g -c sym_table.c exp_tree.c stmt.c decl.c
	yacc -dv wumbo.y

stmt.c: exp_tree.c
	gcc -g -c exp_tree.c

exp_tree.c: wumbo_utils.c
	gcc -g -c wumbo_utils.c

dexp_tree.o: wumbo_utils.c 
	gcc -g -c wumbo_utils.c -DDEBUG

lex.yy.c: wumbo.l
	lex -l wumbo.l

clean:
	rm -f *.o wumbo y.tab.c lex.yy.c y.tab.h y.output