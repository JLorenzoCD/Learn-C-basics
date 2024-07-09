#include "inc/imprimir.h"

#include <stdio.h>

void imprimir_opciones() {
    printf(
        "Selecciona una de las siguientes opciones:\n"
        "1) ........ Mostrar todos los contactos.\n"
        "2) ........ Buscar un contacto.\n"
        "3) ........ Almacenar contacto.\n"
        "4) ........ Modificar contacto.\n"
        "5) ........ Eliminar contacto.\n"
        "6) ........ Salir.\n"
    );
}

void imprimir_opciones_contacto_propiedad() {
    puts("1) Nombre.");
    puts("2) Apellido.");
    puts("3) Numero de teléfono.");
    puts("4) Email.");
}