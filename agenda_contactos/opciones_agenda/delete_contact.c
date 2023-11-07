# include "../opciones_agenda.h"

enum OpcionEliminarContacto { IR_MENU, POR_NOMBRE, POR_APELLIDO, POR_TELEFONO, POR_EMAIL };
typedef enum OpcionEliminarContacto OpcionEliminarContacto;

void eliminar_contacto(void) {
    int op;

    char *valor_eliminar = NULL;
    bool res;

    do {
        res = false;
        op = -1;

        imprimir_cabecera_eliminar_contacto();

        op = obtener_opcion_valida(IR_MENU, POR_EMAIL);

        switch (op) {
        case POR_NOMBRE:
            puts("\nELIMINAR POR NOMBRE");

            valor_eliminar = obtener_texto("Ingrese el nombre del contacto a eliminar: ");
            res = contacto_array_eliminar(&GLOBAL_LEN_CONTACTOS, &GLOBAL_CONTACTOS, CONTACTO_NOMBRE, valor_eliminar);break;

        case POR_APELLIDO:
            puts("\nELIMINAR POR APELLIDO");

            valor_eliminar = obtener_texto("Ingrese el nombre del contacto a eliminar: ");
            res = contacto_array_eliminar(&GLOBAL_LEN_CONTACTOS, &GLOBAL_CONTACTOS, CONTACTO_APELLIDO, valor_eliminar);break;

        case POR_TELEFONO:
            puts("\nELIMINAR POR TELEFONO");

            valor_eliminar = obtener_texto("Ingrese el nombre del contacto a eliminar: ");
            res = contacto_array_eliminar(&GLOBAL_LEN_CONTACTOS, &GLOBAL_CONTACTOS, CONTACTO_TELEFONO, valor_eliminar);break;

        case POR_EMAIL:
            puts("\nELIMINAR POR EMAIL");

            valor_eliminar = obtener_texto("Ingrese el nombre del contacto a eliminar: ");
            res = contacto_array_eliminar(&GLOBAL_LEN_CONTACTOS, &GLOBAL_CONTACTOS, CONTACTO_EMAIL, valor_eliminar);break;

        }

        if (op != IR_MENU) {
            if (res) {
                puts("\nSe elimino el contacto de forma exitosa");
            }
            else {
                puts("\nNo se encontro el contacto");
            }

            contacto_imprimir_array(GLOBAL_LEN_CONTACTOS, GLOBAL_CONTACTOS);

            // Reset
            free(valor_eliminar);
            valor_eliminar = NULL;

            pausar_terminal();
        }

    } while (op != IR_MENU);
}