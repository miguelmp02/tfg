#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_CHAR,
    TYPE_STRING
} DataType;

typedef struct Symbol {
    char *name;          
    DataType type;
    int value;          
    struct Symbol *next; 
} Symbol;

extern Symbol *symbolTable; 

void insert_symbol(char *name, DataType type);
Symbol *find_symbol(char *name);
int print_symbol_table();

#endif 
