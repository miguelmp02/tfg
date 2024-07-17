#ifndef CODEGEN_H
#define CODEGEN_H

#include "node.h"  // Asumiendo que node.h contiene la definición de ASTNode

// Estructura para representar una cuádrupla
typedef struct Cuadrupla {
    char* op;     // Operador
    char* arg1;   // Primer argumento
    char* arg2;   // Segundo argumento
    char* resultado;  // Resultado
} Cuadrupla;

// Funciones para la generación de cuádruplas
void agregar_cuadrupla(char* op, char* arg1, char* arg2, char* resultado);
void generar_codigo_desde_arbol(struct ASTNode* nodo);
void imprimir_cuadruplas();

#endif // CODEGEN_H
