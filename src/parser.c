// parser.c
#include "node.h"  // Asume que node.h define ASTNode y sus funciones relacionadas // Asegúrate de que esto incluya los prototipos generados por Bison
#include "parser.h"
#include <stdio.h> 
 


extern FILE *yyin;
extern int yyparse();

ASTNode* parse(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Cannot open file: %s\n", filename);
        return NULL;
    }
    yyin = file;
    if (yyparse() == 0) {
        fclose(file);
        // Suponiendo que existe una función para obtener la raíz del AST
        return get_ast_root();
    } else {
        fclose(file);
        return NULL;
    }
}
