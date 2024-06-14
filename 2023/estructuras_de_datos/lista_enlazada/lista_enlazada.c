# include "lista_enlazada.h"

// Prototipos de funciones privadas
void lista_enlazada_iniciar(PListaEnlazada lista);

// Funciones privadas
void lista_enlazada_iniciar(PListaEnlazada lista) {
    lista->primero = lista->ultimo = NULL;
    lista->tam = 0;
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

    lista->tam += 1;
}

T lista_enlazada_quitar_ultimo(PListaEnlazada lista) {
    if (0 == lista->tam) return NULL;

    T dato = lista->ultimo->dato;

    if (1 == lista->tam) {
        free(lista->ultimo);
        lista->primero = lista->ultimo = NULL;
        lista->tam = 0;
        return dato;
    }

    PNodo nuevo_ultimo = lista->primero;

    while (nuevo_ultimo->siguiente != lista->ultimo) {
        nuevo_ultimo = nuevo_ultimo->siguiente;
    }

    free(lista->ultimo);
    nuevo_ultimo->siguiente = NULL;

    lista->ultimo = nuevo_ultimo;
    lista->tam -= 1;

    return dato;
}

T lista_enlazada_quitar_primero(PListaEnlazada lista) {
    if (0 == lista->tam) return NULL;

    T dato = lista->primero->dato;

    if (1 == lista->tam) {
        free(lista->primero);
        lista->primero = lista->ultimo = NULL;
        lista->tam = 0;
        return dato;
    }

    PNodo segundo = lista->primero->siguiente;

    lista->primero->siguiente = NULL;
    free(lista->primero);

    lista->primero = segundo;
    lista->tam -= 1;

    return dato;
}

size_t lista_enlazada_index_primera_concidencia(PListaEnlazada lista, T a_comparar, bool (*callback)(T, T)) {
    if (lista->primero == NULL) {
        return NULL;
    }
    size_t primera_concidencia = 0;

    PNodo i = lista->primero;
    while (i != NULL) {

        if (callback(a_comparar, i->dato)) {
            return primera_concidencia;
        }

        i = i->siguiente;
        primera_concidencia += 1;
    }
}

T lista_enlazada_quitar_segun_index(PListaEnlazada lista, size_t indice_elemento_eliminar) {
    if (indice_elemento_eliminar == 0) {
        return lista_enlazada_quitar_primero(lista);
    }

    if (indice_elemento_eliminar == lista->tam - 1) {
        return lista_enlazada_quitar_ultimo(lista);
    }

    size_t indice_actual = 0;

    T dato = NULL;
    PNodo nuevo_siguiente = NULL;

    PNodo i = lista->primero;
    while (i != NULL) {
        if (indice_actual + 1 == indice_elemento_eliminar) {
            dato = i->siguiente->dato;
            nuevo_siguiente = i->siguiente->siguiente;

            free(i->siguiente);
            i->siguiente = nuevo_siguiente;

            lista->tam -= 1;

            return dato;
        }

        i = i->siguiente;
        indice_actual += 1;
    }

    return NULL;
}

void lista_enlazada_destruir(PListaEnlazada lista) {
    for (size_t i = lista->tam; 0 < i; i--) {
        lista_enlazada_quitar_primero(lista);
    }
}