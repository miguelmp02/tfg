#include "codegen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUADS 1000

Quadruple quads[MAX_QUADS];
int quad_index = 0;

void generate_quad(Operation op, char *arg1, char *arg2, char *result) {
    if (quad_index >= MAX_QUADS) {
        fprintf(stderr, "Error: Exceeded maximum number of quadruples\n");
        exit(1);
    }
    quads[quad_index].op = op;
    quads[quad_index].arg1 = strdup(arg1);
    quads[quad_index].arg2 = strdup(arg2);
    quads[quad_index].result = strdup(result);
    quad_index++;
}

void print_quads(FILE *objfilefile) {
    for (int i = 0; i < quad_index; i++) {
        fprintf(objfilefile, "(%d) %s, %s, %s, %s\n", i, 
            operation_to_string(quads[i].op), 
            quads[i].arg1, quads[i].arg2, quads[i].result);
    }
}

const char* operation_to_string(Operation op) {
    switch (op) {
        case OP_LABEL: return "OP_LABEL";
        case OP_ADD: return "ADD";
        case OP_SUB: return "SUB";
        case OP_MUL: return "MUL";
        case OP_DIV: return "DIV";
        case OP_ASSIGN: return "ASSIGN";
        case OP_JUMP: return "JUMP";
        case OP_JUMP_IF_FALSE: return "JUMP_IF_FALSE";
        case OP_LT: return "LT";
        case OP_LE: return "LE";
        case OP_GT: return "GT";
        case OP_GE: return "GE";
        case OP_EQ: return "EQ";
        case OP_NE: return "NE";
        case OP_AND: return "AND";
        case OP_OR: return "OR";
        case OP_NOT: return "NOT";
        default: return "UNKNOWN";
    }
}

void generate_object_code(FILE *objfile) {
    for (int i = 0; i < quad_index; i++) {
        Quadruple q = quads[i];
        switch (q.op) {
            case OP_ADD:
                fprintf(objfile, "ADD %s, %s, %s\n", q.arg1, q.arg2, q.result);
                break;
            case OP_SUB:
                fprintf(objfile, "SUB %s, %s, %s\n", q.arg1, q.arg2, q.result);
                break;
            case OP_MUL:
                fprintf(objfile, "MUL %s, %s, %s\n", q.arg1, q.arg2, q.result);
                break;
            case OP_DIV:
                fprintf(objfile, "DIV %s, %s, %s\n", q.arg1, q.arg2, q.result);
                break;
            case OP_ASSIGN:
                fprintf(objfile, "MOV %s, %s\n", q.arg1, q.result);
                break;
            case OP_JUMP:
                fprintf(objfile, "JMP %s\n", q.result);
                break;
            case OP_JUMP_IF_FALSE:
                fprintf(objfile, "JZ %s, %s\n", q.arg1, q.result);
                break;
            case OP_LABEL:
                fprintf(objfile, "%s:\n", q.arg1);
                break;
            case OP_LT:
                fprintf(objfile, "CMP_LT %s, %s, %s\n", q.arg1, q.arg2, q.result);
                break;
            case OP_LE:
                fprintf(objfile, "CMP_LE %s, %s, %s\n", q.arg1, q.arg2, q.result);
                break;
            case OP_GT:
                fprintf(objfile, "CMP_GT %s, %s, %s\n", q.arg1, q.arg2, q.result);
                break;
            case OP_GE:
                fprintf(objfile, "CMP_GE %s, %s, %s\n", q.arg1, q.arg2, q.result);
                break;
            case OP_EQ:
                fprintf(objfile, "CMP_EQ %s, %s, %s\n", q.arg1, q.arg2, q.result);
                break;
            case OP_NE:
                fprintf(objfile, "CMP_NE %s, %s, %s\n", q.arg1, q.arg2, q.result);
                break;
            case OP_AND:
                fprintf(objfile, "AND %s, %s, %s\n", q.arg1, q.arg2, q.result);
                break;
            case OP_OR:
                fprintf(objfile, "OR %s, %s, %s\n", q.arg1, q.arg2, q.result);
                break;
            default:
                fprintf(objfile, "UNKNOWN %s, %s, %s, %s\n", operation_to_string(q.op), q.arg1, q.arg2, q.result);
                break;
        }
    }
}