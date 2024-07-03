#include "inc/opciones_agenda.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "inc/terminal.h"
#include "inc/imprimir.h"


const uint PRIMERA_OPCION = MOSTRAR_TODOS_LOS_CONTACTOS;
const uint ULTIMA_OPCION = SALIR;




static bool es_opcion_valida(int opcion) {
    --opcion;

    return PRIMERA_OPCION <= (uint)opcion && (uint)opcion <= ULTIMA_OPCION;
}

char *opcion_a_str(OpcionesAgenda opcion) {
    char *opcion_str = NULL;

    switch (opcion) {
    case MOSTRAR_TODOS_LOS_CONTACTOS:
        opcion_str = "mostrar todos los contactos";
        break;

    case BUSCAR_UN_CONTACTO:
        opcion_str = "buscar un contacto";
        break;

    case ALMACENAR_CONTACTO:
        opcion_str = "almacenar contacto";
        break;

    case EDITAR_CONTACTO:
        opcion_str = "editar contacto";
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
