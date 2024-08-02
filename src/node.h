#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include <stdio.h>

typedef enum {
    NODE_CONSTANT, NODE_IDENTIFIER, NODE_BINARY_OP, NODE_UNARY_OP, NODE_ASSIGNMENT,
    NODE_PROGRAM, NODE_DECLARATION, NODE_IF, NODE_WHILE, NODE_FOR,
    NODE_FUNCTION_CALL, NODE_PRINTF,  NODE_FUNCTION_DEFINITION, NODE_PARAMETER, NODE_RETURN, NODE_ARGUMENT
} NodeType;

typedef struct ASTNode {
    NodeType type;
    union {
        int ival;                   // Para constantes
        char* sval;                 // Para identificadores
        char* identifier;
        struct {
            char* type;
            char* identifier;
        } declaration;
        struct {
            struct ASTNode* condition;
            struct ASTNode* trueBranch;
            struct ASTNode* falseBranch;
        } ifExpr;
        struct {
            struct ASTNode* condition;
            struct ASTNode* body;
        } whileExpr;
        struct {
            struct ASTNode* init;
            struct ASTNode* cond;
            struct ASTNode* iter;
            struct ASTNode* body;
        } forLoop;
        struct {
            char* functionName;
            struct ASTNode** arguments;
            int argCount;
        } functionCall;
        struct {
            char* identifier;
            struct ASTNode* value;
        } assignment;
        struct {
            char* text;   // Para nodos printf
        } printfNode;
         struct {
            struct ASTNode* left;
            struct ASTNode* right;
            char* op;
        } binary;
        struct {
            char* type;
            char* identifier;
            struct ASTNode* parameters;
            struct ASTNode* body;
        } function;
        struct ASTNode* expression;
    } data;   
    struct ASTNode* next;
} ASTNode;

// Prototipos de funciones
ASTNode* create_constant_node(int value);
ASTNode* create_identifier_node(char* identifier);
ASTNode* create_binary_op_node(char* op, struct ASTNode* left, struct ASTNode* right);
ASTNode* create_unary_op_node(char* op, ASTNode* operand);
ASTNode* create_program_node(ASTNode* left, ASTNode* right);
ASTNode* create_assignment_node(char* identifier, ASTNode* expression);
ASTNode* create_declaration_node(char* type, char* identifier);
ASTNode* create_if_node(ASTNode* condition, ASTNode* trueBranch, ASTNode* falseBranch);
ASTNode* create_while_node(ASTNode* condition, ASTNode* body);
ASTNode* create_for_node(ASTNode* init, ASTNode* cond, ASTNode* iter, ASTNode* body);
ASTNode* create_function_call_node(char* functionName, struct ASTNode* arguments);
ASTNode* create_printf_node(char* identifier);
ASTNode* combine_nodes(struct ASTNode* a, struct ASTNode* b);
ASTNode* create_function_node(char* type, char* identifier, ASTNode* parameters, ASTNode* body);
ASTNode* create_parameter_node(char* type, char* identifier);
ASTNode* combine_parameter_nodes(ASTNode* a, ASTNode* b);
ASTNode* combine_argument_nodes(ASTNode* a, ASTNode* b);
ASTNode* create_return_node(ASTNode* expression);
ASTNode* create_argument_node(struct ASTNode* expr);
void free_tree(ASTNode* root);

#endif // NODE_H
