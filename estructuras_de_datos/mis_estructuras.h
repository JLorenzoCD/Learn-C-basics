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

struct ListaEnlazada {
    PNodo primero;
    PNodo ultimo;
};

typedef struct ListaEnlazada ListaEnlazada;
typedef ListaEnlazada *PListaEnlazada;

// Cola
Cola cola_crear(void);
void cola_agregar(PCola cola, T dato);
T cola_quitar(PCola cola);

// Lista enlazada
ListaEnlazada lista_enlazada_crear(void);
void lista_enlazada_agregar(PListaEnlazada lista, T dato);