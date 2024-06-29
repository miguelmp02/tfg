// codegen.h
#ifndef CODEGEN_H
#define CODEGEN_H

typedef struct {
    char* operador;
    char* operando1;
    char* operando2;
    char* resultado;
} Cuadrupla;

void generate_code(const char* filename);
void agregar_cuadrupla(char* op, char* op1, char* op2, char* res);

#endif

