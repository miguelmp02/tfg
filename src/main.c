#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include "generacion/y.tab.h"
#include "symbol_table.h"
#include "codegen.h"

typedef int BOOL;

int has_syntax_error = 0; 
int has_semantic_error = 0; 
extern int yylineno;
extern int yyparse();
extern int yylex();
extern char* yytext; 
extern FILE* yyin;

void open_file_dialog(GtkWidget *widget, gpointer window);
void process_file(const char *filename, GtkWidget *window);
void cleanup();

void yyerror(const char *s) {
    fprintf(stderr, "Error de analisis en la linea %d: %s\n", yylineno, s);
    has_syntax_error = 1; 
}

void yysemanticerror(const char *s) {
    fprintf(stderr, "Error semantico en la linea %d: %s\n", yylineno, s);
    has_semantic_error = 1;
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        // Modo de línea de comandos
        const char *filename = argv[1];
        process_file(filename, NULL);
        return 0;
    }

    // Modo gráfico
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *grid;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Code Analyzer");
    gtk_window_set_default_size(GTK_WINDOW(window), 280, 200);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    button = gtk_button_new_with_label("Open File");
    g_signal_connect(button, "clicked", G_CALLBACK(open_file_dialog), window);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 0, 1, 1);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}

void open_file_dialog(GtkWidget *widget, gpointer window) {
    GtkWidget *dialog;
    dialog = gtk_file_chooser_dialog_new("Open File", GTK_WINDOW(window),
        GTK_FILE_CHOOSER_ACTION_OPEN, 
        "_Cancel", GTK_RESPONSE_CANCEL, 
        "_Open", GTK_RESPONSE_ACCEPT, NULL);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
        char *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
        gtk_widget_destroy(dialog); // Cierra la ventana de diálogo inmediatamente
        process_file(filename, GTK_WIDGET(window));
        g_free(filename);
    } else {
        gtk_widget_destroy(dialog); // Cierra la ventana de diálogo si el usuario cancela
    }
}

void process_file(const char *filename, GtkWidget *window) {
    FILE *outfile = fopen("src/compilado/codigo_intermedio.txt", "w");
    if (outfile == NULL) {
        fprintf(stderr, "Failed to open the output file.\n");
        if (window) gtk_widget_destroy(window); // Cierra la ventana principal
        return;
    }

    FILE *objfile = fopen("src/compilado/codigo_objeto.txt", "w");
    if (objfile == NULL) {
        fclose(outfile);
        fprintf(stderr, "Failed to open the output file.\n");
        if (window) gtk_widget_destroy(window); // Cierra la ventana principal
        return;
    }

    yyin = fopen(filename, "r");
    if (yyin) {
        int result = yyparse();
        int token;
        BOOL lexError = FALSE; 
        BOOL symbolTableError = FALSE; 

        while ((token = yylex()) != 0 && !lexError) {
            if (token == ERROR_TOKEN) {
                lexError = TRUE;
            }
        }

        if (!print_symbol_table()) {
            symbolTableError = TRUE;
        }

        if (!lexError && !symbolTableError && !has_syntax_error && !has_semantic_error) {
            printf("Analisis lexico completado de forma correcta.\n");
            printf("Analisis sintactico completado de forma correcta.\n");
            printf("Tabla de simbolos completada de forma correcta.\n");
            printf("Analisis semantico completado de forma correcta.\n");
            printf("<---------- Analisis terminados de forma correcta ---------->\n");
            printf("Codigo Intermedio Generado de forma correcta\n");
            printf("Codigo Objeto Generado de forma correcta\n");
            printf("<---------- Generacion de codigo de forma correcta ---------->\n");
            print_quads(outfile); 
            generate_object_code(objfile);
            printf("\n-------------- FICHERO COMPILADO CORRECTAMENTE --------------\n");
        } else {
            if (lexError) {
                printf("Error en el analisis lexico.\n");
            }
            if (symbolTableError) {
                printf("Error en la tabla de simbolos.\n");
            }
            if (has_syntax_error) {
                printf("Error en el analisis sintactico.\n");
            }
            if (has_semantic_error) {
                printf("Error en el analisis semantico.\n");
            }
        }
    } else {
        fprintf(stderr, "Failed to open the input file.\n");
    }

    fclose(outfile);
    fclose(objfile);
    fclose(yyin);
    yyin = NULL;
    cleanup();

    if (window) gtk_widget_destroy(window); // Cierra la ventana principal después de procesar el archivo
}

void cleanup() {
    has_syntax_error = 0;
    has_semantic_error = 0;
    yylineno = 0;
}
