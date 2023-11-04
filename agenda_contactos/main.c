// Modulos estandar
# include <stdio.h>
# include <stdbool.h>

// Mis modulos
# include "opciones_agenda.h"

int main(void) {
    int op;

    if (GLOBAL_CONTACTOS == NULL) {
        GLOBAL_LEN_CONTACTOS = 4;
        GLOBAL_CONTACTOS = contacto_prueba_array(GLOBAL_LEN_CONTACTOS);
    }

    do {
        op = -1;
        // system("clear");
        puts("        AGENDA DE CONTACTO");
        puts("Seleccione alguna de las siguientes opciones:");
        puts("1) Mostrar todos los contactos agendados.");
        puts("2) Buscar contacto.");
        puts("3) Agregar un nuevo contacto.");
        puts("4) Editar contacto.");
        puts("5) Eliminar contacto.");
        puts("0) Salir de la agenda.");

        op = obtener_opcion_valida(CLOSE, DELETE);

        switch (op) {
        case GET_ALL:
            mostrar_todos_contactos();break;
        case GET:
            buscar_contacto();break;
        case STORE:
            nuevo_contacto();break;
        case UPDATE:
            puts("4) Editar contacto.");break;
        case DELETE:
            eliminar_contacto();break;
        case CLOSE:
            puts("\nCerrando la agenda de contactos.");
        }

    } while (op != CLOSE);

    contacto_destruir_array(GLOBAL_LEN_CONTACTOS, GLOBAL_CONTACTOS);
    free(GLOBAL_CONTACTOS);
    GLOBAL_CONTACTOS = NULL;

    return 0;
}