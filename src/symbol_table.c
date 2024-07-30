#include "symbol_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Symbol *symbolTable = NULL;

void insert_symbol(char *name, DataType type) {
    Symbol *s = malloc(sizeof(Symbol));
    s->name = strdup(name);
    s->type = type;
    s->next = symbolTable;
    symbolTable = s;
    //printf("Insertado: %s\n", name);
}

Symbol *find_symbol(char *name) {
    for (Symbol *s = symbolTable; s; s = s->next) {
        if (strcmp(s->name, name) == 0) {
            return s;
        }
    }
    return NULL;
}
int print_symbol_table() {
    Symbol *s = symbolTable;
    if (s == NULL) {
        printf("La tabla de símbolos está vacía.\n");
        return 0; 
    }
    //printf("Tabla de Símbolos:\n");
    while (s != NULL) {
        //printf("Nombre: %s, Tipo: %d\n", s->name, s->type);
        s = s->next;
    }
    return 1; // Indica éxito
}