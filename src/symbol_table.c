#include "symbol_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Symbol *symbolTable = NULL;

void insert_symbol(char *name, DataType type) {
    Symbol *existing_symbol = find_symbol(name);
    if (existing_symbol) {
        fprintf(stderr, "Error semántico: Error identificador \"%s\" ya declarado previamente.\n", name);
        return;
    }
    Symbol *s = malloc(sizeof(Symbol));
    if (s == NULL) {
        fprintf(stderr, "Error al asignar memoria para el nuevo símbolo.\n");
        return;
    }
    s->name = strdup(name);
    s->type = type;
    s->next = symbolTable;
    symbolTable = s;
}
DataType convert_data_type(char* type_str) {
    if (strcmp(type_str, "int") == 0) return TYPE_INT;
    if (strcmp(type_str, "float") == 0) return TYPE_FLOAT;
    if (strcmp(type_str, "char") == 0) return TYPE_CHAR;
    if (strcmp(type_str, "string") == 0) return TYPE_STRING;
    return TYPE_INT;
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