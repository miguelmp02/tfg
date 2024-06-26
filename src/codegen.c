#include "codegen.h"
#include <stdio.h>

void init_code_generation() {
    printf(".section .text\n");
}

void finalize_code_generation() {
    printf("end\n");
}

void generate_variable_declaration(const Symbol *symbol) {
    printf("%s: .space 4\n", symbol->name);  // Para un entero, por ejemplo
}

void generate_function_definition(const Symbol *symbol) {
    // Implementación dependiendo del backend de código objetivo
    printf("%s:\n", symbol->name);
    printf("    # Código de la función\n");
}

void generate_code() {
    Symbol *s = symbolTable;
    while (s != NULL) {
        if (s->type == TYPE_INT) { // Suponiendo un tipo simple
            generate_variable_declaration(s);
        }
        s = s->next;
    }
    finalize_code_generation();
}
