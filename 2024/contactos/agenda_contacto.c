#include "inc/agenda_contacto.h"

#include <stdio.h>
#include "inc/opciones_agenda.h"

void agenda_contacto_iniciar() {
    printf("Se inicio con exito la agenda de contactos.\n");
}

void agenda_contacto_realizar_accion(OpcionesAgenda opcion) {

    printf("Se esta realizando la siguiente accion: '%s'.\n", opcion_a_str(opcion));

    switch (opcion) {
    case OBTENER_TODOS_LOS_CONTACTOS:
        // TODO
        break;

    case OBTENER_UN_CONTACTO:
        // TODO
        break;

    case ALMACENAR_CONTACTO:
        // TODO
        break;

    case ACTUALIZAR_CONTACTO:
        // TODO
        break;

    case ELIMINAR_CONTACTO:
        // TODO
        break;

    case SALIR:
        // TODO
        break;
    }
}

void agenda_contacto_destruir() {
    printf("Se destruyo con exito la agenda de contactos.\n");
}