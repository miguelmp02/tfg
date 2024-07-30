#include "semantic.h"
#include <stdio.h>

extern int yylineno; // Importa la línea actual del análisis léxico

void check_variable_declaration(char *varName, int line) {
    // Ejemplo de implementación
    printf("Semantic check at line %d: Variable '%s' checked.\n", line, varName);
}

void check_function_declaration(char *functionName, int line) {
    // Similar a check_variable_declaration
}

void check_type_compatibility(DataType type1, DataType type2, int line) {
    if (type1 != type2) {
        printf("Type mismatch error at line %d: Type %d is not compatible with Type %d.\n", line, type1, type2);
    }
}

void process_assignment(char *varName, DataType expressionType, int line) {
    printf("Assignment processed at line %d: Variable '%s'.\n", line, varName);
}

void eval_expression(int exprValue, int line) {
    printf("Expression evaluated at line %d: Value %d.\n", line, exprValue);
}
