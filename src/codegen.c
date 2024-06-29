#include "codegen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Cuadrupla cuadruplas[1000];
int numero_de_cuadruplas = 0;

void agregar_cuadrupla(char* op, char* op1, char* op2, char* res) {
    if (numero_de_cuadruplas < 1000) {
        Cuadrupla c = {op, op1, op2, res};
        cuadruplas[numero_de_cuadruplas++] = c;
        printf("Adding Cuadrupla: %s, %s, %s, %s\n", op, op1, op2, res);
    }
}

void generate_code(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char outputFilename[1024];
    sprintf(outputFilename, "%s.out", filename); // Crear un nombre de archivo de salida
    FILE *outputFile = fopen(outputFilename, "w"); // Abrir el archivo de salida para escribir
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(file);
        return;
    }
    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        char var[100], value[100];
        // Asumiendo un formato simple de 'var = value;'
        if (sscanf(line, "%s = %[^;];", var, value) == 2) {
            agregar_cuadrupla(":=", value, "", var);
        }
    }

    fclose(file);

    // Imprimir cuádruplas generadas
    for (int i = 0; i < numero_de_cuadruplas; i++) {
        printf("%s, %s, %s, %s\n",
            cuadruplas[i].operador,
            cuadruplas[i].operando1,
            cuadruplas[i].operando2,
            cuadruplas[i].resultado);
    }
    fclose(outputFile); // Cerrar el archivo de salida
    printf("Compilation complete. Output written to %s\n", outputFilename);
}


