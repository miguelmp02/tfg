#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_CHAR,
    TYPE_STRING
    // Agrega más tipos según sea necesario
} DataType;

typedef struct Symbol {
    char *name;          
    DataType type;
    int value;           // Agrega un campo para almacenar valores
    struct Symbol *next; 
} Symbol;

extern Symbol *symbolTable;  // Declaración externa de symbolTable

void insert_symbol(char *name, DataType type);
Symbol *find_symbol(char *name);

#endif // SYMBOL_TABLE_H
