#include "inc/opciones_agenda.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "inc/terminal.h"


const uint PRIMERA_OPCION = OBTENER_TODOS_LOS_CONTACTOS;
const uint ULTIMA_OPCION = SALIR;



static bool es_opcion_valida(int opcion) {
    --opcion;

    return PRIMERA_OPCION <= (uint)opcion && (uint)opcion <= ULTIMA_OPCION;
}

static void imprimir_opciones() {
    printf(
        "Selecciona una de las siguientes opciones:\n"
        "1 ........Mostrar todos los contactos.\n"
        "2 ........Buscar un contacto.\n"
        "3 ........Almacenar contacto.\n"
        "4 ........Modificar contacto.\n"
        "5 ........Eliminar contacto.\n"
        "6 ........Salir.\n"
    );
}


OpcionesAgenda obtener_opcion() {
    int opcion;

    do {
        imprimir_opciones();
        opcion = obtener_entero("Escriba la opcion a seleccionar:\n", "\n**** Se espera un numero entero positivo.\n\n");

        if (!es_opcion_valida(opcion)) {
            printf("\n**** Opción invalida. Seleccione un numero dentro del rango [%u-%u].\n", PRIMERA_OPCION + 1u, ULTIMA_OPCION + 1u);
        }
        else {
            printf("La opcion seleccionada es '%i'\n", opcion);
        }

        detener_terminal();
    } while (!es_opcion_valida(opcion));

    return (OpcionesAgenda)opcion;
}
