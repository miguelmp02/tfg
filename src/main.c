#include <stdio.h>
#include <string.h>
#include "codegen.h"

int main(int argc, char **argv) {
    char filename[256];

    if (argc < 2) {
        printf("Enter the source file path: ");
        scanf("%s", filename);
    } else {
        strcpy(filename, argv[1]);
    }

    printf("Compiling %s\n", filename);
    generate_code();
    return 0;
}
