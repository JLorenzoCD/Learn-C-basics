# include "../opciones_agenda.h"

enum OpcionBuscarContacto { IR_MENU, NOMBRE, APELLIDO, TELEFONO, EMAIL };
typedef enum OpcionBuscarContacto OpcionBuscarContacto;

void buscar_contacto(void) {
    int op = -1;

    do {
        puts("########### Busqueda de contacto ###########");
        puts("Por cual de las siguientes propiedades deseas buscar a tu contacto?");
        puts("1) Nombre.");
        puts("2) Apellido.");
        puts("3) Numero de telefono.");
        puts("4) Email.");

        puts("0) Ir al menu.");

        printf("Opcion (0-4): "); scanf("%i", &op);

        if (!(IR_MENU <= op && op <= EMAIL)) {
            system("clear");
            puts("\nOpcion no valida!!\n");
        }

    } while (!(IR_MENU <= op && op <= EMAIL));

    system("clear");
    switch (op) {
    case NOMBRE:
        puts("BUSCAR POR NOMBRE");
        break;
    case APELLIDO:
        puts("BUSCAR POR APELLIDO");

        break;
    case TELEFONO:
        puts("BUSCAR POR TELEFONO");

        break;
    case EMAIL:
        puts("BUSCAR POR EMAIL");
        break;
    case IR_MENU:
        puts("YENDO AL MENU");
        return;
    }
}