#include "semantic.h"
#include <stdio.h>

// Verifica si una variable ha sido declarada previamente
void check_variable_declaration(char *varName) {
    Symbol *var = find_symbol(varName);
    if (!var) {
        printf("Semantic Error: Variable '%s' not declared.\n", varName);
        // Aquí podrías lanzar una excepción o manejar el error de manera adecuada
    }
}

// Verifica si una función ha sido declarada previamente
void check_function_declaration(char *functionName) {
    Symbol *func = find_symbol(functionName);
    if (!func) {
        printf("Semantic Error: Function '%s' not declared.\n", functionName);
        // Aquí podrías lanzar una excepción o manejar el error de manera adecuada
    }
}

// Comprueba la compatibilidad de dos tipos para una operación
void check_type_compatibility(int type1, int type2) {
    if (type1 != type2) {
        printf("Semantic Error: Type mismatch, types %d and %d are not compatible.\n", type1, type2);
        // Aquí podrías lanzar una excepción o manejar el error de manera adecuada
    }
}

// Procesa una asignación verificando la compatibilidad de tipos
void process_assignment(char *varName, DataType expressionType) {
    Symbol *var = find_symbol(varName);
    if (var) {
        if (var->type != expressionType) {
            printf("Semantic Error: Type mismatch in assignment to '%s'. Expected type %d, got type %d.\n", varName, var->type, expressionType);
            // Manejar error
        }
    } else {
        printf("Semantic Error: Variable '%s' not declared.\n", varName);
        // Manejar error
    }
}
