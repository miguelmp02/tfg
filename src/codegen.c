#include "codegen.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definimos un tamaño máximo para el almacenamiento de cuádruplas
#define MAX_CUADRUPLAS 1000

Cuadrupla cuadruplas[MAX_CUADRUPLAS];
int numero_de_cuadruplas = 0;

// Función para agregar cuádruplas al almacenamiento
void agregar_cuadrupla(char* operador, char* operando1, char* operando2, char* resultado) {
    if (numero_de_cuadruplas >= MAX_CUADRUPLAS) {
        fprintf(stderr, "Límite de cuádruplas alcanzado.\n");
        return;
    }
    cuadruplas[numero_de_cuadruplas++] = (Cuadrupla){strdup(operador), strdup(operando1), strdup(operando2), strdup(resultado)};
}

// Función para imprimir todas las cuádruplas generadas
void print_cuadruplas() {
    for (int i = 0; i < numero_de_cuadruplas; i++) {
        printf("%s, %s, %s, %s\n",
            cuadruplas[i].operador,
            cuadruplas[i].operando1,
            cuadruplas[i].operando2,
            cuadruplas[i].resultado);
    }
}

void generate_code_from_tree(ASTNode* node) {
    if (!node) return;

    switch (node->type) {
        case NODE_BINARY_OP: {
            char* tmp = malloc(20);
            sprintf(tmp, "t%d", numero_de_cuadruplas);  // Crear un nuevo nombre temporal para el resultado

            generate_code_from_tree(node->binary.left);
            generate_code_from_tree(node->binary.right);
            agregar_cuadrupla(node->binary.op, node->binary.left->result, node->binary.right->result, tmp);
            node->result = tmp;  // Actualizar el resultado del nodo actual al temporal creado
            break;
        }
        case NODE_ASSIGNMENT: {
            generate_code_from_tree(node->binary.right);
            agregar_cuadrupla(":=", node->binary.right->result, "", node->binary.left->identifier);
            break;
        }
        case NODE_IDENTIFIER:
        case NODE_CONSTANT: {
            node->result = strdup(node->identifier);  // Asumiendo que identificador también se usa para constantes
            break;
        }
        default:
            fprintf(stderr, "Tipo de nodo desconocido.\n");
    }
}

