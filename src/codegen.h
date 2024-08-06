#ifndef CODEGEN_H
#define CODEGEN_H

#include "node.h"

typedef enum {
    OP_ADD, OP_SUB, OP_MUL, OP_DIV,
    OP_ASSIGN, OP_JUMP, OP_JUMP_IF_FALSE,
    OP_LT, OP_LE, OP_GT, OP_GE, OP_EQ, OP_NE,
    OP_AND, OP_OR, OP_NOT, OP_LABEL
} Operation;

typedef struct {
    Operation op;
    char *arg1;
    char *arg2;
    char *result;
} Quadruple;

void generate_quad(Operation op, char *arg1, char *arg2, char *result);
void print_quads(FILE *outfile);
const char* operation_to_string(Operation op);
//codigo objeto
void generate_object_code(FILE *objfile);

#endif