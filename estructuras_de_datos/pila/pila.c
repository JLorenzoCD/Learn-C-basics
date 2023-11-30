# include "pila.h"

// Prototipos de funciones privadas
void pila_iniciar(PPila pila);

// Funciones privadas
void pila_iniciar(PPila pila) {
    pila->ultimo = NULL;
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
}

T pila_quitar(PPila pila) {
    if (pila->ultimo == NULL) return NULL;

    PNodo temp = pila->ultimo;

    T dato = temp->dato;
    pila->ultimo = temp->siguiente;

    free(temp);

    return dato;
}