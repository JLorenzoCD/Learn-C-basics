#include "inc/opciones_agenda.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "inc/contacto.h"
#include "inc/terminal.h"
#include "inc/imprimir.h"



static bool es_opcion_valida(int opcion) {
    --opcion;

    return PRIMERA_OPCION <= opcion && opcion <= ULTIMA_OPCION;
}

static int opcion_valida_segun_enum(void(imprimr_opcion)(void), uint primera_opcion, uint ultima_opcion, bool (opcion_validar)(int)) {
    int opcion;

    do {
        imprimr_opcion();
        opcion = obtener_entero("Escriba la opcion a seleccionar:\n", "\n**** Se espera un numero entero positivo.\n\n");

        if (!opcion_validar(opcion)) {
            printf("\n**** Opción invalida. Seleccione un numero dentro del rango [%u-%u].\n", primera_opcion + 1u, ultima_opcion + 1u);
        }

    } while (!opcion_validar(opcion));

    opcion--;
    return opcion;
}


char *agenda_contacto_opcion_a_str(OpcionesAgenda opcion) {
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

OpcionesAgenda agenda_contacto_obtener_opcion(void) {
    return (OpcionesAgenda)opcion_valida_segun_enum(
        &imprimir_opciones,
        PRIMERA_OPCION,
        ULTIMA_OPCION,
        &es_opcion_valida
    );
}

ContactoPropiedad contacto_propiedad_obtener_opcion(void) {
    return (ContactoPropiedad)opcion_valida_segun_enum(
        &imprimir_opciones_contacto_propiedad,
        CONTACTO_PROPIEDAD_PRIMERA,
        CONTACTO_PROPIEDAD_ULTIMA,
        &contacto_propiedad_es_valido
    );
}
