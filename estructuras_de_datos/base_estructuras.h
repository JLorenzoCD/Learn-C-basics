# pragma once

# include <stdio.h>
# include <stdlib.h>

typedef void* T;

struct Nodo {
    struct Nodo *siguiente;
    T dato;
};

typedef struct Nodo Nodo;
typedef Nodo *PNodo;