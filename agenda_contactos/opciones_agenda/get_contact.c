# include "../opciones_agenda.h"

enum OpcionBuscarContacto { IR_MENU, BUSCAR_NOMBRE, BUSCAR_APELLIDO, BUSCAR_TELEFONO, BUSCAR_EMAIL };
typedef enum OpcionBuscarContacto OpcionBuscarContacto;

void buscar_contacto(void) {
    int op;

    size_t len_contactos_filtrados;
    Contacto **contactos_filtrados = NULL;
    char *valor_buscar = NULL;

    do {
        len_contactos_filtrados = GLOBAL_LEN_CONTACTOS;

        op = -1;
        imprimir_cabecera_buscar_contacto();

        op = obtener_opcion_valida(IR_MENU, BUSCAR_EMAIL);

        switch (op) {
        case BUSCAR_NOMBRE:
            valor_buscar = obtener_texto("\nIngrese el nombre del contacto a buscar: ");

            contactos_filtrados = contacto_filtrar_por_propiedad(&len_contactos_filtrados, GLOBAL_CONTACTOS, CONTACTO_NOMBRE, valor_buscar);break;
        case BUSCAR_APELLIDO:
            valor_buscar = obtener_texto("\nIngrese el apellido del contacto a buscar: ");

            contactos_filtrados = contacto_filtrar_por_propiedad(&len_contactos_filtrados, GLOBAL_CONTACTOS, CONTACTO_APELLIDO, valor_buscar);break;
        case BUSCAR_TELEFONO:
            valor_buscar = obtener_texto("\nIngrese el telefono del contacto a buscar: ");

            contactos_filtrados = contacto_filtrar_por_propiedad(&len_contactos_filtrados, GLOBAL_CONTACTOS, CONTACTO_TELEFONO, valor_buscar);break;
        case BUSCAR_EMAIL:
            valor_buscar = obtener_texto("\nIngrese el email del contacto a buscar: ");

            contactos_filtrados = contacto_filtrar_por_propiedad(&len_contactos_filtrados, GLOBAL_CONTACTOS, CONTACTO_EMAIL, valor_buscar);break;
        }

        if (op != IR_MENU) {
            if (len_contactos_filtrados == 0) {
                puts("\n\nNo se ha encontrado nigun contacto con dicho valor.\n");
            }
            else {
                puts("\n\nSe a encontrado los siguientes contactos:");
                contacto_imprimir_array(len_contactos_filtrados, contactos_filtrados);
            }

            // Reset
            free(contactos_filtrados);
            contactos_filtrados = NULL;

            free(valor_buscar);
            valor_buscar = NULL;

            pausar_terminal();
        }

    } while (op != IR_MENU);
}