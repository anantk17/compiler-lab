slpi: y.tab.c exptree.c lex.yy.c symboltable.c
	gcc -g -o slpi y.tab.c exptree.c symboltable.c -ll

lex.yy.c : slpi.l
	lex slpi.l

exptree.o	: exptree.c exptree.h
	gcc -g -c exptree.c

y.tab.c : slpi.y
	yacc -d slpi.y

symboltable.o :	symboltable.c symboltable.h
	gcc -g -c symboltable.c
