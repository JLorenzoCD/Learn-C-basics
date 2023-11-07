# include "../opciones_agenda.h"

enum OpcionNuevoContacto { IR_MENU, ALMACENAR, REACER, ALMACENAR_Y_CREAR };
typedef enum OpcionNuevoContacto OpcionNuevoContacto;

void nuevo_contacto(void) {
    int op = -1;

    char *nombre = NULL;
    char *apellido = NULL;
    char *telefono = NULL;
    char *email = NULL;

    Contacto *contacto_nuevo = NULL;

    do {
        contacto_nuevo = NULL;
        imprimir_cabecera_alamcenar_contacto();

        nombre = obtener_texto("- Nombre: ");
        apellido = obtener_texto("- Apellido: ");
        telefono = obtener_texto("- Numero de telefono: ");
        email = obtener_texto("- Email: ");

        contacto_nuevo = contacto_crear(nombre, apellido, telefono, email);

        free(nombre);
        free(apellido);
        free(telefono);
        free(email);
        nombre = NULL;
        apellido = NULL;
        telefono = NULL;
        email = NULL;

        puts("-------------------------------------------------");
        puts("El nuvo contacto es: ");
        contacto_imprimir(contacto_nuevo);

        imprimir_opciones_alamcenar_contacto();

        op = obtener_opcion_valida(IR_MENU, ALMACENAR_Y_CREAR);

        switch (op) {
        case ALMACENAR:
            contacto_array_agregar(&GLOBAL_LEN_CONTACTOS, &GLOBAL_CONTACTOS, contacto_nuevo);
            puts("\nSE ALMACENO EL CONTACTO EN LA BASE DE DATOS");break;

        case REACER:
            contacto_destruir(contacto_nuevo);
            puts("\nREACIENDO EL CONTACTO");break;

        case ALMACENAR_Y_CREAR:
            contacto_array_agregar(&GLOBAL_LEN_CONTACTOS, &GLOBAL_CONTACTOS, contacto_nuevo);
            puts("\nSE ALMACENO Y SE SELECCIONO CREAR OTRO CONTACTO");break;
        }

        contacto_nuevo = NULL;

        if (op != IR_MENU) {
            pausar_terminal();
        }

    } while (op != IR_MENU && op != ALMACENAR);
}