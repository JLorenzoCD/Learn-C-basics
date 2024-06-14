# include <stdio.h>
# include <stdlib.h>

// MACROS para mascara de bits
# define ESTA_PRENDIDO_EL_BIT(bits, a_consultar) (bits & (a_consultar))
# define ENCENDER_BIT(bits, a_prender) (bits | (a_prender))
# define APAGAR_BIT(bits, a_apagar) (bits & (~(a_apagar)))
# define INTERCAMBIAR_BIT(bits, a_intercambiar) (bits ^ (a_intercambiar))

// MASCARA DE BITS para los colores
# define ROJO     1 << 7
# define VERDE    1 << 6
# define MARRON   1 << 5
# define AZUL     1 << 4
# define PURPURA  1 << 3
# define CYAN     1 << 2
# define GRIS     1 << 1
# define NEGRO    1 << 0

// Imprime un texto cambiando el color de cada caracter, segun los colores ingresados mediante la mascara de bits
void print_letras_en_colores(int tam, char palabra[], unsigned char color);

int main() {
    system("clear");

    // Probando colorar las palabras en terminal
    // printf("\033[1;31m");
    // printf("HOLA");
    // printf("\033[0m");

    // printf("\033[1;32m");
    // printf(" MuNDO\n");
    // printf("\033[0m");


    char texto[] = "HOLA MUNDO EN COLORES";

    print_letras_en_colores(sizeof(texto) / sizeof(texto[0]), texto, ROJO | VERDE | AZUL | PURPURA | CYAN);

    return 0;
}

void print_letras_en_colores(int tam, char palabra[], unsigned char color) {
    // Variable auxiliar que se utilizara para ir rotando por todos los colores y luego volver a comenzar
    unsigned char copia_aux = color;

    for (int i = 0; i < tam; i++) {

        // Si se quitaron todos los bits de colores ingresados, se buelven a asignar colores a copia_aux
        if (copia_aux == 0) {
            copia_aux = color;
        }

        // Se revisa si el color esta en la variable auxiliar
        if (ESTA_PRENDIDO_EL_BIT(copia_aux, ROJO)) {
            printf("\033[1;31m"); // Coloca el color a el siguiente caracter

            copia_aux = APAGAR_BIT(copia_aux, ROJO);  // Se elimina el color de la variable aux
        } // Se realiza lo mismo que en ROJO
        else if (ESTA_PRENDIDO_EL_BIT(copia_aux, VERDE)) {
            printf("\033[1;32m");
            copia_aux = APAGAR_BIT(copia_aux, VERDE);
        }
        else if (ESTA_PRENDIDO_EL_BIT(copia_aux, MARRON)) {
            printf("\033[1;33m");
            copia_aux = APAGAR_BIT(copia_aux, MARRON);
        }
        else if (ESTA_PRENDIDO_EL_BIT(copia_aux, AZUL)) {
            printf("\033[1;34m");
            copia_aux = APAGAR_BIT(copia_aux, AZUL);
        }
        else if (ESTA_PRENDIDO_EL_BIT(copia_aux, PURPURA)) {
            printf("\033[1;35m");
            copia_aux = APAGAR_BIT(copia_aux, PURPURA);
        }
        else if (ESTA_PRENDIDO_EL_BIT(copia_aux, CYAN)) {
            printf("\033[1;36m");
            copia_aux = APAGAR_BIT(copia_aux, CYAN);
        }
        else if (ESTA_PRENDIDO_EL_BIT(copia_aux, GRIS)) {
            printf("\033[1;37m");
            copia_aux = APAGAR_BIT(copia_aux, GRIS);
        }
        else if (ESTA_PRENDIDO_EL_BIT(copia_aux, NEGRO)) {
            printf("\033[0m");
            copia_aux = APAGAR_BIT(copia_aux, NEGRO);
        }

        printf("%c", palabra[i]); // Se imprime el caracter con un color seleccionado
    }
    printf("\033[0m"); // Se limpia los colores

    printf("\n");
}