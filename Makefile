CC = gcc
CFLAGS = -Isrc -g -Wall
LFLAGS = -lfl

BIN = compilador
SRC_DIR = src
OBJ_DIR = obj

SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/symbol_table.c
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LEX_SRC = $(SRC_DIR)/alfa.l
YACC_SRC = $(SRC_DIR)/alfa.y
LEX_OBJ = $(LEX_SRC:$(SRC_DIR)/%.l=$(OBJ_DIR)/%.o)
YACC_OBJ = $(YACC_SRC:$(SRC_DIR)/%.y=$(OBJ_DIR)/%.o)

all: bison flex $(BIN)

bison:
	bison -d -o $(SRC_DIR)/alfa.tab.c $(YACC_SRC)

flex:
	flex -o $(SRC_DIR)/lex.yy.c $(LEX_SRC)

$(BIN): $(OBJECTS) $(LEX_OBJ) $(YACC_OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LEX_OBJ): $(LEX_SRC) $(YACC_SRC)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/lex.yy.c -o $(LEX_OBJ)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/alfa.tab.c -o $(YACC_OBJ)

clean:
	rm -f $(BIN) $(OBJ_DIR)/*.o $(SRC_DIR)/lex.yy.c $(SRC_DIR)/alfa.tab.c $(SRC_DIR)/alfa.tab.h

.PHONY: all clean bison flex
