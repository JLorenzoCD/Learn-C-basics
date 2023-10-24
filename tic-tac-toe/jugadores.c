# include "jugadores.h"

void movimiento_jugador(void) {
    int x;
    int y;

    do {
        printf("Colocar la FILA #(1-3): "); scanf("%d", &x);
        printf("Colocar la COLUMNA #(1-3): "); scanf("%d", &y);

        x--;
        y--;

        if (TABLERO[x][y] != ' ') {
            printf("Movimiento invalido!\n");
        }
        else {
            TABLERO[x][y] = JUGADOR;
            break;
        }
    } while (TABLERO[x][y] != ' ');
}

void movimiento_computadora(void) {
    int x;
    int y;

    if (revisando_si_hay_espacios_disponibles() > 0) {
        do {
            x = numero_aleatorio(3);
            y = numero_aleatorio(3);
        } while (TABLERO[x][y] != ' ');

        TABLERO[x][y] = COMPUTADORA;
    }
    else {
        imprimir_ganador(' ');
    }
}