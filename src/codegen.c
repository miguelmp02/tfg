#include "codegen.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Asumiendo un tamaño máximo para el arreglo de cuádruplas
#define MAX_CUADRUPLES 1024
Cuadrupla cuadruplas[MAX_CUADRUPLES];
int contador_cuadruplas = 0;

// Agregar una cuádrupla al arreglo de cuádruplas
void agregar_cuadrupla(char* op, char* arg1, char* arg2, char* resultado) {
    if (contador_cuadruplas < MAX_CUADRUPLES) {
        Cuadrupla c = {strdup(op), strdup(arg1), strdup(arg2), strdup(resultado)};
        cuadruplas[contador_cuadruplas++] = c;
    }
}

// Generar código desde el árbol AST
void generar_codigo_desde_arbol(struct ASTNode* nodo) {
    if (nodo == NULL) return;

    char temp[100];  // Para generar nombres temporales para resultados intermedios

    switch (nodo->type) {
    /*    case NODE_ASSIGNMENT:
            // Suponiendo que nodo->data.assignment.expression es un char* o similar
            agregar_cuadrupla("=", nodo->data.assignment.identifier, "", nodo->data.assignment.expression);
            break;

        case NODE_BINARY_OP:
            // Generar código para la expresión izquierda y derecha primero
            generar_codigo_desde_arbol(nodo->data.binary.left);
            generar_codigo_desde_arbol(nodo->data.binary.right);
            // Suponiendo que se crean temporales para almacenar resultados intermedios
            sprintf(temp, "t%d", contador_cuadruplas);  // Crear un nuevo temporal
            agregar_cuadrupla(nodo->data.binary.op, 
                              nodo->data.binary.left->data.identifier,  // asumiendo que estos son identificadores o temporales
                              nodo->data.binary.right->data.identifier, 
                              temp);
            break;

        case NODE_UNARY_OP:
            // Generar código para el operando primero
            generar_codigo_desde_arbol(nodo->data.unary.operand);
            sprintf(temp, "t%d", contador_cuadruplas);
            agregar_cuadrupla(nodo->data.unary.op, 
                              nodo->data.unary.operand->data.identifier, 
                              "", 
                              temp);
            break;
        */
        case NODE_IF:
            // Generar código para la condición
            generar_codigo_desde_arbol(nodo->data.ifExpr.condition);
            // Usar una etiqueta para manejar el flujo de control
            agregar_cuadrupla("ifFalse", nodo->data.ifExpr.condition->data.identifier, "goto", "L1");
            // Código para el cuerpo del if
            generar_codigo_desde_arbol(nodo->data.ifExpr.trueBranch);
            agregar_cuadrupla("goto", "L2", "", "");
            agregar_cuadrupla("label", "L1", "", "");
            // Código para el else si existe
            if (nodo->data.ifExpr.falseBranch) {
                generar_codigo_desde_arbol(nodo->data.ifExpr.falseBranch);
            }
            agregar_cuadrupla("label", "L2", "", "");
            break;

        case NODE_WHILE:
            // Similar al if, pero con bucles
            agregar_cuadrupla("label", "L1", "", "");
            generar_codigo_desde_arbol(nodo->data.whileExpr.condition);
            agregar_cuadrupla("ifFalse", nodo->data.whileExpr.condition->data.identifier, "goto", "L2");
            generar_codigo_desde_arbol(nodo->data.whileExpr.body);
            agregar_cuadrupla("goto", "L1", "", "");
            agregar_cuadrupla("label", "L2", "", "");
            break;

        case NODE_DECLARATION:
            // No se genera una cuádrupla para una declaración típica, pero puedes necesitar inicializar variables
            if (nodo->data.declaration.identifier != NULL) {
                generar_codigo_desde_arbol(nodo->data.declaration.identifier);
                sprintf(temp, "t%d", contador_cuadruplas);
                agregar_cuadrupla("=", nodo->data.declaration.identifier, temp, "");
            }
            if (nodo->data.declaration.type != NULL) {
                generar_codigo_desde_arbol(nodo->data.declaration.type);
                sprintf(temp, "t%d", contador_cuadruplas);
                agregar_cuadrupla("=", nodo->data.declaration.type, temp, "");
            }
            break;

        /*case NODE_FUNCTION_CALL:
            // Si la función retorna un valor, manejar el resultado
            if (nodo->data.functionCall.hasReturnValue) {
                sprintf(temp, "t%d", contador_cuadruplas);
                agregar_cuadrupla("call", nodo->data.functionCall.functionName, "", temp);
            } else {
                agregar_cuadrupla("call", nodo->data.functionCall.functionName, "", "");
            }
            // Generar cuádruplas para cada argumento
            for (int i = 0; i < nodo->data.functionCall.argCount; i++) {
                generar_codigo_desde_arbol(nodo->data.functionCall.arguments[i]);
            }
            break;

        case NODE_PRINTF:
            // Generar cuádruplas para cada argumento en una llamada printf
            for (int i = 0; i < nodo->data.funcCall.argCount; i++) {
                generar_codigo_desde_arbol(nodo->data.funcCall.arguments[i]);
                sprintf(temp, "param t%d", contador_cuadruplas);
                agregar_cuadrupla("param", nodo->data.funcCall.arguments[i]->data.identifier, "", temp);
            }
            agregar_cuadrupla("call", "printf", "", "");
            break; */


        default:
            fprintf(stderr, "Tipo de nodo desconocido\n");
            break;
    }
}

// Imprimir todas las cuádruplas generadas
void imprimir_cuadruplas() {
    for (int i = 0; i < contador_cuadruplas; i++) {
        printf("%s, %s, %s, %s\n",
               cuadruplas[i].op,
               cuadruplas[i].arg1,
               cuadruplas[i].arg2,
               cuadruplas[i].resultado);
    }
}
