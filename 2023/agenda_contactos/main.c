// Modulos estandar
# include <stdio.h>

// Mis modulos
# include "opciones_agenda.h"
# include "imprimir.h"

int main(void) {
    int op;

    if (GLOBAL_CONTACTOS == NULL) {
        GLOBAL_LEN_CONTACTOS = 4;
        GLOBAL_CONTACTOS = contacto_prueba_array(GLOBAL_LEN_CONTACTOS);
    }

    do {
        op = -1;
        imprimir_opciones_agenda();

        op = obtener_opcion_valida(CLOSE, DELETE);

        switch (op) {
        case GET_ALL:
            mostrar_todos_contactos();break;
        case GET:
            buscar_contacto();break;
        case STORE:
            nuevo_contacto();break;
        case UPDATE:
            modificar_contacto();break;
        case DELETE:
            eliminar_contacto();break;
        case CLOSE:
            imprimir_msg_salir_agenda();
        }

    } while (op != CLOSE);

    contacto_destruir_array(&GLOBAL_LEN_CONTACTOS, GLOBAL_CONTACTOS);

    return 0;
}