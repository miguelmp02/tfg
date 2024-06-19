#include "symbol_table.h"

extern int yyparse(void);

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "No se pudo abrir el archivo: %s\n", argv[1]);
            return EXIT_FAILURE;
        }
        yyin = file;
    }

    if (yyparse() != 0) {
        fprintf(stderr, "Se encontraron errores en el compilado\n");
        return EXIT_FAILURE;
    }

    fclose(yyin);
    return EXIT_SUCCESS;
}
