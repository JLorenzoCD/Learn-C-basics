# include <stdio.h>
# include <stdlib.h>

typedef struct Nodo {
    struct Nodo *siguiente;
    void *dato;
}Nodo;

typedef struct {
    Nodo *primero;
    Nodo *ultimo;
}ListaEnlazada;

void inicir_lista_enlazada(ListaEnlazada *lista);
void agregar(ListaEnlazada *lista, void *dato);

int main(void) {
    ListaEnlazada lista_prueba;
    inicir_lista_enlazada(&lista_prueba);

    char elemento_uno[] = "1° Elemnto de la lista";
    char elemento_dos[] = "2° Elemnto de la lista";
    char elemento_tres[] = "3° Elemnto de la lista";

    agregar(&lista_prueba, elemento_uno);
    agregar(&lista_prueba, elemento_dos);
    agregar(&lista_prueba, elemento_tres);

    Nodo *i = lista_prueba.primero;
    while (i != NULL) {
        printf("%s\n", (char*)i->dato);
        i = i->siguiente;
    }

    printf("\nSegunda vuelta\n");
    i = lista_prueba.primero;
    while (i != NULL) {
        printf("%s\n", (char*)i->dato);
        i = i->siguiente;
    }

    return 0;
}

void inicir_lista_enlazada(ListaEnlazada *lista) {
    lista->primero = lista->ultimo = NULL;
}

void agregar(ListaEnlazada *lista, void *dato) {
    Nodo *elem = (Nodo*)malloc(sizeof(Nodo));

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