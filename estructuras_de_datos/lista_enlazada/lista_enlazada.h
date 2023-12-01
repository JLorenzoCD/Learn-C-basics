# pragma once

# include "./../base_estructuras.h"

struct ListaEnlazada {
    PNodo primero;
    PNodo ultimo;
    size_t tam;
};

typedef struct ListaEnlazada ListaEnlazada;
typedef ListaEnlazada *PListaEnlazada;

ListaEnlazada lista_enlazada_crear(void);
void lista_enlazada_agregar(PListaEnlazada lista, T dato);
T lista_enlazada_quitar_ultimo(PListaEnlazada lista);
T lista_enlazada_quitar_primero(PListaEnlazada lista);
void lista_enlazada_destruir(PListaEnlazada lista);