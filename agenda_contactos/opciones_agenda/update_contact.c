# include "../opciones_agenda.h"

enum OpcionEditarContacto { IR_MENU, BUSCAR_NOMBRE, BUSCAR_APELLIDO, BUSCAR_TELEFONO, BUSCAR_EMAIL };
typedef enum OpcionEditarContacto OpcionEditarContacto;

void modificar_contacto(void) {
    int op, index_contacto;

    size_t len_contactos_filtrados;
    ListaContactos contactos_filtrados = NULL;
    char *valor_buscar = NULL;

    char *nombre = NULL;
    char *apellido = NULL;
    char *telefono = NULL;
    char *email = NULL;

    do {
        len_contactos_filtrados = GLOBAL_LEN_CONTACTOS;

        op = -1;
        imprimir_cabecera_modificar_contacto();

        op = obtener_opcion_valida(IR_MENU, BUSCAR_EMAIL);

        switch (op) {
        case BUSCAR_NOMBRE:
            valor_buscar = obtener_texto("\nIngrese el nombre del contacto a modificar: ");

            contactos_filtrados = contacto_filtrar_por_propiedad(&len_contactos_filtrados, GLOBAL_CONTACTOS, CONTACTO_NOMBRE, valor_buscar);break;
        case BUSCAR_APELLIDO:
            valor_buscar = obtener_texto("\nIngrese el apellido del contacto a modificar: ");

            contactos_filtrados = contacto_filtrar_por_propiedad(&len_contactos_filtrados, GLOBAL_CONTACTOS, CONTACTO_APELLIDO, valor_buscar);break;
        case BUSCAR_TELEFONO:
            valor_buscar = obtener_texto("\nIngrese el telefono del contacto a modificar: ");

            contactos_filtrados = contacto_filtrar_por_propiedad(&len_contactos_filtrados, GLOBAL_CONTACTOS, CONTACTO_TELEFONO, valor_buscar);break;
        case BUSCAR_EMAIL:
            valor_buscar = obtener_texto("\nIngrese el email del contacto a modificar: ");

            contactos_filtrados = contacto_filtrar_por_propiedad(&len_contactos_filtrados, GLOBAL_CONTACTOS, CONTACTO_EMAIL, valor_buscar);break;
        }

        if (op != IR_MENU) {
            if (len_contactos_filtrados == 0) {
                puts("\n\nNo se ha encontrado nigun contacto con dicho valor.\n");
            }
            else {
                puts("\n\nSe a encontrado los siguientes contactos:");
                contacto_imprimir_array(len_contactos_filtrados, contactos_filtrados);

                printf("\nCual contacto deseas modificar? Contacto N°(%d-%lu)\n", 1, len_contactos_filtrados);
                index_contacto = obtener_opcion_valida(1, len_contactos_filtrados);
                index_contacto--;

                puts("\nEl contacto a modificar es el siguiente:");
                contacto_imprimir(contactos_filtrados[index_contacto]);

                puts("\n\nColoque los nuevos valores para el contacto:");
                nombre = obtener_texto("- Nuevo nombre: ");
                apellido = obtener_texto("- Nuevo apellido: ");
                telefono = obtener_texto("- Nuevo numero de telefono: ");
                email = obtener_texto("- Nuevo email: ");

                contacto_modificar_valores(contactos_filtrados[index_contacto], &nombre, &apellido, &telefono, &email);

                nombre = NULL;
                apellido = NULL;
                telefono = NULL;
                email = NULL;

                puts("\nEl contacto se modifico con exito!!");
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