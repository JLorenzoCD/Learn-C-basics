# include "pila.h"

// Prototipos de funciones privadas
void pila_iniciar(PPila pila);

// Funciones privadas
void pila_iniciar(PPila pila) {
    pila->ultimo = NULL;
    pila->tam = 0;
}

// Funciones publicas
Pila pila_crear(void) {
    Pila nueva_pila;

    pila_iniciar(&nueva_pila);

    return nueva_pila;
}

void pila_agregar(PPila pila, T dato) {
    PNodo elem = (PNodo)malloc(sizeof(Nodo));

    if (elem == NULL) {
        printf("Error al asignar espacio en memoria");
        exit(1);
    }

    elem->dato = dato;
    elem->siguiente = NULL;

    if (pila->ultimo == NULL) {
        pila->ultimo = elem;
    }
    else {
        elem->siguiente = pila->ultimo;
        pila->ultimo = elem;
    }

    pila->tam += 1;
}

T pila_quitar(PPila pila) {
    if (pila->ultimo == NULL) return NULL;

    PNodo temp = pila->ultimo;

    T dato = temp->dato;
    pila->ultimo = temp->siguiente;

    free(temp);

    pila->tam -= 1;

    return dato;
}

void pila_destruir(PPila pila) {
    T dato_pila = (T)pila_quitar(pila);
    while (dato_pila != NULL) {
        dato_pila = (T)pila_quitar(pila);
    }

    pila->ultimo = NULL;
}