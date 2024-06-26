#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "symbol_table.h"  

void eval_expression(int exprValue);

// Define aquí cualquier estructura de datos que necesites para el análisis semántico
typedef struct {
    // Estructuras de ejemplo
    int dataType;
    char *identifier;
} SemanticAttributes;

// Funciones para el análisis semántico
void check_variable_declaration(char *varName);
void check_function_declaration(char *functionName);
void check_type_compatibility(int type1, int type2);
void process_assignment(char *varName, DataType expressionType);

#endif // SEMANTIC_H
