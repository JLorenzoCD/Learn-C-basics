# include <stdio.h>
# include <stdlib.h>

typedef struct elemento {
    struct elemento *siguiente;
    char *nombre;
}elemento;

elemento *ultimo = NULL;

void agregar(elemento *elem);
elemento* quitar(void);

int main(void) {

    elemento *uno = (elemento*)malloc(sizeof(elemento));
    elemento *dos = (elemento*)malloc(sizeof(elemento));
    elemento *tres = (elemento*)malloc(sizeof(elemento));

    uno->nombre = "1° Libro apilado";
    dos->nombre = "2° Libro apilado";
    tres->nombre = "3° Libro apilado";

    agregar(uno);
    agregar(dos);
    agregar(tres);

    elemento *i = quitar();
    while (i != NULL) {
        printf("%s\n", i->nombre);

        // Como hago un free(i), si me tira error aca?
        i = quitar();
    }


    return 0;
}

void agregar(elemento *elem) {
    elem->siguiente = NULL;

    if (ultimo == NULL) {
        ultimo = elem;
    }
    else {
        elem->siguiente = ultimo;
        ultimo = elem;
    }
}

elemento* quitar(void) {
    if (ultimo == NULL) return NULL;

    elemento *elem_quitado = ultimo;
    ultimo = elem_quitado->siguiente;

    return elem_quitado;
}