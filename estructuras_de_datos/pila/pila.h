# pragma once

# include "./../base_estructuras.h"

struct Pila {
    PNodo ultimo;
};

typedef struct Pila Pila;
typedef Pila *PPila;

Pila pila_crear(void);
void pila_agregar(PPila pila, T dato);
T pila_quitar(PPila pila);