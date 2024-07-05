#include "inc/terminal.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include <fcntl.h>   // Para F_GETFL y F_SETFL
#include <unistd.h>  // Para STDIN_FILENO


static char *ltrim(char *s) {
    while (isspace(*s)) { s++; }

    return s;
}

static char *rtrim(char *s) {
    char* back;
    int len = strlen(s);

    if (len == 0) return s;

    back = s + len;
    while (isspace(*(--back)));

    *(back + 1) = '\0';

    return s;
}

static char *trim(char *s) {
    return rtrim(ltrim(s));
}

/* void limpiar_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
} */

void limpiar_stdin() {
    int old_flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    if (old_flags == -1) {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }

    // Establecer stdin en modo no bloqueante
    if (fcntl(STDIN_FILENO, F_SETFL, old_flags | O_NONBLOCK) == -1) {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Restaurar los flags originales de stdin
    if (fcntl(STDIN_FILENO, F_SETFL, old_flags) == -1) {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }
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

    str[MAX_SIZE - 1] = '\0';

    for (size_t i = 0; i < MAX_SIZE; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
        }
    }

    strcpy(str, trim(str));
}
