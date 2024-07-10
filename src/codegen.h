#ifndef CODEGEN_H
#define CODEGEN_H

#include "node.h"  // Asumimos que node.h define la estructura para los nodos del AST.

// Definición de la estructura Cuadrupla para manejar las operaciones intermedias.
typedef struct {
    char* operador;
    char* operando1;
    char* operando2;
    char* resultado;
} Cuadrupla;

// Funciones públicas que deben ser accesibles desde otros módulos del compilador.

// Inicia la generación de código a partir del árbol sintáctico abstracto.
void generate_code_from_tree(struct ASTNode* root);

// Agrega una cuádrupla al conjunto de cuádruplas gestionadas por este módulo.
void agregar_cuadrupla(char* operador, char* operando1, char* operando2, char* resultado);

// Imprime todas las cuádruplas generadas para depuración.
void print_cuadruplas();

#endif // CODEGEN_H
