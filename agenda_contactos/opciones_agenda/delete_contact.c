# include "../opciones_agenda.h"

enum OpcionEliminarContacto { IR_MENU, POR_NOMBRE, POR_APELLIDO, POR_TELEFONO, POR_EMAIL };
typedef enum OpcionEliminarContacto OpcionEliminarContacto;

void eliminar_contacto(void) {
    int op;

    char *valor_eliminar = NULL;
    bool res;

    do {
        res = false;

        system("clear");

        op = -1;
        puts("########### Eliminar contacto ###########");
        puts("Por cual de las siguientes propiedades deseas eliminar a tu contacto?");
        puts("1) Nombre.");
        puts("2) Apellido.");
        puts("3) Numero de telefono.");
        puts("4) Email.");

        puts("0) Ir al menu.");

        op = obtener_opcion_valida(IR_MENU, POR_EMAIL);

        switch (op) {
        case POR_NOMBRE:
            puts("ELIMINAR POR NOMBRE");

            valor_eliminar = obtener_texto("Ingrese el nombre del contacto a eliminar: ");
            res = contacto_array_eliminar(&GLOBAL_LEN_CONTACTOS, &GLOBAL_CONTACTOS, CONTACTO_NOMBRE, valor_eliminar);break;

        case POR_APELLIDO:
            puts("ELIMINAR POR APELLIDO");

            valor_eliminar = obtener_texto("Ingrese el nombre del contacto a eliminar: ");
            res = contacto_array_eliminar(&GLOBAL_LEN_CONTACTOS, &GLOBAL_CONTACTOS, CONTACTO_APELLIDO, valor_eliminar);break;

        case POR_TELEFONO:
            puts("ELIMINAR POR TELEFONO");

            valor_eliminar = obtener_texto("Ingrese el nombre del contacto a eliminar: ");
            res = contacto_array_eliminar(&GLOBAL_LEN_CONTACTOS, &GLOBAL_CONTACTOS, CONTACTO_TELEFONO, valor_eliminar);break;

        case POR_EMAIL:
            puts("ELIMINAR POR EMAIL");

            valor_eliminar = obtener_texto("Ingrese el nombre del contacto a eliminar: ");
            res = contacto_array_eliminar(&GLOBAL_LEN_CONTACTOS, &GLOBAL_CONTACTOS, CONTACTO_EMAIL, valor_eliminar);break;

        }

        if (op != IR_MENU) {
            if (res) {
                puts("Se elimino el contacto de forma exitosa");
            }
            else {
                puts("No se encontro el contacto");
            }

            contacto_imprimir_array(GLOBAL_LEN_CONTACTOS, GLOBAL_CONTACTOS);

            // Reset
            free(valor_eliminar);
            valor_eliminar = NULL;

            pausar_terminal();
        }

    } while (op != IR_MENU);
}