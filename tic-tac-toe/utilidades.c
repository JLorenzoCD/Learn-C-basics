# include "utilidades.h"

int numero_aleatorio(int hasta) {
    srand(time(0));
    int x = rand() % hasta;

    return x;
}