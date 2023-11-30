# include "lista_enlazada.h"

// Prototipos de funciones privadas
void lista_enlazada_iniciar(PListaEnlazada lista);

// Funciones privadas
void lista_enlazada_iniciar(PListaEnlazada lista) {
    lista->primero = lista->ultimo = NULL;
}

// Funciones publicas
ListaEnlazada lista_enlazada_crear(void) {
    ListaEnlazada lista;
    lista_enlazada_iniciar(&lista);

    return lista;
}

void lista_enlazada_agregar(PListaEnlazada lista, T dato) {
    PNodo elem = (PNodo)malloc(sizeof(Nodo));

    if (elem == NULL) {
        printf("Error al asignar espacio en memoria");
        exit(1);
    }

    elem->siguiente = NULL;
    elem->dato = dato;

    if (lista->primero == NULL) {
        lista->primero = elem;
        lista->ultimo = elem;
    }
    else {
        lista->ultimo->siguiente = elem;
        lista->ultimo = elem;
    }
}