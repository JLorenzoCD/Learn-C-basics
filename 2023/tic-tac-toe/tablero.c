# include "tablero.h"

void resetear_tablero(void) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            TABLERO[i][j] = ' ';
        }
    }
}

int revisando_si_hay_espacios_disponibles(void) {
    int espacios_libres = 9;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (TABLERO[i][j] != ' ') {
                espacios_libres--;
            }
        }
    }
    return espacios_libres;
}

char revisar_ganadores(void) {
    char ganador = ' ';

    for (int i = 0; i < 3 && ganador == ' '; i++) {
        // Revisando si se hizo tic-tac-toe en las filas
        if (TABLERO[i][0] == TABLERO[i][1] && TABLERO[i][0] == TABLERO[i][2]) {
            ganador = TABLERO[i][0];
        }

        // Revisando si se hizo tic-tac-toe en las columnas
        if (TABLERO[0][i] == TABLERO[1][i] && TABLERO[0][i] == TABLERO[2][i]) {
            ganador = TABLERO[0][i];
        }
    }

    // Revisando diagonales
    if (TABLERO[0][0] == TABLERO[1][1] && TABLERO[0][0] == TABLERO[2][2]) {
        ganador = TABLERO[0][0];
    }
    if (TABLERO[0][2] == TABLERO[1][1] && TABLERO[0][2] == TABLERO[2][0]) {
        ganador = TABLERO[0][2];
    }

    return ganador;
}