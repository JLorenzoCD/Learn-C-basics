# include "../opciones_agenda.h"

enum OpcionNuevoContacto { IR_MENU, ALMACENAR, REACER, ALMACENAR_Y_CREAR };
typedef enum OpcionNuevoContacto OpcionNuevoContacto;

void nuevo_contacto(void) {
    int op = -1;

    char *nombre;
    char *apellido;
    char *telefono;
    char *email;

    Contacto *contacto_nuevo;

    do {
        contacto_nuevo = NULL;
        system("clear");

        puts("########### Añadiendo nuevo contacto ###########");
        puts("Ingrese los datos del contacto: ");

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


        puts("\nDesea: ");
        puts("1) Almacenar.");
        puts("2) Reacer.");
        puts("3) Almacenar y crear nuevo contacto.");
        puts("0) Ir al menu.");

        op = obtener_opcion_valida(IR_MENU, ALMACENAR_Y_CREAR);

        switch (op) {
        case ALMACENAR:
            puts("SE ALMACENO EL CONTACTO EN LA BASE DE DATOS");break;
        case REACER:
            puts("REACIENDO EL CONTACTO");break;
        case ALMACENAR_Y_CREAR:
            puts("SE ALMACENO Y SE ESTA CREANDO NUEVO CONTACTO");break;
        }

        if (op != IR_MENU) {
            pausar_terminal();
        }

    } while (op != IR_MENU && op != ALMACENAR);
}