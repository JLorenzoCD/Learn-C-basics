# include "imprimir.h"

void imprimir_tablero(void) {
    system("clear");
    printf("-------- JUEGO DEL AHORCADO --------\n\n");

    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", TABLERO[i][0], TABLERO[i][1], TABLERO[i][2]);

        if (2 != i) {
            printf("---|---|--- \n");
        }
    }

    printf("\n");
}

void imprimir_ganador(char ganador) {
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

void imprimir_pregunta_continuar_jugando(char* continuar_jugando) {
    printf("\nTe gustaria jugar de nuevo? (Y/N): ");scanf(" %c", continuar_jugando);
    *continuar_jugando = toupper(*continuar_jugando);
}

void imprimir_msg_salida(void) {
    printf("\nGracias por jugar!\n\n");
}