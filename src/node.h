#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include <stdio.h>

typedef enum {
    NODE_CONSTANT, NODE_IDENTIFIER, NODE_BINARY_OP, NODE_UNARY_OP, NODE_ASSIGNMENT, NODE_FREE, NODE_ARRAY_ACCESS, NODE_ASSIGNMENT_AMPERSAND,
    NODE_PROGRAM, NODE_DECLARATION, NODE_IF, NODE_WHILE, NODE_FOR, NODE_POINTER, NODE_POINTER_ASSIGNMENT, NODE_ARRAY, NODE_DIMENSION_LIST,
    NODE_FUNCTION_CALL, NODE_PRINTF, NODE_FUNCTION_DEFINITION, NODE_PARAMETER, NODE_RETURN, NODE_ARGUMENT, NODE_SCANF
} NodeType;

typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_CHAR,
    TYPE_STRING,
    TYPE_BOOLEAN
} DataType;
                                 
typedef struct ASTNode {
    NodeType type;
    DataType data_type; 
    union {
        int ival;                  
        char* sval;                
        char* identifier;
        struct {
            char* type;
            int pointer_level;
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
            struct ASTNode* cond;
            struct ASTNode* body;
        } forLoop;
        struct {
            char* functionName;
            struct ASTNode* arguments;
            int argCount;
        } functionCall;
        struct {
            char* identifier;
            struct ASTNode* value;
        } assignment;
        struct {
            char* text; 
        } printfNode;
        struct {
            char* text; 
        } scanfNode;
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
        struct {                    
            char* type;             
            struct ASTNode* dimensions;  
            char* identifier;      
        } array;
        struct {                     
            struct ASTNode* first;   
            struct ASTNode* next;    
        } dimensions;
        struct {
            char* arrayName;
            struct ASTNode* index;
        } arrayAccess;  
        struct ASTNode* expression;
        int pointer_level;
        struct {
            char* identifier;
            struct ASTNode* expression;     
        } return_stmt;      
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
ASTNode* create_assignment_node_array(ASTNode* array_access_node, ASTNode* expression);
ASTNode* create_declaration_node(char* type, char* identifier, int pointer_level);
ASTNode* create_if_node(ASTNode* condition, ASTNode* trueBranch, ASTNode* falseBranch);
ASTNode* create_while_node(ASTNode* condition, ASTNode* body);
ASTNode* create_for_node(ASTNode* cond, ASTNode* body);
ASTNode* create_function_call_node(char* functionName, struct ASTNode* arguments);
ASTNode* create_printf_node(char* identifier);
ASTNode* combine_nodes(struct ASTNode* a, struct ASTNode* b);
ASTNode* create_function_node(char* type, char* identifier, ASTNode* parameters, ASTNode* body);
ASTNode* create_parameter_node(char* type, char* identifier);
ASTNode* combine_parameter_nodes(ASTNode* a, ASTNode* b);
ASTNode* combine_argument_nodes(ASTNode* a, ASTNode* b);
ASTNode* create_return_node(char* identifier, ASTNode* expression);
ASTNode* create_argument_node(struct ASTNode* expr);
ASTNode* create_pointer_assignment_node(char* identifier, ASTNode* value);
ASTNode* create_free_node(char* identifier);
ASTNode* create_pointer_node(int level);
ASTNode* increase_pointer_level(struct ASTNode* node);
ASTNode* create_function_call_node(char* functionName, struct ASTNode* arguments);
ASTNode* create_array_node(char* type, struct ASTNode* dimensions, char* identifier);
ASTNode* create_dimension_list(struct ASTNode* first, struct ASTNode* next);
ASTNode* create_array_access_node(char* arrayName, struct ASTNode* index);
ASTNode* combine_expressions(struct ASTNode* left, struct ASTNode* right);
ASTNode* create_scanf_node(char* identifier);
ASTNode* create_scanf_node_array(struct ASTNode* array_access);
ASTNode* create_assignment_node_ampersand(char* identifier, char* target);
char* extract_identifier(struct ASTNode* node);
int new_label();
void free_tree(ASTNode* root);

#endif
