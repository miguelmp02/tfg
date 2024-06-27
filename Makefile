CC = gcc
CFLAGS = -I. -g -Isrc/

# Define los archivos objeto
OBJS = src/generacion/lex.yy.o src/generacion/y.tab.o src/generacion/symbol_table.o src/generacion/semantic.o src/generacion/codegen.o src/generacion/main.o

# Nombre del ejecutable final
EXEC = compiler

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -o $@ $(OBJS) -ly -lfl

# Genera el código objeto para el analizador léxico
src/generacion/lex.yy.o: src/lex.l src/generacion/y.tab.h
	flex -o src/generacion/lex.yy.c src/lex.l
	$(CC) $(CFLAGS) -c src/generacion/lex.yy.c -o src/generacion/lex.yy.o

# Genera el código objeto para el analizador sintáctico
src/generacion/y.tab.o: src/syntax.y
	bison -yd -o src/generacion/y.tab.c src/syntax.y
	$(CC) $(CFLAGS) -c src/generacion/y.tab.c -o src/generacion/y.tab.o

# Asegúrate de que y.tab.h se genere a partir del archivo correcto
src/generacion/y.tab.h: src/syntax.y
	bison -yd -o src/generacion/y.tab.c src/syntax.y

# Genera el código objeto para la tabla de símbolos
src/symbol_table.o: src/symbol_table.c src/symbol_table.h
	$(CC) $(CFLAGS) -c src/symbol_table.c -o src/symbol_table.o

# Genera el código objeto para el análisis semántico
src/semantic.o: src/semantic.c src/semantic.h src/symbol_table.h
	$(CC) $(CFLAGS) -c src/semantic.c -o src/semantic.o

# Genera el código objeto para la generación de código
src/codegen.o: src/codegen.c src/codegen.h
	$(CC) $(CFLAGS) -c src/codegen.c -o src/codegen.o

# Genera el código objeto para el archivo principal
src/main.o: src/main.c src/codegen.h
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

clean:
	rm -f src/*.o src/generacion/*.o src/generacion/lex.yy.c src/generacion/y.tab.c src/generacion/y.tab.h $(EXEC)

.PHONY: all clean

