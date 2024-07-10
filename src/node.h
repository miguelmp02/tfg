#ifndef NODE_H
#define NODE_H

#include <stdlib.h>



// Enumeración para los diferentes tipos de nodos del AST
typedef enum {
    NODE_CONSTANT,
    NODE_IDENTIFIER,
    NODE_BINARY_OP,
    NODE_UNARY_OP,
    NODE_ASSIGNMENT,
    NODE_PROGRAM
} NodeType;

typedef struct ASTNode {
    NodeType type;             // Tipo de nodo
    union {
        int value;             // Usado para constantes
        char* identifier;      // Usado para identificadores
        struct {               // Usado para operaciones binarias
            struct ASTNode* left;
            struct ASTNode* right;
            char* op;          // Operador para la operación binaria
        } binary;
        struct {               // Usado para operaciones unarias
            struct ASTNode* operand;
            char* op;          // Operador para la operación unaria
        } unary;
    };  
    char* result;              // Para almacenar el resultado temporal de la expresión
} ASTNode;

extern ASTNode* root;  
ASTNode* parse(const char* filename);  // Función de análisis que también necesita estar declarada
void free_tree(ASTNode* root); 
ASTNode* create_constant_node(int value);
ASTNode* create_identifier_node(char* identifier);
ASTNode* create_binary_op_node(char* op, ASTNode* left, ASTNode* right);
ASTNode* create_unary_op_node(char* op, ASTNode* operand);
ASTNode* create_program_node(ASTNode* left, ASTNode* right);
ASTNode* create_assignment_node(char* identifier, ASTNode* expression);
ASTNode* get_ast_root();
void set_ast_root(ASTNode* new_root);

#endif // NODE_H
