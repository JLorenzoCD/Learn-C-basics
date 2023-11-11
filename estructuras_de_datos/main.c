# include <stdio.h>

# include "mis_estructuras.h"

void prueba_cola(void);

int main(void) {
    prueba_cola();
    return 0;
}

void prueba_cola(void) {
    Cola cola_libros = cola_crear();

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
}
