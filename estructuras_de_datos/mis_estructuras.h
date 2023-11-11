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

// Cola
struct Cola {
    PNodo primero;
    PNodo ultimo;
};

typedef struct Cola Cola;
typedef Cola *PCola;

Cola cola_crear(void);
void cola_agregar(PCola cola, T dato);
T cola_quitar(PCola cola);

// Lista enlazada
struct ListaEnlazada {
    PNodo primero;
    PNodo ultimo;
};

typedef struct ListaEnlazada ListaEnlazada;
typedef ListaEnlazada *PListaEnlazada;

ListaEnlazada lista_enlazada_crear(void);
void lista_enlazada_agregar(PListaEnlazada lista, T dato);

// Pila
struct Pila {
    PNodo ultimo;
};

typedef struct Pila Pila;
typedef Pila *PPila;

Pila pila_crear(void);
void pila_agregar(PPila pila, T dato);
T pila_quitar(PPila pila);
