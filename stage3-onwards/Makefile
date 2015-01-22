slpi: y.tab.c exptree.o lex.yy.c
	gcc -o slpi y.tab.c exptree.o -ll

lex.yy.c : slpi.l
	lex slpi.l

exptree.o	: exptree.c exptree.h
	gcc -c exptree.c

y.tab.c : slpi.y
	yacc -d slpi.y
