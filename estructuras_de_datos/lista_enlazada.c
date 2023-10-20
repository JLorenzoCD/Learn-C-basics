# include <stdio.h>
# include <stdlib.h>

typedef struct nodo {
    struct nodo *siguiente;
    char *nombre;
}nodo;

nodo *primero = NULL;
nodo *ultimo = NULL;

void agregar(nodo *elem);

int main(void) {

    nodo *elemento_uno = (nodo*)malloc(sizeof(nodo));
    nodo *elemento_dos = (nodo*)malloc(sizeof(nodo));
    nodo *elemento_tres = (nodo*)malloc(sizeof(nodo));

    elemento_uno->nombre = "1° Elemnto de la lista";
    elemento_dos->nombre = "2° Elemnto de la lista";
    elemento_tres->nombre = "3° Elemnto de la lista";

    agregar(elemento_uno);
    agregar(elemento_dos);
    agregar(elemento_tres);

    nodo *i = primero;
    while (i != NULL) {
        printf("%s\n", i->nombre);
        i = i->siguiente;
    }

    printf("\nSegunda vuelta\n");
    i = primero;
    while (i != NULL) {
        printf("%s\n", i->nombre);
        i = i->siguiente;
    }

    return 0;
}

void agregar(nodo *elem) {
    elem->siguiente = NULL;

    if (primero == NULL) {
        primero = elem;
        ultimo = elem;
    }
    else {
        ultimo->siguiente = elem;
        ultimo = elem;
    }
}