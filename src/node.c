#include "node.h"
#include <stdlib.h>
#include <string.h>
#include "src/generacion/y.tab.h"

ASTNode* root = NULL;

ASTNode* get_ast_root() {
    return root;
}

void set_ast_root(ASTNode* new_root) {
    root = new_root;
}

ASTNode* create_constant_node(int value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_CONSTANT;
    node->value = value;
    return node;
}

ASTNode* create_identifier_node(char* identifier) {
    ASTNode* node = malloc(sizeof(ASTNode));
    if (node == NULL) {
        return NULL; // Manejo de errores en caso de fallo de malloc
    }
    // Suponiendo que node->identifier es un campo en ASTNode
    node->identifier = strdup(identifier);
    return node;
}

ASTNode* create_binary_op_node(char* op, ASTNode* left, ASTNode* right) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_BINARY_OP;
    node->binary.op = op;
    node->binary.left = left;
    node->binary.right = right;
    return node;
}

ASTNode* create_unary_op_node(char* op, ASTNode* operand) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_UNARY_OP;
    node->unary.op = op;
    node->unary.operand = operand;
    return node;
}
ASTNode* create_program_node(ASTNode* left, ASTNode* right) {
    ASTNode* node = malloc(sizeof(ASTNode));
    if (!node) return NULL;  // Manejo de errores en caso de fallo de malloc

    node->type = NODE_PROGRAM;
    node->binary.left = left;
    node->binary.right = right;
    return node;
}
ASTNode* create_assignment_node(char* identifier, ASTNode* expression) {
    ASTNode* node = malloc(sizeof(ASTNode));
    if (!node) {
        return NULL;  // Manejo de errores en caso de fallo de malloc
    }
    node->type = NODE_ASSIGNMENT;
    node->binary.left = (ASTNode*)malloc(sizeof(ASTNode));
    node->binary.left->type = NODE_IDENTIFIER;
    node->binary.left->identifier = strdup(identifier);
    node->binary.right = expression;
    node->binary.op = strdup("=");  // Operador de asignación
    return node;
}
void free_tree(ASTNode* root) {
    if (root == NULL) return;

    // Asegúrate de liberar cualquier cadena u otro recurso dinámico en el nodo
    if (root->type == NODE_IDENTIFIER) {
        free(root->identifier);
    }

    // Finalmente, libera el nodo mismo
    free(root);
}
