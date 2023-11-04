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

        system("clear");

        op = -1;
        puts("########### Busqueda de contacto ###########");
        puts("Por cual de las siguientes propiedades deseas buscar a tu contacto?");
        puts("1) Nombre.");
        puts("2) Apellido.");
        puts("3) Numero de telefono.");
        puts("4) Email.");

        puts("0) Ir al menu.");

        op = obtener_opcion_valida(IR_MENU, BUSCAR_EMAIL);

        // system("clear");

        switch (op) {
        case BUSCAR_NOMBRE:
            puts("BUSCAR POR NOMBRE");

            valor_buscar = obtener_texto("Ingrese el nombre del contacto a buscar: ");

            contactos_filtrados = contacto_filtrar_por_propiedad(&len_contactos_filtrados, GLOBAL_CONTACTOS, CONTACTO_NOMBRE, valor_buscar);break;
        case BUSCAR_APELLIDO:
            puts("BUSCAR POR APELLIDO");

            valor_buscar = obtener_texto("Ingrese el apellido del contacto a buscar: ");

            contactos_filtrados = contacto_filtrar_por_propiedad(&len_contactos_filtrados, GLOBAL_CONTACTOS, CONTACTO_APELLIDO, valor_buscar);break;
        case BUSCAR_TELEFONO:
            puts("BUSCAR POR TELEFONO");

            valor_buscar = obtener_texto("Ingrese el telefono del contacto a buscar: ");

            contactos_filtrados = contacto_filtrar_por_propiedad(&len_contactos_filtrados, GLOBAL_CONTACTOS, CONTACTO_TELEFONO, valor_buscar);break;
        case BUSCAR_EMAIL:
            puts("BUSCAR POR EMAIL");

            valor_buscar = obtener_texto("Ingrese el email del contacto a buscar: ");

            contactos_filtrados = contacto_filtrar_por_propiedad(&len_contactos_filtrados, GLOBAL_CONTACTOS, CONTACTO_EMAIL, valor_buscar);break;
        }

        if (op != IR_MENU) {
            contacto_imprimir_array(len_contactos_filtrados, contactos_filtrados);

            // Reset
            free(contactos_filtrados);
            contactos_filtrados = NULL;

            free(valor_buscar);
            valor_buscar = NULL;

            pausar_terminal();
        }

    } while (op != IR_MENU);
}