#include "symbol_table.h"
#include <stdlib.h>
#include <string.h>

Symbol *symbolTable = NULL;  // Definición de symbolTable

void insert_symbol(char *name, DataType type) {
    Symbol *s = malloc(sizeof(Symbol));
    s->name = strdup(name);
    s->type = type;
    s->next = symbolTable;
    symbolTable = s;
}

Symbol *find_symbol(char *name) {
    for (Symbol *s = symbolTable; s; s = s->next) {
        if (strcmp(s->name, name) == 0) {
            return s;
        }
    }
    return NULL;
}
