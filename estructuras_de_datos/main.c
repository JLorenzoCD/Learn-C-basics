# include <stdio.h>

# include "pila/pila.h"
# include "cola/cola.h"
# include "lista_enlazada/lista_enlazada.h"

void cabecera_prueba_estructura_datos(char nombre_estructura[]);

void prueba_cola(void);
void prueba_lista_enlazada(void);
void prueba_pila(void);

int main(void) {
    prueba_cola();
    puts("\n");
    prueba_lista_enlazada();
    puts("\n");
    prueba_pila();

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

    cola_destruir(&cola_libros);
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

    printf("Tamaño de la lista enlazada = %li\n", lista_prueba.tam);

    PNodo i = lista_prueba.primero;
    while (i != NULL) {
        printf("%s\n", (char*)i->dato);
        i = i->siguiente;
    }

    lista_enlazada_quitar_ultimo(&lista_prueba);
    puts("\nSegunda vuelta, luego de quitar el ultimo dato");
    i = lista_prueba.primero;
    while (i != NULL) {
        printf("%s\n", (char*)i->dato);
        i = i->siguiente;
    }

    lista_enlazada_destruir(&lista_prueba);
}

void prueba_pila(void) {
    cabecera_prueba_estructura_datos("Pila");

    Pila pila_libro = pila_crear();

    char libro_uno[] = "1° Libro apilado";
    char libro_dos[] = "2° Libro apilado";
    char libro_tres[] = "3° Libro apilado";

    pila_agregar(&pila_libro, libro_uno);
    pila_agregar(&pila_libro, libro_dos);
    pila_agregar(&pila_libro, libro_tres);

    char *dato_pila = (char*)pila_quitar(&pila_libro);
    while (dato_pila != NULL) {
        printf("%s\n", dato_pila);

        dato_pila = (char*)pila_quitar(&pila_libro);
    }

    pila_destruir(&pila_libro);
}