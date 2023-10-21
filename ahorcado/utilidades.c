# include "utilidades.h"

void limpiar_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int generar_entero_hasta(int n) {
    srand(time(NULL));

    if (n <= 0) {
        return rand() % 10;
    }

    return rand() % n;
}