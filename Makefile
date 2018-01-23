	
all: clean
	flex scanner.lex
	bison -d parser.ypp 
	g++ -o hw5 *.c *.cpp ${f} #-DHW3 #-DDEBUG
clean:
	rm -f lex.yy.c
	rm -f parser.tab.*pp
	rm -f hw5
