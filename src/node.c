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
    if (node == NULL) {
        return NULL;
    }
    node->type = NODE_IDENTIFIER;
    node->data.sval = strdup(identifier); // Asegúrate de que ASTNode tiene un campo `sval` para char*
    node->next = NULL;
    return node;
}

struct ASTNode* create_declaration_node(char* type, char* identifier, int pointer_level) {
    if (type == NULL || identifier == NULL) {
        return NULL;
    }
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    if (node == NULL) {
        return NULL;
    }
    node->type = NODE_DECLARATION;
    node->data.declaration.type = strdup(type);
    node->data.declaration.identifier = strdup(identifier);
    node->data.declaration.pointer_level = pointer_level; 
    node->next = NULL;
    return node;
}

struct ASTNode* create_if_node(struct ASTNode* condition, struct ASTNode* trueBranch, struct ASTNode* falseBranch) {
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    if (node == NULL) {
        return NULL;
    }
    node->type = NODE_IF;
    node->data.ifExpr.condition = condition;
    node->data.ifExpr.trueBranch = trueBranch;
    node->data.ifExpr.falseBranch = falseBranch;
    node->next = NULL;
    return node;
}

struct ASTNode* create_while_node(struct ASTNode* condition, struct ASTNode* body) {
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    if (node == NULL) {
        return NULL;
    }
    node->type = NODE_WHILE;
    node->data.whileExpr.condition = condition;
    node->data.whileExpr.body = body;
    node->next = NULL;
    return node;
}

struct ASTNode* create_for_node(struct ASTNode* cond, struct ASTNode* body) {
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    if (node == NULL) {
        return NULL;
    }
    node->type = NODE_FOR;
    node->data.forLoop.cond = cond;
    node->data.forLoop.body = body;
    node->next = NULL;
    return node;
}

struct ASTNode* create_array_node(char* type, struct ASTNode* dimensions, char* identifier) {
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    if (node == NULL) {
        return NULL;
    }
    node->type = NODE_ARRAY;
    node->data.array.type = strdup(type);
    node->data.array.dimensions = dimensions;
    node->data.array.identifier = strdup(identifier);
    node->next = NULL;
    return node;
}

struct ASTNode* create_dimension_list(struct ASTNode* first, struct ASTNode* next) {
    struct ASTNode* list = malloc(sizeof(struct ASTNode));
    if (list == NULL) {
        return NULL;
    }
    list->type = NODE_DIMENSION_LIST;
    list->data.dimensions.first = first;
    list->data.dimensions.next = next;
    list->next = NULL;
    return list;
}

struct ASTNode* create_array_access_node(char* arrayName, struct ASTNode* index) {
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    if (node == NULL) {
        return NULL;
    }
    node->type = NODE_ARRAY_ACCESS;
    node->data.arrayAccess.arrayName = strdup(arrayName);
    node->data.arrayAccess.index = index;
    node->next = NULL;
    return node;
}

struct ASTNode* combine_expressions(struct ASTNode* left, struct ASTNode* right) {
    if (left == NULL || right == NULL) {
        fprintf(stderr, "Error: Intento de combinar expresiones nulas.\n");
        return NULL;
    }

    struct ASTNode* combined_node = malloc(sizeof(struct ASTNode));
    if (combined_node == NULL) {
        return NULL;
    }
    combined_node->type = NODE_BINARY_OP; 
    combined_node->data.binary.left = left;
    combined_node->data.binary.right = right;
    combined_node->data.binary.op = strdup("+");  // Ejemplo: operación de suma
    combined_node->next = NULL;  // Asegurar que el campo 'next' está limpio

    return combined_node;
}

ASTNode* create_function_call_node(char* functionName, ASTNode* arguments) {
    ASTNode* node = malloc(sizeof(ASTNode));
    if (node == NULL) {
        return NULL;
    }
    node->type = NODE_FUNCTION_CALL;
    node->data.functionCall.functionName = strdup(functionName);
    node->data.functionCall.arguments = arguments;
    node->next = NULL;
    return node;
}

struct ASTNode* create_argument_node(struct ASTNode* expr) {
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    if (node == NULL) {
        return NULL;
    }
    node->type = NODE_ARGUMENT;
    node->data.expression = expr;
    node->next = NULL;
    return node;
}

struct ASTNode* create_printf_node(char* identifier) {
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    if (node == NULL) {
        return NULL;
    }
    node->type = NODE_PRINTF;
    node->data.identifier = strdup(identifier);
    node->next = NULL;
    return node;
}

struct ASTNode* create_scanf_node(char* identifier) {
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    if (node == NULL) {
        return NULL;
    }
    node->type = NODE_SCANF;
    node->data.identifier = strdup(identifier);
    node->next = NULL;
    return node;
}   

struct ASTNode* create_scanf_node_array(struct ASTNode* array_access) {
    if (array_access == NULL || array_access->type != NODE_IDENTIFIER) {
        return NULL;
    }
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    if (node == NULL) {
        return NULL;
    }
    node->type = NODE_SCANF;
    node->data.identifier = strdup(array_access->data.identifier);
    node->next = NULL;
    return node;
}

struct ASTNode* create_constant_node(int value) {
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    if (node == NULL) {
        return NULL;
    }
    node->type = NODE_CONSTANT;
    node->data.ival = value;
    node->next = NULL;
    return node;
}

struct ASTNode* create_assignment_node_ampersand(char* identifier, char* target) {
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    if (node == NULL) {
        return NULL;
    }
    node->type = NODE_ASSIGNMENT_AMPERSAND;
    node->data.assignment.identifier = strdup(identifier);
    node->data.assignment.value = create_identifier_node(target);
    node->next = NULL;
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
    node->next = NULL;
    return node;
}

struct ASTNode* create_assignment_node_array(ASTNode* array_access_node, ASTNode* expression) {
    if (!array_access_node || !expression) {
        return NULL;
    }
    char* identifier = extract_identifier(array_access_node);

    ASTNode* node = malloc(sizeof(ASTNode));
    if (node == NULL) {
        return NULL;
    }
    node->type = NODE_ASSIGNMENT;
    node->data.assignment.identifier = strdup(identifier);
    node->data.assignment.value = expression;
    node->next = NULL;
    return node;
}

char* extract_identifier(struct ASTNode* node) {
    if (node && node->type == NODE_IDENTIFIER) {
        return strdup(node->data.identifier);
    }
    return NULL;
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
    node->next = NULL;
    return node;
}

struct ASTNode* combine_nodes(struct ASTNode* a, struct ASTNode* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    struct ASTNode* last = a;
    last->next = b;

    return a;
}

ASTNode* create_function_node(char* type, char* identifier, ASTNode* parameters, ASTNode* body) {
    ASTNode* node = malloc(sizeof(ASTNode));
    if (node == NULL) {
        return NULL;
    }
    node->type = NODE_FUNCTION_DEFINITION;
    node->data.function.type = strdup(type);
    node->data.function.identifier = strdup(identifier);
    node->data.function.parameters = parameters;
    node->data.function.body = body;
    node->next = NULL;
    return node;
}

struct ASTNode* create_parameter_node(char* type, char* identifier) {
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    if (node == NULL) {
        return NULL;
    }
    node->type = NODE_PARAMETER;
    node->data.declaration.type = strdup(type);
    node->data.declaration.identifier = strdup(identifier);
    node->next = NULL;
    return node;
}

ASTNode* combine_parameter_nodes(ASTNode* a, ASTNode* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    struct ASTNode* current = a;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = b;

    return a;
}

ASTNode* combine_argument_nodes(ASTNode* a, ASTNode* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    struct ASTNode* current = a;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = b;

    return a;
}

ASTNode* create_return_node(char* identifier, ASTNode* expression) {
    ASTNode* node = malloc(sizeof(ASTNode));
    if (node == NULL) {
        return NULL;
    }
    node->type = NODE_RETURN;
    node->data.return_stmt.identifier = identifier ? strdup(identifier) : NULL;
    node->data.return_stmt.expression = expression;
    node->next = NULL;
    return node;
}

struct ASTNode* create_pointer_assignment_node(char* identifier, struct ASTNode* value) {
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    if (node == NULL) {
        return NULL;
    }
    node->type = NODE_POINTER_ASSIGNMENT;
    node->data.assignment.identifier = strdup(identifier);
    node->data.assignment.value = value;
    node->next = NULL;
    return node;
}

struct ASTNode* create_free_node(char* identifier) {
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    if (node == NULL) {
        return NULL;
    }
    node->type = NODE_FREE;
    node->data.identifier = strdup(identifier);
    node->next = NULL;
    return node;
}

ASTNode* create_pointer_node(int level) {
    struct ASTNode* node = malloc(sizeof(struct ASTNode));
    if (node == NULL) {
        return NULL; 
    }
    node->type = NODE_POINTER;
    node->data.pointer_level = level;
    node->next = NULL;
    return node;
}

ASTNode* increase_pointer_level(struct ASTNode* node) {
    if (node == NULL) {
        return NULL;
    }
    node->data.pointer_level += 1;
    return node;
}

void free_tree(ASTNode* node) {
    if (node == NULL) return;
    switch (node->type) {
        case NODE_BINARY_OP:
            free_tree(node->data.binary.left);
            free_tree(node->data.binary.right);
            free(node->data.binary.op);
            break;
        case NODE_ASSIGNMENT:
        case NODE_ASSIGNMENT_AMPERSAND:
            free(node->data.assignment.identifier);
            free_tree(node->data.assignment.value);
            break;
        case NODE_IF:
            free_tree(node->data.ifExpr.condition);
            free_tree(node->data.ifExpr.trueBranch);
            free_tree(node->data.ifExpr.falseBranch);
            break;
        case NODE_WHILE:
            free_tree(node->data.whileExpr.condition);
            free_tree(node->data.whileExpr.body);
            break;
        case NODE_FOR:
            free_tree(node->data.forLoop.cond);
            free_tree(node->data.forLoop.body);
            break;
        case NODE_FUNCTION_CALL:
            free(node->data.functionCall.functionName);
            // Suponiendo que también necesitas liberar una lista de argumentos
            free_tree(node->data.functionCall.arguments);
            break;
        case NODE_PRINTF:
        case NODE_SCANF:
        case NODE_IDENTIFIER:
        case NODE_CONSTANT:
        case NODE_DECLARATION:
            free(node->data.identifier);  // Asumiendo que estas son cadenas dinámicas
            break;
        case NODE_ARRAY:
            free(node->data.array.type);
            free(node->data.array.identifier);
            free_tree(node->data.array.dimensions);
            break;
        case NODE_DIMENSION_LIST:
            free_tree(node->data.dimensions.first);
            free_tree(node->data.dimensions.next);
            break;
        case NODE_ARRAY_ACCESS:
            free(node->data.arrayAccess.arrayName);
            free_tree(node->data.arrayAccess.index);
            break;
        case NODE_FUNCTION_DEFINITION:
            free(node->data.function.type);
            free(node->data.function.identifier);
            free_tree(node->data.function.parameters);
            free_tree(node->data.function.body);
            break;
        case NODE_RETURN:
            if (node->data.return_stmt.identifier != NULL) {
                free(node->data.return_stmt.identifier);
            }
            free_tree(node->data.return_stmt.expression);
            break;
        case NODE_POINTER:
            break;
    }
    free(node);  // Finalmente, libera el nodo mismo
}
