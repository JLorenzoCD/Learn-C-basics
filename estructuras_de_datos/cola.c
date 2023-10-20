# include <stdio.h>
# include <stdlib.h>

typedef struct Nodo {
    struct Nodo *siguiente;
    void *dato;
}Nodo;

typedef struct {
    Nodo *primero;
    Nodo *ultimo;
}Cola;

void inicir_cola(Cola *cola);
void agregar(Cola *cola, void *dato);
void* quitar(Cola *cola);

int main(void) {
    Cola cola_libros;
    inicir_cola(&cola_libros);

    char libro_uno[] = "1° Libro apilado";
    char libro_dos[] = "2° Libro apilado";
    char libro_tres[] = "3° Libro apilado";

    agregar(&cola_libros, libro_uno);
    agregar(&cola_libros, libro_dos);
    agregar(&cola_libros, libro_tres);

    char *dato_cola = (char*)quitar(&cola_libros);
    while (dato_cola != NULL) {
        printf("%s\n", dato_cola);
        dato_cola = (char*)quitar(&cola_libros);
    }

    return 0;
}

void inicir_cola(Cola *cola) {
    cola->primero = cola->ultimo = NULL;
}

void agregar(Cola *cola, void *dato) {
    Nodo *elem = (Nodo*)malloc(sizeof(Nodo));

    if (elem == NULL) {
        printf("Error al asignar espacio en memoria");
        exit(1);
    }

    elem->dato = dato;
    elem->siguiente = NULL;

    if (cola->primero == NULL) {
        cola->primero = elem;
        cola->ultimo = elem;
    }
    else {
        cola->ultimo->siguiente = elem;
        cola->ultimo = elem;
    }
}

void* quitar(Cola *cola) {
    if (cola->primero == NULL) return NULL;

    Nodo *temp = cola->primero;
    void *dato = temp->dato;

    cola->primero = temp->siguiente;

    free(temp);

    return dato;
}