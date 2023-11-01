# include "../opciones_agenda.h"

enum OpcionBuscarContacto { IR_MENU, BUSCAR_NOMBRE, BUSCAR_APELLIDO, BUSCAR_TELEFONO, BUSCAR_EMAIL };
typedef enum OpcionBuscarContacto OpcionBuscarContacto;

void buscar_contacto(void) {
    int op;

    unsigned int len_contactos_filtrados = 0;
    Contacto **contactos_filtrados = NULL;

    do {
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

        char *valor_buscar;
        system("clear");

        switch (op) {
        case BUSCAR_NOMBRE:
            puts("BUSCAR POR NOMBRE");

            valor_buscar = obtener_texto("Ingrese el nombre del contacto a buscar: ");

            contactos_filtrados = contacto_filtrar_por_propiedad(GLOBAL_LEN_CONTACTOS, GLOBAL_CONTACTOS, CONTACTO_NOMBRE, valor_buscar);break;
        case BUSCAR_APELLIDO:
            puts("BUSCAR POR APELLIDO");

            valor_buscar = obtener_texto("Ingrese el apellido del contacto a buscar: ");

            contactos_filtrados = contacto_filtrar_por_propiedad(GLOBAL_LEN_CONTACTOS, GLOBAL_CONTACTOS, CONTACTO_APELLIDO, valor_buscar);break;
        case BUSCAR_TELEFONO:
            puts("BUSCAR POR TELEFONO");

            valor_buscar = obtener_texto("Ingrese el telefono del contacto a buscar: ");

            contactos_filtrados = contacto_filtrar_por_propiedad(GLOBAL_LEN_CONTACTOS, GLOBAL_CONTACTOS, CONTACTO_TELEFONO, valor_buscar);break;
        case BUSCAR_EMAIL:
            puts("BUSCAR POR EMAIL");

            valor_buscar = obtener_texto("Ingrese el email del contacto a buscar: ");

            contactos_filtrados = contacto_filtrar_por_propiedad(GLOBAL_LEN_CONTACTOS, GLOBAL_CONTACTOS, CONTACTO_EMAIL, valor_buscar);break;
        }

        if (op != IR_MENU) {
            len_contactos_filtrados = contacto_array_len(contactos_filtrados);
            contacto_imprimir_array(len_contactos_filtrados, contactos_filtrados);

            free(contactos_filtrados);
            contactos_filtrados = NULL;

            len_contactos_filtrados = 0;

            pausar_terminal();
        }

    } while (op != IR_MENU);
}