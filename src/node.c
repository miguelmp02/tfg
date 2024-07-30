#include "node.h"
#include <stdlib.h>
#include <string.h>
#include "src/generacion/y.tab.h"

extern int yylineno;

ASTNode* root = NULL;

ASTNode* get_ast_root() {
    return root;
}

void set_ast_root(ASTNode* new_root) {
    root = new_root;
}

struct ASTNode* create_identifier_node(char* identifier) {
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    if (node) {
        node->type = NODE_IDENTIFIER;
        node->data.sval = strdup(identifier); // Asegúrate de que ASTNode tiene un campo `sval` para char*
    }
    return node;
}

struct ASTNode* create_declaration_node(char* type, char* identifier) {
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    if (node == NULL) {
        return NULL;
    }
    node->type = NODE_DECLARATION; 
    node->data.declaration.type = strdup(type);
    node->data.declaration.identifier = strdup(identifier);
    return node;
}
struct ASTNode* create_if_node(struct ASTNode* condition, struct ASTNode* trueBranch, struct ASTNode* falseBranch) {
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    if (node) {
        node->type = NODE_IF;
        node->data.ifExpr.condition = condition;
        node->data.ifExpr.trueBranch = trueBranch;
        node->data.ifExpr.falseBranch = falseBranch;
    }
    return node;
}
struct ASTNode* create_while_node(struct ASTNode* condition, struct ASTNode* body) {
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    if (node) {
        node->type = NODE_WHILE;
        node->data.whileExpr.condition = condition;
        node->data.whileExpr.body = body;
    }
    return node;
}
struct ASTNode* create_for_node(struct ASTNode* init, struct ASTNode* cond, struct ASTNode* iter, struct ASTNode* body) {
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    if (node) {
        node->type = NODE_FOR;
        node->data.forLoop.init = init;
        node->data.forLoop.cond = cond;
        node->data.forLoop.iter = iter;
        node->data.forLoop.body = body;
    }
    return node;
}
struct ASTNode* create_function_call_node(char* functionName, ASTNode** arguments, int argCount) {
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    if (node) {
        node->type = NODE_FUNCTION_CALL;
        node->data.functionCall.functionName = strdup(functionName);
        node->data.functionCall.arguments = arguments;
        node->data.functionCall.argCount = argCount;
    }
    return node;
}
struct ASTNode* create_printf_node(char* identifier) {
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    if (node) {
        node->type = NODE_PRINTF;
        node->data.identifier = strdup(identifier);  // Asegúrate de que el campo `identifier` exista en `ASTNode`
    }
    return node;
}
struct ASTNode* create_constant_node(int value) {
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    if (node) {
        node->type = NODE_CONSTANT;
        node->data.ival = value;
    }
    return node;
}
struct ASTNode* create_assignment_node(char* identifier, struct ASTNode* value) {
    if (!identifier || !value) {
        return NULL;
    }
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    if (!node) {
        return NULL;
    }
    node->type = NODE_ASSIGNMENT;
    node->data.assignment.identifier = strdup(identifier);
    node->data.assignment.value = value;
    return node;
}

struct ASTNode* create_binary_op_node(char* op, struct ASTNode* left, struct ASTNode* right) {
    if (!left || !right) {
        return NULL;
    }
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    if (!node) {
        return NULL;
    }
    node->type = NODE_BINARY_OP;
    node->data.binary.op = strdup(op);
    node->data.binary.left = left;
    node->data.binary.right = right;
    return node;
}

struct ASTNode* combine_nodes(struct ASTNode* a, struct ASTNode* b) {
    if (!a) return b;
    if (!b) return a;

    struct ASTNode* last = a;
    while (last && last->sibling) {
        last = last->sibling;  
    }

    if (last) {
        last->sibling = b; 
    }
    
    return a;
}
void free_tree(ASTNode* node) {
    if (node == NULL) return;
    printf("Liberando nodo de tipo %d en la línea %d.\n", node->type, yylineno);
    switch (node->type) {
        case NODE_BINARY_OP:
        case NODE_ASSIGNMENT:
        case NODE_IF:
            free_tree(node->data.ifExpr.condition);
            free_tree(node->data.ifExpr.trueBranch);
            free_tree(node->data.ifExpr.falseBranch);
            break;
        case NODE_WHILE:
        case NODE_FOR:
            free_tree(node->data.whileExpr.condition);
            free_tree(node->data.whileExpr.body);
            break;
        case NODE_FUNCTION_CALL:
            // Suponiendo que también necesitas liberar una lista de argumentos
            break;
        case NODE_PRINTF:
        case NODE_IDENTIFIER:
        case NODE_CONSTANT:
        case NODE_DECLARATION:
            free(node->data.identifier);  // Asumiendo que estas son cadenas dinámicas
            break;
    }

    free(node);  // Finalmente, libera el nodo mismo
}
