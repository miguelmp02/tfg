#include <windows.h>
#include "generacion/y.tab.h"
#include <stdio.h>
#include "symbol_table.h" 

#define ID_FILE_OPEN 1
#define ID_FILE_PROCESS 2

extern int yylineno;
extern int yyparse();
extern int yylex();  
extern char* yytext; 
extern FILE* yyin;   

void yyerror(const char *s);

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
void openFileAndProcess(HWND);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
    AllocConsole();
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);
    WNDCLASSW wc = {0};

    wc.hbrBackground = (HBRUSH)COLOR_BACKGROUND;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpfnWndProc = WindowProcedure;
    wc.lpszClassName = L"CodeAnalyzer";

    if (!RegisterClassW(&wc))
        return -1;

    CreateWindowW(L"CodeAnalyzer", L"Code Analyzer", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  100, 100, 280, 200, NULL, NULL, NULL, NULL);

    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_COMMAND:
            switch(wp) {
                case ID_FILE_OPEN:
                    openFileAndProcess(hwnd);
                    break;
            }
            break;
        case WM_CREATE:
            CreateWindowW(L"Button", L"Open File", WS_VISIBLE | WS_CHILD, 10, 10, 120, 40,
                          hwnd, (HMENU)ID_FILE_OPEN, NULL, NULL);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProcW(hwnd, msg, wp, lp);
    }
    return 0;
}

void openFileAndProcess(HWND hwnd) {
    OPENFILENAME ofn;
    char file_name[100];
    BOOL lexError = FALSE; 
    BOOL symbolTableError = FALSE;
    BOOL parseError = FALSE; 

    ZeroMemory(&ofn, sizeof(OPENFILENAME));
    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner = hwnd;
    ofn.lpstrFile = file_name;
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = 100;
    ofn.lpstrFilter = "All files\0*.*\0Source files\0*.TXT\0";
    ofn.nFilterIndex = 1;

    if (GetOpenFileName(&ofn)) {
        yyin = fopen(ofn.lpstrFile, "r");
        if (yyin) {
            int result = yyparse();
            int token;
            while ((token = yylex()) != 0 && !lexError) {
                //printf("Token: %d (%s)\n", token, yytext);
                if (token == ERROR_TOKEN) {
                    lexError = TRUE;
                }
            }
            if (!lexError) { 
                if (result == 0) { 
                    printf("Analisis sintactico completado correctamente.\n");
                } else {
                    printf("Error en el analisis sintactico.\n");
                }
            }

            if (!print_symbol_table()) {
                symbolTableError = TRUE;
                //print_symbol_table();  
            }
            if (!lexError && !symbolTableError) {
                printf("Analisis lexico completado de forma correcta.\n");
                printf("Tabla de simbolos completada de forma correcta.\n");
            } else {
                if (lexError) {
                    printf("Error en el analisis lexico.\n");
                }
                if (symbolTableError) {
                    printf("Error en la tabla de simbolos.\n");
                }
            }
        } else {
            MessageBox(hwnd, "Failed to open the file.", "Error", MB_OK | MB_ICONERROR);
        }
        
    }
    fclose(yyin);
}
void yyerror(const char *s) {
    fprintf(stderr, "Error de análisis en la línea %d: %s\n", yylineno, s);
}   
