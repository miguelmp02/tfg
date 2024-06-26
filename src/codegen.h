#ifndef CODEGEN_H
#define CODEGEN_H

// Incluye dependencias necesarias para definiciones o estructuras utilizadas.
#include "symbol_table.h"

// Función para iniciar la generación de código
void init_code_generation();

// Función para finalizar la generación de código y realizar cualquier limpieza necesaria
void finalize_code_generation();

// Función para generar código para declaraciones de variables
void generate_variable_declaration(const Symbol *symbol);

// Función para generar código para una función
void generate_function_definition(const Symbol *symbol);

// Función general para generar todo el código basado en la tabla de símbolos
void generate_code();

#endif // CODEGEN_H
