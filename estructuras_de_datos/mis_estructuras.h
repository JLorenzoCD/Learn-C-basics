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

struct Cola {
    PNodo primero;
    PNodo ultimo;
};

typedef struct Cola Cola;
typedef Cola *PCola;

// Cola
Cola cola_crear(void);
void agregar(PCola cola, T dato);
T quitar(PCola cola);