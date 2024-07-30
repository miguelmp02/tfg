#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "node.h"  // Estructuras del AST

typedef enum {
    TYPE_INT,
    TYPE_BOOLEAN,
    TYPE_ARRAY,
    TYPE_ERROR  // Para manejar errores de tipo
} DataType;

// Estructura para representar los atributos de los símbolos
typedef struct Symbol {
    char *name;
    DataType type;
    int defined; // Flag para verificar si el símbolo ha sido definido
} Symbol;

void check_variable_declaration(char *varName, int line);
void check_function_declaration(char *functionName, int line);
void check_type_compatibility(DataType type1, DataType type2, int line);
void process_assignment(char *varName, DataType expressionType, int line);
void eval_expression(int exprValue, int line);

#endif // SEMANTIC_H
