Bison = C:\ProgramData\chocolatey\bin\win_bison.exe
Flex = C:\ProgramData\chocolatey\bin\win_flex.exe

#CFLAGS = -I "C:/Graphviz/include/graphviz" -I "C:/Graphviz/include"
#LDLIBS = -L "C:/Graphviz/lib" -lgvc -lcgraph -lcdt

INCLUDE_PATH = -I C:/Graphviz/include
LIB_PATH = -L C:/Graphviz/lib
LIBS = -lgvc -lcgraph -lcdt -lpathplan

all: bison.tab.o lex.yy.o ast.o dfs.o
	gcc $(INCLUDE_PATH) $(LIB_PATH) lex.yy.o bison.tab.o ast.o dfs.o -o lab2 $(LIBS)

bison.tab.o: bison.tab.c
	gcc -c bison.tab.c -o bison.tab.o $(INCLUDE_PATH) $(LIB_PATH)

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c -o lex.yy.o $(INCLUDE_PATH) $(LIB_PATH)

bison.tab.c:
	$(Bison) -Wcounterexamples -d bison.y

lex.yy.c:
	$(Flex) flex.l

ast.o:
	gcc -c ./src/ast.c -o ast.o $(INCLUDE_PATH) $(LIB_PATH)
dfs.o:
	gcc -c ./src/dfs.c -o dfs.o $(INCLUDE_PATH) $(LIB_PATH)

clear:
	del /f bison.tab.h bison.tab.c lex.yy.c bison.tab.o lex.yy.o ast.o  dfs.o bison.gv out.svg lab2.exe output.dot file.png