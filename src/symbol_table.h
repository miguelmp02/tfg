#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "node.h"

typedef struct Symbol {
    char *name;          
    DataType type;
    int value;    
    struct Symbol *next; 
    int num_parameters; 
} Symbol;

extern Symbol *symbolTable; 

void insert_symbol(char *name, DataType type, int num_parameters);
Symbol *find_symbol(char *name);
int print_symbol_table();
int count_parameters(ASTNode *parameter_list);
int count_arguments(ASTNode *argument_list);
DataType convert_data_type(char* type_str);

#endif 
