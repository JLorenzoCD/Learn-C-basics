#include "inc/terminal.h"

#include <stdio.h>

void limpiar_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void detener_terminal() {
    limpiar_stdin();

    printf(
        "\n\n"
        "Presiona Enter para continuar...\n"
    );
    while (getchar() != '\n');
}

int obtener_entero(const char *mensaje_pedir_dato, const char *mensaje_error_dato) {
    int entero;
    int scf_res;

    do {
        printf("%s", mensaje_pedir_dato);
        scf_res = scanf("%i", &entero);

        if (scf_res != 1) {
            printf("%s", mensaje_error_dato);
            limpiar_stdin();
        }
    } while (scf_res != 1);

    return entero;
}

void obtener_str(char str[], size_t MAX_SIZE, const char *mensaje_pedir_dato) {
    printf("%s", mensaje_pedir_dato);
    fgets(str, MAX_SIZE, stdin);

    for (size_t i = 0; i < MAX_SIZE; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
        }
    }
}
