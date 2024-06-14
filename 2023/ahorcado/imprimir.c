# include "imprimir.h"

void imprimir_opciones_categorias(void) {
    system("clear");
    printf("\n\t\t\t\tJUEGO EL AHORCADO\n\n");
    printf(" CATEGORIAS\n\n");
    printf(" 1. Frutas\n");
    printf(" 2. Animales\n");
    printf(" 3. Paises\n");
    printf(" 4. Objetos\n\n");
}

void imprimir_ahorcado(void) {
    system("clear");

    // Cabecera del juego ahorcado, con los datos de la categoria, intentos y puntos.
    printf("\n\t\t\t\tJUEGO EL AHORCADO\n\n");
    printf(" CATEGORIA: %s\n\n", NOMBRE_CATEGORIA[DATOS_JUEGO.categoria]);
    printf(" Intentos Disponibles: %i\t\t\t\tPuntuacion: %i\n\n", 6 - DATOS_JUEGO.intentos, DATOS_JUEGO.puntos);

    // Dibujando el ahorcado
    int intentos = DATOS_JUEGO.intentos;
    printf("\n     _______\n");
    printf("    |       |\n");
    printf("    |       %c\n", 0 < intentos ? '0' : ' ');
    printf("    |      %c%c%c \n", 2 < intentos ? '/' : ' ', 1 < intentos ? '|' : ' ', 3 < intentos ? '\\' : ' ');
    printf("    |      %c %c \n", 4 < intentos ? '/' : ' ', 5 < intentos ? '\\' : ' ');
    printf("    |\n");
    printf("    |\n");
    printf(" ----------");

    // Imprime la palabra que se va completando
    printf("\n\n\n");
    for (int i = 0; i < DATOS_JUEGO.longitud; i++) {
        printf(" %c ", DATOS_JUEGO.frase[i]);
    }
}

void imprimir_msg_perdiste(void) {
    imprimir_ahorcado();
    printf("\n\n PERDISTE!!\n");
    printf(" LA SOLUCION ERA: %s\n\n", DATOS_JUEGO.palabra_a_adivinar);
}

void imprimir_msg_ganaste(void) {
    imprimir_ahorcado();
    printf("\n\n FELICIDADES.. GANASTE!!\n\n");
}

bool imprimir_pregunta_seguir_jugando(void) {
    char caracter;

    limpiar_buffer();

    printf("Desea para volver a jugar? (S/N): "); scanf(" %c", &caracter);

    return toupper(caracter) == 'S';
}

void imprimir_msg_fin(void) {
    printf("\n\n#############################################\n");
    printf("              Gracias por jugar!!");
    printf("\n#############################################\n\n");
}