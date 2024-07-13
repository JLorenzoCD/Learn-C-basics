#include "inc/agenda_contacto.h"

#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "inc/opciones_agenda.h"
#include "inc/lista_contacto.h"
#include "inc/terminal.h"



// Variable global del archivo para manejar la lista de contactos
static ListaContacto LISTA_CONTACTO;


// Funciones aux
static void imprimir_contactos(ListaContacto lista_contacto) {
    uint len = lista_contacto_size(lista_contacto);

    for (uint i = 0; i < len; i++) {
        Contacto contacto_actual = lista_contacto_obtener_at(lista_contacto, i);

        printf("--------------- %u -------------------\n", (i + 1u));
        contacto_imprimir(contacto_actual);
        puts("-------------------------------------");
    }
}

static ListaContacto buscar_contacto_por_propiedad(ContactoPropiedad contacto_propidad) {
    printf("Ingrese el valor de '%s' por el cual desea buscar: ", contacto_propiedad_a_str(contacto_propidad));
    char value[CONTACTO_MAX_SIZE_ATRIBUTO] = "";


    limpiar_stdin();
    obtener_str(value, CONTACTO_MAX_SIZE_ATRIBUTO, "");

    ListaContacto lc_f = lista_contacto_filtrar(LISTA_CONTACTO, contacto_propidad, value);

    return lc_f;
}



// Funciones que manejan las acciones de la agenda de contactos
static void accion_imprimir_contactos(void) {
    printf("Tus contactos guardados (%u):\n", lista_contacto_size(LISTA_CONTACTO));
    imprimir_contactos(LISTA_CONTACTO);
}

static void accion_buscar_contacto(void) {
    puts("########### Búsqueda de contacto ###########");
    puts("Por cual de las siguientes propiedades deseas buscar a tu contacto?");
    ContactoPropiedad c_propiedad = contacto_propiedad_obtener_opcion();

    ListaContacto lc_f = buscar_contacto_por_propiedad(c_propiedad);

    if (lista_contacto_size(lc_f) != 0u) {
        puts("Se a encontrado los siguientes contactos: ");
        imprimir_contactos(lc_f);
    }
    else {
        puts("No se a encontrado ningún contacto.");
    }

    lista_contacto_destruir(&lc_f);
}

static void accion_almacenar_contacto(void) {
    puts("Rellene el siguiente formulario para crear un contacto.");

    Contacto nuevo_contacto = contacto_craer_por_input(
        "Ingrese el nombre del nuevo contacto: ",
        "Ingrese el apellido del nuevo contacto: ",
        "Ingrese el teléfono del nuevo contacto: ",
        "Ingrese el email del nuevo contacto: "
    );

    if (lista_contacto_existe_nombre_contacto(LISTA_CONTACTO, nuevo_contacto)) {
        puts("El nombre del contacto ya se encuentra en la agenda, si desea modificar el contacto seleccione la opción 'Actualizar contacto', en caso contrario intente con otro nombre.");
        return;
    }

    lista_contacto_add(&LISTA_CONTACTO, nuevo_contacto);
    puts("\n\nSe a creado y guardado con éxito el siguiente contacto:");
    contacto_imprimir(nuevo_contacto);

    assert(lista_contacto_existe_nombre_contacto(LISTA_CONTACTO, nuevo_contacto));
}

static void accion_actualizar_contacto(void) {
    puts("########### Actualización de un contacto ###########");
    puts("Por cual de las siguientes propiedades deseas buscar a el contacto que actualizaras?");
    ContactoPropiedad c_propiedad = contacto_propiedad_obtener_opcion();

    ListaContacto lc_f = buscar_contacto_por_propiedad(c_propiedad);

    if (lista_contacto_size(lc_f) != 0u) {
        puts("Se a encontrado los siguientes contactos: ");
        imprimir_contactos(lc_f);

        uint indice = (uint)obtener_entero_entre(
            "Escriba indice del contacto a modificar:\n",
            "\n**** Se espera un numero entero positivo, entre el rango dado.\n\n",
            1,
            lista_contacto_size(lc_f)
        );

        Contacto contacto = lista_contacto_obtener_at(lc_f, indice - 1);
        contacto = lista_contacto_obtener_contacto_por_id(LISTA_CONTACTO, contacto_obtener_id(contacto));
        assert(contacto != NULL); // Nunca debería suceder ya que se obtuvo según el indice

        puts("El contacto a modificar es el siguiente:");
        contacto_imprimir(contacto);

        printf(
            "\n\nRellene el siguiente formulario para modificar el contacto:\n"
            "(en caso de no querer modificar alguna propiedad, entonces PRESIONE 'ENTER')\n"
        );

        Contacto nuevo_contacto = contacto_craer_por_input(
            "Ingrese el nuevo nombre del contacto: ",
            "Ingrese el nuevo apellido del contacto: ",
            "Ingrese el nuevo teléfono del contacto: ",
            "Ingrese el nuevo email del contacto: "
        );

        if (strlen(contacto_obtener_nombre(nuevo_contacto)) == 0u) {
            contacto_modificar(nuevo_contacto, NOMBRE, contacto_obtener_nombre(contacto));
        }

        if (strlen(contacto_obtener_apellido(nuevo_contacto)) == 0u) {
            contacto_modificar(nuevo_contacto, APELLIDO, contacto_obtener_apellido(contacto));
        }

        if (strlen(contacto_obtener_telefono(nuevo_contacto)) == 0u) {
            contacto_modificar(nuevo_contacto, TELEFONO, contacto_obtener_telefono(contacto));
        }

        if (strlen(contacto_obtener_email(nuevo_contacto)) == 0u) {
            contacto_modificar(nuevo_contacto, EMAIL, contacto_obtener_email(contacto));
        }

        puts("\n\nEl contacto modificado quedo de la siguiente forma:");
        contacto_imprimir(nuevo_contacto);

        puts("Deseas guardar los cambios? (s/S o n/N)");

        char ok = ' ';
        scanf("%c", &ok);

        if ((ok == 's' || ok == 'S')) {
            contacto_modificar(contacto, NOMBRE, contacto_obtener_nombre(nuevo_contacto));
            contacto_modificar(contacto, APELLIDO, contacto_obtener_apellido(nuevo_contacto));
            contacto_modificar(contacto, TELEFONO, contacto_obtener_telefono(nuevo_contacto));
            contacto_modificar(contacto, EMAIL, contacto_obtener_email(nuevo_contacto));

            puts("Se a modificado el contacto con éxito.");
        }

        contacto_destruir(&nuevo_contacto);
    }
    else {
        puts("No se a encontrado ningún contacto.");
    }

    lista_contacto_destruir(&lc_f);
}

static void accion_eliminar_contacto(void) {
    puts("########### Eliminación de un contacto ###########");
    puts("Por cual de las siguientes propiedades deseas buscar a el contacto que eliminaras?");
    ContactoPropiedad c_propiedad = contacto_propiedad_obtener_opcion();

    ListaContacto lc_f = buscar_contacto_por_propiedad(c_propiedad);

    if (lista_contacto_size(lc_f) != 0u) {
        puts("Se a encontrado los siguientes contactos: ");
        imprimir_contactos(lc_f);

        uint indice = (uint)obtener_entero_entre(
            "Escriba indice del contacto a eliminar:\n",
            "\n**** Se espera un numero entero positivo, entre el rango dado.\n\n",
            1,
            lista_contacto_size(lc_f)
        );

        Contacto contacto = lista_contacto_obtener_at(lc_f, indice - 1);
        lista_contacto_eliminar_contacto_por_id(LISTA_CONTACTO, contacto_obtener_id(contacto));
        puts("El contacto a sido eliminado con éxito.");
    }
    else {
        puts("No se a encontrado ningún contacto.");
    }

    lista_contacto_destruir(&lc_f);
}





void agenda_contacto_iniciar(void) {
    puts("Se inicio con éxito la agenda de contactos.");
    LISTA_CONTACTO = lista_contacto_from_file();
}

void agenda_contacto_realizar_accion(OpcionesAgenda op) {
    printf("\n\n");

    printf("Se esta realizando la siguiente acción: '%s'.\n", agenda_contacto_opcion_a_str(op));

    switch (op) {
    case MOSTRAR_TODOS_LOS_CONTACTOS:
        accion_imprimir_contactos();
        break;

    case BUSCAR_UN_CONTACTO:
        accion_buscar_contacto();
        break;

    case ALMACENAR_CONTACTO:
        accion_almacenar_contacto();
        break;

    case EDITAR_CONTACTO:
        accion_actualizar_contacto();
        break;

    case ELIMINAR_CONTACTO:
        accion_eliminar_contacto();
        break;

    case SALIR:
        // skip
        break;
    }
}

void agenda_contacto_destruir(void) {
    puts("Se destruyo con éxito la agenda de contactos.");
    lista_contacto_destruir(&LISTA_CONTACTO);
}