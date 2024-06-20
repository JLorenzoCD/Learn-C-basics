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

char *opcion_a_str(OpcionesAgenda opcion) {
    char *opcion_str = NULL;

    switch (opcion) {
    case OBTENER_TODOS_LOS_CONTACTOS:
        opcion_str = "obtener todos los contactos";
        break;

    case OBTENER_UN_CONTACTO:
        opcion_str = "obtener un contacto";
        break;

    case ALMACENAR_CONTACTO:
        opcion_str = "almacenar contacto";
        break;

    case ACTUALIZAR_CONTACTO:
        opcion_str = "actualizar contacto";
        break;

    case ELIMINAR_CONTACTO:
        opcion_str = "eliminar contacto";
        break;

    case SALIR:
        opcion_str = "salir";
        break;

    default:
        opcion_str = "";
    }

    return opcion_str;
}

OpcionesAgenda obtener_opcion() {
    int opcion;

    do {
        imprimir_opciones();
        opcion = obtener_entero("Escriba la opcion a seleccionar:\n", "\n**** Se espera un numero entero positivo.\n\n");

        if (!es_opcion_valida(opcion)) {
            printf("\n**** Opción invalida. Seleccione un numero dentro del rango [%u-%u].\n", PRIMERA_OPCION + 1u, ULTIMA_OPCION + 1u);
        }

    } while (!es_opcion_valida(opcion));

    opcion--;
    return (OpcionesAgenda)opcion;
}
