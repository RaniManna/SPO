Bison = C:\ProgramData\chocolatey\bin\win_bison.exe
Flex = C:\ProgramData\chocolatey\bin\win_flex.exe

all: bison.tab.o lex.yy.o ast.o dfs.o
	gcc lex.yy.o bison.tab.o ast.o dfs.o -o lab1

bison.tab.o: bison.tab.c
	gcc -c bison.tab.c -o bison.tab.o

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c -o lex.yy.o

bison.tab.c:
	$(Bison) -Wcounterexamples -d  bison.y

lex.yy.c:
	$(Flex) flex.l

ast.o:
	gcc -c ./src/ast.c -o ast.o

dfs.o:
	gcc -c ./src/dfs.c -o dfs.o

clear:
	del /f bison.tab.h bison.tab.c lex.yy.c bison.tab.o lex.yy.o ast.o dfs.o bison.gv out.svg lab1

