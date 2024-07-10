#include "inc/agenda_contacto.h"

#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

#include "inc/opciones_agenda.h"
#include "inc/lista_contacto.h"
#include "inc/terminal.h"

static ListaContacto LISTA_CONTACTO;

static void imprimir_contactos(ListaContacto lista_contacto) {
    uint len = lista_contacto_size(lista_contacto);

    for (uint i = 0; i < len; i++) {
        Contacto contacto_actual = lista_contacto_obtener_at(lista_contacto, i);

        printf("--------------- %u -------------------\n", (i + 1u));
        contacto_imprimir(contacto_actual);
        puts("-------------------------------------");
    }
}

static void buscar_contacto(ContactoPropiedad contacto_propidad) {
    printf("Ingrese el valor de '%s' por el cual desea buscar: ", contacto_propiedad_a_str(contacto_propidad));
    char value[CONTACTO_MAX_SIZE_ATRIBUTO] = "";


    limpiar_stdin();
    obtener_str(value, CONTACTO_MAX_SIZE_ATRIBUTO, "");

    ListaContacto lc_f = lista_contacto_filtrar(LISTA_CONTACTO, contacto_propidad, value);

    if (lista_contacto_size(lc_f) != 0u) {
        puts("Se a encontrado los siguientes contactos: ");
        imprimir_contactos(lc_f);
    }
    else {
        puts("No se a encontrado ningún contacto.");
    }

    lista_contacto_destruir(&lc_f);
}

static void almacenar_contacto() {
    Contacto nuevo_contacto = contacto_craer_por_input(
        "Ingrese el nombre del nuevo contacto: ",
        "Ingrese el apellido del nuevo contacto: ",
        "Ingrese el teléfono del nuevo contacto: ",
        "Ingrese el email del nuevo contacto: "
    );

    if (lista_contacto_existe(LISTA_CONTACTO, nuevo_contacto)) {
        puts("El nombre del contacto ya se encuentra en la agenda, si desea modificar el contacto seleccione la opción 'Actualizar contacto', en caso contrario intente con otro nombre");
        return;
    }

    lista_contacto_add(&LISTA_CONTACTO, nuevo_contacto);
    puts("\n\nSe a creado y guardado con éxito el siguiente contacto:");
    contacto_imprimir(nuevo_contacto);

    assert(lista_contacto_existe(LISTA_CONTACTO, nuevo_contacto));
}

static void actualizar_contacto() {}

static void eliminar_contacto() {}

void agenda_contacto_iniciar() {
    puts("Se inicio con exito la agenda de contactos.");
    LISTA_CONTACTO = lista_contacto_from_file();
}

void agenda_contacto_realizar_accion(OpcionesAgenda op) {
    printf("\n\n");

    printf("Se esta realizando la siguiente accion: '%s'.\n", agenda_contacto_opcion_a_str(op));

    switch (op) {
    case MOSTRAR_TODOS_LOS_CONTACTOS:
        printf("Tus contactos guardados (%u):\n", lista_contacto_size(LISTA_CONTACTO));
        imprimir_contactos(LISTA_CONTACTO);
        break;

    case BUSCAR_UN_CONTACTO:
        puts("########### Búsqueda de contacto ###########");
        puts("Por cual de las siguientes propiedades deseas buscar a tu contacto?");
        ContactoPropiedad c_propiedad = contacto_propiedad_obtener_opcion();
        buscar_contacto(c_propiedad);
        break;

    case ALMACENAR_CONTACTO:
        puts("Rellene el siguiente formulario para crear un contacto.");
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
    puts("Se destruyo con éxito la agenda de contactos.");
    lista_contacto_destruir(&LISTA_CONTACTO);
}