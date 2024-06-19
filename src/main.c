#include "alfa.tab.h"  // Asegúrate de que este archivo incluya las definiciones necesarias de Bison y Flex

extern FILE *yyin;    // Asegura que yyin es reconocido como externo si no está en alfa.tab.h

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "No se pudo abrir el archivo: %s\n", argv[1]);
            return 1;
        }
        yyin = file;
    }

    yyparse();

    if (yyin != stdin) {
        fclose(yyin);
    }

    return 0;
}
