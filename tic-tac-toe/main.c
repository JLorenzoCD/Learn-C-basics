#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char tablero[3][3];
const char JUGADOR = 'X';
const char COMPUTADORA = 'O';

void resetear_tablero(void);
void imprimir_tablero(void);
int revisando_si_hay_espacios_disponibles(void);
void movimiento_jugador(void);
void movimiento_computadora(void);
char revisar_ganadores(void);
void pintar_ganador(char ganador);
int numero_aleatorio(int hasta);

int main() {
    char ganador = ' ';
    char continuar_jugando = ' ';

    do {
        ganador = ' ';
        continuar_jugando = ' ';
        resetear_tablero();

        while (ganador == ' ' && revisando_si_hay_espacios_disponibles() != 0) {
            imprimir_tablero();

            movimiento_jugador();
            ganador = revisar_ganadores();

            if (ganador == ' ' && revisando_si_hay_espacios_disponibles() != 0) {
                movimiento_computadora();
                ganador = revisar_ganadores();
            }
        }

        imprimir_tablero();
        pintar_ganador(ganador);

        printf("\nTe gustaria jugar de nuevo? (Y/N): ");
        scanf(" %c", &continuar_jugando);
        continuar_jugando = toupper(continuar_jugando);
    } while (continuar_jugando == 'Y');

    printf("\nGracias por jugar!\n\n");

    return 0;
}

void resetear_tablero(void) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = ' ';
        }
    }
}

void imprimir_tablero(void) {
    system("clear");
    printf("-------- JUEGO DEL AHORCADO --------\n\n");

    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", tablero[i][0], tablero[i][1], tablero[i][2]);

        if (2 != i) {
            printf("---|---|--- \n");
        }
    }

    printf("\n");
}

int revisando_si_hay_espacios_disponibles(void) {
    int espacios_libres = 9;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i][j] != ' ') {
                espacios_libres--;
            }
        }
    }
    return espacios_libres;
}

void movimiento_jugador(void) {
    int x;
    int y;

    do {
        printf("Colocar la FILA #(1-3): "); scanf("%d", &x);
        printf("Colocar la COLUMNA #(1-3): "); scanf("%d", &y);

        x--;
        y--;

        if (tablero[x][y] != ' ') {
            printf("Movimiento invalido!\n");
        }
        else {
            tablero[x][y] = JUGADOR;
            break;
        }
    } while (tablero[x][y] != ' ');
}

void movimiento_computadora(void) {
    int x;
    int y;

    if (revisando_si_hay_espacios_disponibles() > 0) {
        do {
            x = numero_aleatorio(3);
            y = numero_aleatorio(3);
        } while (tablero[x][y] != ' ');

        tablero[x][y] = COMPUTADORA;
    }
    else {
        pintar_ganador(' ');
    }
}

char revisar_ganadores(void) {
    char ganador = ' ';

    for (int i = 0; i < 3 && ganador == ' '; i++) {
        // Revisando si se hizo tic-tac-toe en las filas
        if (tablero[i][0] == tablero[i][1] && tablero[i][0] == tablero[i][2]) {
            ganador = tablero[i][0];
        }

        // Revisando si se hizo tic-tac-toe en las columnas
        if (tablero[0][i] == tablero[1][i] && tablero[0][i] == tablero[2][i]) {
            ganador = tablero[0][i];
        }
    }

    // Revisando diagonales
    if (tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2]) {
        ganador = tablero[0][0];
    }
    if (tablero[0][2] == tablero[1][1] && tablero[0][2] == tablero[2][0]) {
        ganador = tablero[0][2];
    }

    return ganador;
}

void pintar_ganador(char ganador) {
    if (ganador == JUGADOR) {
        printf("FLICIDADES, GANASTE!");
    }
    else if (ganador == COMPUTADORA) {
        printf("PERDISTE!");
    }
    else {
        printf("HUBO UN EMPATE!");
    }
}

int numero_aleatorio(int hasta) {
    srand(time(0));
    int x = rand() % hasta;

    return x;
}

