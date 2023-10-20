# include <stdio.h>
# include <stdlib.h>

typedef struct Nodo {
    struct Nodo *siguiente;
    void *dato;
}Nodo;

typedef struct {
    Nodo *ultimo;
}Pila;

void inicir_pila(Pila *pila);
void agregar(Pila *pila, void *dato);
void* quitar(Pila *pila);

int main(void) {
    Pila pila_libro;
    inicir_pila(&pila_libro);

    char libro_uno[] = "1° Libro apilado";
    char libro_dos[] = "2° Libro apilado";
    char libro_tres[] = "3° Libro apilado";

    agregar(&pila_libro, libro_uno);
    agregar(&pila_libro, libro_dos);
    agregar(&pila_libro, libro_tres);

    char *dato_pila = (char*)quitar(&pila_libro);
    while (dato_pila != NULL) {
        printf("%s\n", dato_pila);

        dato_pila = (char*)quitar(&pila_libro);
    }

    return 0;
}

void inicir_pila(Pila *pila) {
    pila->ultimo = NULL;
}


void agregar(Pila *pila, void *dato) {
    Nodo *elem = (Nodo*)malloc(sizeof(Nodo));

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

void* quitar(Pila *pila) {
    if (pila->ultimo == NULL) return NULL;

    Nodo *temp = pila->ultimo;

    void *dato = temp->dato;
    pila->ultimo = temp->siguiente;

    free(temp);

    return dato;
}