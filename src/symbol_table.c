#include "symbol_table.h"

// Función hash simple
static int hash(const char *key, int size) {
    unsigned long int hashval = 0;
    int i = 0;
    while (hashval < ULONG_MAX && i < strlen(key)) {
        hashval = hashval << 8;
        hashval += key[i];
        i++;
    }
    return hashval % size;
}

// Crear tabla de símbolos
SymbolTable *create_symbol_table(int size) {
    SymbolTable *newTable;
    if (size < 1) return NULL; // Tamaño inválido de la tabla

    // Intentar asignar memoria para la estructura de la tabla
    if ((newTable = malloc(sizeof(SymbolTable))) == NULL) {
        return NULL;
    }

    // Intentar asignar memoria para la tabla en sí
    if ((newTable->symbols = malloc(sizeof(Symbol *) * size)) == NULL) {
        return NULL;
    }

    // Inicializar los elementos de la tabla
    for (int i = 0; i < size; i++) newTable->symbols[i] = NULL;
    newTable->size = size;

    return newTable;
}

// Agregar un símbolo a la tabla
Symbol *add_symbol(SymbolTable *table, const char *name, const char *type, int scope) {
    int bin = 0;
    Symbol *newSymbol = NULL;
    Symbol *next = NULL;
    Symbol *last = NULL;

    bin = hash(name, table->size);

    next = table->symbols[bin];

    while (next != NULL && next->name != NULL && strcmp(name, next->name) > 0) {
        last = next;
        next = next->next;
    }

    // Ya hay un elemento. Reemplazar ese símbolo.
    if (next != NULL && next->name != NULL && strcmp(name, next->name) == 0) {
        free(next->type);
        next->type = strdup(type);
        next->scope = scope;
    } else {
        newSymbol = malloc(sizeof(Symbol));
        newSymbol->name = strdup(name);
        newSymbol->type = strdup(type);
        newSymbol->scope = scope;
        newSymbol->next = next;

        if (last == NULL) {
            table->symbols[bin] = newSymbol;
        } else {
            last->next = newSymbol;
        }
    }

    return newSymbol;
}

// Buscar un símbolo en la tabla
Symbol *find_symbol(SymbolTable *table, const char *name, int scope) {
    int bin = hash(name, table->size);
    Symbol *symbol = table->symbols[bin];
    while (symbol != NULL && !(strcmp(symbol->name, name) == 0 && symbol->scope == scope)) {
        symbol = symbol->next;
    }
    return symbol;
}

// Liberar la tabla de símbolos
void free_symbol_table(SymbolTable *table) {
    Symbol *symbol, *tmp;
    if (table == NULL) return;

    for (int i = 0; i < table->size; i++) {
        symbol = table->symbols[i];
        while (symbol != NULL) {
            tmp = symbol;
            symbol = symbol->next;
            free(tmp->name);
            free(tmp->type);
            free(tmp);
        }
    }
    free(table->symbols);
    free(table);
}

// Función para imprimir la tabla de símbolos (para depuración)
void print_symbol_table(SymbolTable *table) {
    Symbol *symbol;
    for (int i = 0; i < table->size; i++) {
        symbol = table->symbols[i];
        while (symbol != NULL) {
            printf("Symbol: %s, Type: %s, Scope: %d\n", symbol->name, symbol->type, symbol->scope);
            symbol = symbol->next;
        }
    }
}
