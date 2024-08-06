CC = gcc
CFLAGS = -I. -g -Isrc/
FLEX = flex
BISON = bison
MKDIR_P = mkdir -p
OUT_DIR = src/generacion
EXEC = compiler

OBJS = $(OUT_DIR)/lex.yy.o $(OUT_DIR)/y.tab.o $(OUT_DIR)/symbol_table.o $(OUT_DIR)/node.o $(OUT_DIR)/codegen.o $(OUT_DIR)/main.o

all: directories $(EXEC)

directories: ${OUT_DIR}

${OUT_DIR}:
	${MKDIR_P} ${OUT_DIR}

$(EXEC): $(OBJS)
	$(CC) -o $@ $(OBJS) -lcomdlg32

$(OUT_DIR)/y.tab.o $(OUT_DIR)/y.tab.h: src/syntax.y
	$(BISON) -yd -o $(OUT_DIR)/y.tab.c src/syntax.y
	$(CC) $(CFLAGS) -c $(OUT_DIR)/y.tab.c -o $(OUT_DIR)/y.tab.o

$(OUT_DIR)/lex.yy.o: src/lex.l $(OUT_DIR)/y.tab.h
	$(FLEX) -o $(OUT_DIR)/lex.yy.c src/lex.l
	$(CC) $(CFLAGS) -c $(OUT_DIR)/lex.yy.c -o $@

$(OUT_DIR)/symbol_table.o: src/symbol_table.c src/symbol_table.h
	$(CC) $(CFLAGS) -c src/symbol_table.c -o $@

$(OUT_DIR)/codegen.o: src/codegen.c src/codegen.h
	$(CC) $(CFLAGS) -c src/codegen.c -o $@

$(OUT_DIR)/node.o: src/node.c src/node.h
	$(CC) $(CFLAGS) -c src/node.c -o $@
	
$(OUT_DIR)/main.o: src/main.c src/codegen.h
	$(CC) $(CFLAGS) -c src/main.c -o $@

clean:
	rm -f $(OUT_DIR)/*.o $(OUT_DIR)/*.c $(OUT_DIR)/*.h $(EXEC)

clean_docs:
	@echo "Eliminando la carpeta src/docs..."
	rm -rf src/docs

# Regla para generar la documentación
generate_docs:
	@echo "Generando la documentación con Doxygen..."
	doxygen src/Doxyfile $(EXEC)

# Regla para abrir la documentación
open_docs:
	@echo "Abriendo la documentación en el navegador..."
	start docs/html/index.html
	
# Regla principal para documentación que limpia, genera y abre la documentación
docs: clean_docs generate_docs open_docs


.PHONY: all clean directories
