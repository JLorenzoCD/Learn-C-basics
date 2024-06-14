# include <stdio.h>
# include <string.h>

# include "pila/pila.h"
# include "cola/cola.h"
# include "lista_enlazada/lista_enlazada.h"

void cabecera_prueba_estructura_datos(char nombre_estructura[]);

void prueba_cola(void);
void prueba_lista_enlazada(void);
void prueba_pila(void);

// Funcion de prueba para utilizarla como callback para buscar un elemnto en la lista enlazada
bool mismo_elemento_lista(T x, T y) {
    return ((char*)x)[0] == ((char*)y)[0];
}

void lista_enlazada_mostrar_texto(PListaEnlazada lista) {
    PNodo i = lista->primero;
    while (i != NULL) {
        printf("%s\n", (char*)i->dato);
        i = i->siguiente;
    }
}

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
    char elemento_cuatro[] = "4° Elemnto de la lista";

    lista_enlazada_agregar(&lista_prueba, elemento_uno);
    lista_enlazada_agregar(&lista_prueba, elemento_dos);
    lista_enlazada_agregar(&lista_prueba, elemento_tres);
    lista_enlazada_agregar(&lista_prueba, elemento_cuatro);

    printf("Tamaño de la lista enlazada = %li\n", lista_prueba.tam);

    lista_enlazada_mostrar_texto(&lista_prueba);

    size_t index = lista_enlazada_index_primera_concidencia(&lista_prueba, "3° Elemnto de la lista", &mismo_elemento_lista);
    if (index != NULL) {
        printf("\n\nindice encontrado = %li\n", index);

        lista_enlazada_quitar_segun_index(&lista_prueba, index);
        printf("Se elimino el elemento de la lista que se encontraba en el indice %li\n\n", index);
        lista_enlazada_mostrar_texto(&lista_prueba);
    }



    lista_enlazada_quitar_primero(&lista_prueba);
    lista_enlazada_quitar_ultimo(&lista_prueba);
    puts("\nQuitando el primer y ultimo elemnto");
    lista_enlazada_mostrar_texto(&lista_prueba);

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