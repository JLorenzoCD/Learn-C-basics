#include "inc/agenda_contacto.h"

#include <stdio.h>

#include "inc/opciones_agenda.h"
#include "inc/lista_contacto.h"

static ListaContacto LISTA_CONTACTO;

static void imprimir_contactos() {
    uint len = lista_contacto_size(LISTA_CONTACTO);

    for (uint i = 0; i < len; i++) {
        Contacto contacto_actual = lista_contacto_obtener_at(LISTA_CONTACTO, i);

        printf("--------------- %u -------------------\n", (i + 1u));
        contacto_imprimir(contacto_actual);
        printf("-------------------------------------\n");
    }
}

void agenda_contacto_iniciar() {
    printf("Se inicio con exito la agenda de contactos.\n");
    LISTA_CONTACTO = lista_contacto_from_file();
}

void agenda_contacto_realizar_accion(OpcionesAgenda op) {

    printf("Se esta realizando la siguiente accion: '%s'.\n", opcion_a_str(op));

    switch (op) {
    case MOSTRAR_TODOS_LOS_CONTACTOS:
        printf("\nTus contactos guardados (%u):\n", lista_contacto_size(LISTA_CONTACTO));
        imprimir_contactos();
        break;

    case BUSCAR_UN_CONTACTO:
        // TODO
        buscar_contacto();
        break;

    case ALMACENAR_CONTACTO:
        // TODO
        almacenar_contacto();
        break;

    case EDITAR_CONTACTO:
        // TODO
        actualizar_contacto();
        break;

    case ELIMINAR_CONTACTO:
        // TODO
        eliminar_contacto();
        break;

    case SALIR:
        // skip
        break;
    }
}

void agenda_contacto_destruir() {
    printf("Se destruyo con exito la agenda de contactos.\n");
    lista_contacto_destruir(&LISTA_CONTACTO);
}