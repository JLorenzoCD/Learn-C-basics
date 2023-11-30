# pragma once

# include "./../base_estructuras.h"

struct ListaEnlazada {
    PNodo primero;
    PNodo ultimo;
};

typedef struct ListaEnlazada ListaEnlazada;
typedef ListaEnlazada *PListaEnlazada;

ListaEnlazada lista_enlazada_crear(void);
void lista_enlazada_agregar(PListaEnlazada lista, T dato);