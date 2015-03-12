sil2xsm : label.o lex.yy.c
	gcc -o sil2xsm lex.yy.c label.o -ll
lex.yy.c : sil2xsm.l
	lex sil2xsm.l
label.o : label.c label.h
	gcc -c label.c -o label.o
clean :
	$(RM) lex.yy.c 
