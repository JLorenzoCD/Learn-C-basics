# include <stdio.h>

# include "mis_estructuras.h"

void cabecera_prueba_estructura_datos(char nombre_estructura[]);

void prueba_cola(void);
void prueba_lista_enlazada(void);

int main(void) {
    prueba_cola();
    puts("\n");
    prueba_lista_enlazada();

    return 0;
}

void cabecera_prueba_estructura_datos(char nombre_estructura[]) {
    puts("#####################################################");
    printf("Prueba de la estructura de datos: %s.\n", nombre_estructura);
    puts("#####################################################\n");
}

void prueba_cola(void) {
    cabecera_prueba_estructura_datos("Cola");

    Cola cola_libros = cola_crear();

    char libro_uno[] = "1° Libro apilado";
    char libro_dos[] = "2° Libro apilado";
    char libro_tres[] = "3° Libro apilado";

    cola_agregar(&cola_libros, libro_uno);
    cola_agregar(&cola_libros, libro_dos);
    cola_agregar(&cola_libros, libro_tres);

    char *dato_cola = (char*)cola_quitar(&cola_libros);
    while (dato_cola != NULL) {
        printf("%s\n", dato_cola);
        dato_cola = (char*)cola_quitar(&cola_libros);
    }
}

void prueba_lista_enlazada(void) {
    cabecera_prueba_estructura_datos("Lista enlazada");

    ListaEnlazada lista_prueba = lista_enlazada_crear();

    char elemento_uno[] = "1° Elemnto de la lista";
    char elemento_dos[] = "2° Elemnto de la lista";
    char elemento_tres[] = "3° Elemnto de la lista";

    lista_enlazada_agregar(&lista_prueba, elemento_uno);
    lista_enlazada_agregar(&lista_prueba, elemento_dos);
    lista_enlazada_agregar(&lista_prueba, elemento_tres);

    PNodo i = lista_prueba.primero;
    while (i != NULL) {
        printf("%s\n", (char*)i->dato);
        i = i->siguiente;
    }

    puts("\nSegunda vuelta");
    i = lista_prueba.primero;
    while (i != NULL) {
        printf("%s\n", (char*)i->dato);
        i = i->siguiente;
    }
}