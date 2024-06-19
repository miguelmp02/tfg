#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Estructuras de datos
typedef struct Symbol {
    char *name;
    char *type;
    int scope;
    struct Symbol *next;
} Symbol;

typedef struct {
    Symbol **symbols;
    int size;
} SymbolTable;

// Funciones de la tabla de símbolos
SymbolTable *create_symbol_table(int size);
void free_symbol_table(SymbolTable *table);
Symbol *add_symbol(SymbolTable *table, const char *name, const char *type, int scope);
Symbol *find_symbol(SymbolTable *table, const char *name, int scope);
void print_symbol_table(SymbolTable *table);

#endif // SYMBOL_TABLE_H
