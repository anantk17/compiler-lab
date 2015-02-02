slpi: y.tab.c exptree.o lex.yy.c symboltable.o
	gcc -g -o slpi y.tab.c exptree.o symboltable.o -ll

lex.yy.c : slpi.l
	lex slpi.l

exptree.o	: exptree.c exptree.h
	gcc -g -c exptree.c

y.tab.c : slpi.y
	yacc -d slpi.y

symboltable.o :	symboltable.c symboltable.h
	gcc -g -c symboltable.c

clean:
	$(RM) y.tab.* slpi lex.yy.c exptree.o symboltable.o
