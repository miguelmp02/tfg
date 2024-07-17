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
    NODE_PROGRAM,
    NODE_DECLARATION,
    NODE_IF,
    NODE_WHILE,
    NODE_FOR,
    NODE_FUNCTION_CALL,
    NODE_PRINTF
} NodeType;

typedef struct Declaration {
    char* type;
    char* identifier;
} Declaration;

typedef struct IfExpr {
    struct ASTNode* condition;
    struct ASTNode* trueBranch;
    struct ASTNode* falseBranch;
} IfExpr;

typedef struct WhileExpr {
    struct ASTNode* condition;
    struct ASTNode* body;
} WhileExpr;

typedef struct ForLoop {
    struct ASTNode* init;
    struct ASTNode* cond;
    struct ASTNode* iter;
    struct ASTNode* body;
} ForLoop;

typedef struct FunctionCall {
    char* functionName;          // Para almacenar el nombre de la función
    struct ASTNode* arguments;  // Si necesitas argumentos, esto podría ser una lista
} FunctionCall;

typedef struct Assignment {
    char* identifier;
    struct ASTNode* value;
} Assignment;

typedef struct ASTNode {
    NodeType type;
    union {
        int ival;     // Para constantes
        char* sval;   // Para identificadores
        char* identifier;
        Declaration declaration;
        IfExpr ifExpr;           // Para sentencias if
        WhileExpr whileExpr;
        ForLoop forLoop;  
        FunctionCall functionCall;
        Assignment assignment;
        struct {      // Para operaciones binarias y otros nodos compuestos
            struct ASTNode* left;
            struct ASTNode* right;
            struct ASTNode* condition;
            char* text;
        } printfnode;
    } data;
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
struct ASTNode* create_declaration_node(char* type, char* identifier);
struct ASTNode* create_if_node(struct ASTNode* condition, struct ASTNode* trueBranch, struct ASTNode* falseBranch);
struct ASTNode* create_while_node(struct ASTNode* condition, struct ASTNode* body);
struct ASTNode* create_for_node(struct ASTNode* init, struct ASTNode* cond, struct ASTNode* iter, struct ASTNode* body);
struct ASTNode* create_function_call_node(char* functionName);
struct ASTNode* create_printf_node(char* identifier);
void set_ast_root(ASTNode* new_root);


#endif // NODE_H
