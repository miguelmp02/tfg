#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_VARIABLES 100
#define MAX_LABELS 100
#define MAX_INSTRUCTIONS 1000
#define MAX_LINE_LENGTH 100

typedef struct {
    char name[20];
    int value;
} Variable;

typedef struct {
    char name[20];
    int address;
} Label;

Variable variables[MAX_VARIABLES];
Label labels[MAX_LABELS];
int num_variables = 0;
int num_labels = 0;
char instructions[MAX_INSTRUCTIONS][MAX_LINE_LENGTH];

int find_variable(char *name) {
    for (int i = 0; i < num_variables; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            return i;
        }
    }
    strncpy(variables[num_variables].name, name, sizeof(variables[num_variables].name) - 1);
    variables[num_variables].name[sizeof(variables[num_variables].name) - 1] = '\0';
    variables[num_variables].value = 0;
    return num_variables++;
}

int find_label(char *name) {
    for (int i = 0; i < num_labels; i++) {
        if (strcmp(labels[i].name, name) == 0) {
            return labels[i].address;
        }
    }
    return -1;
}

void set_label(char *name, int address) {
    strncpy(labels[num_labels].name, name, sizeof(labels[num_labels].name) - 1);
    labels[num_labels].name[sizeof(labels[num_labels].name) - 1] = '\0';
    labels[num_labels].address = address;
    num_labels++;
}

void execute_code(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int pc = 0;

    // Leer todas las instrucciones
    while (fgets(line, sizeof(line), file)) {
        if (line[0] != '(' && line[0] != '\n') {
            strncpy(instructions[pc], line, sizeof(instructions[pc]) - 1);
            instructions[pc][sizeof(instructions[pc]) - 1] = '\0';
            pc++;
        }
    }
    fclose(file);

    // Primera pasada: definir etiquetas
    for (int i = 0; i < pc; i++) {
        char *token = strtok(instructions[i], " \n");
        if (token[strlen(token) - 1] == ':') {
            token[strlen(token) - 1] = '\0';
            set_label(token, i);
        }
    }

    int pc_current = 0;
    while (pc_current < pc) {
        char *token = strtok(instructions[pc_current], " \n");

        if (strcmp(token, "ADD") == 0) {
            char *arg1 = strtok(NULL, ", ");
            char *arg2 = strtok(NULL, ", ");
            char *result = strtok(NULL, ", ");
            int idx1 = find_variable(arg1);
            int idx2 = find_variable(arg2);
            int idx3 = find_variable(result);
            variables[idx3].value = variables[idx1].value + variables[idx2].value;
        } else if (strcmp(token, "SUB") == 0) {
            char *arg1 = strtok(NULL, ", ");
            char *arg2 = strtok(NULL, ", ");
            char *result = strtok(NULL, ", ");
            int idx1 = find_variable(arg1);
            int idx2 = find_variable(arg2);
            int idx3 = find_variable(result);
            variables[idx3].value = variables[idx1].value - variables[idx2].value;
        } else if (strcmp(token, "MUL") == 0) {
            char *arg1 = strtok(NULL, ", ");
            char *arg2 = strtok(NULL, ", ");
            char *result = strtok(NULL, ", ");
            int idx1 = find_variable(arg1);
            int idx2 = find_variable(arg2);
            int idx3 = find_variable(result);
            variables[idx3].value = variables[idx1].value * variables[idx2].value;
        } else if (strcmp(token, "DIV") == 0) {
            char *arg1 = strtok(NULL, ", ");
            char *arg2 = strtok(NULL, ", ");
            char *result = strtok(NULL, ", ");
            int idx1 = find_variable(arg1);
            int idx2 = find_variable(arg2);
            int idx3 = find_variable(result);
            variables[idx3].value = variables[idx1].value / variables[idx2].value;
        } else if (strcmp(token, "MOV") == 0) {
            char *arg1 = strtok(NULL, ", ");
            char *result = strtok(NULL, ", ");
            int idx1 = find_variable(arg1);
            int idx2 = find_variable(result);
            variables[idx2].value = variables[idx1].value;
        } else if (strcmp(token, "JMP") == 0) {
            char *label = strtok(NULL, ", ");
            pc_current = find_label(label);
            continue;
        } else if (strcmp(token, "JZ") == 0) {
            char *arg1 = strtok(NULL, ", ");
            char *label = strtok(NULL, ", ");
            int idx1 = find_variable(arg1);
            if (variables[idx1].value == 0) {
                pc_current = find_label(label);
                continue;
            }
        } else if (token[strlen(token) - 1] == ':') {
            // Do nothing, it's a label
        } else {
            fprintf(stderr, "Unknown instruction: %s\n", token);
        }
        pc_current++;
    }

    for (int i = 0; i < num_variables; i++) {
        printf("%s = %d\n", variables[i].name, variables[i].value);
    }
}

int main() {
    execute_code("src/compilado/codigo_objeto.txt");
    return 0;
}
