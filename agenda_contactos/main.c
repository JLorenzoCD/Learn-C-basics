// Modulos estandar
# include <stdio.h>

// Mis modulos
# include "opciones_agenda.h"

int main(void) {
    int op = -1;

    do {
        // system("clear");
        puts("        AGENDA DE CONTACTO");
        puts("Seleccione alguna de las siguientes opciones:");
        puts("1) Mostrar todos los contactos agendados.");
        puts("2) Buscar contacto.");
        puts("3) Agregar un nuevo contacto.");
        puts("4) Editar contacto.");
        puts("5) Eliminar contacto.");
        puts("0) Salir de la agenda.");

        printf("Opcion (0-5): "); scanf("%i", &op);

        if (!(CLOSE <= op && op <= DELETE)) {
            system("clear");
            puts("\nOpcion no valida!!\n");
        }

    } while (!(CLOSE <= op && op <= DELETE));

    system("clear");
    switch (op) {
    case GET_ALL:
        mostrar_todos_contactos();break;
    case GET:
        buscar_contacto();break;
    case STORE:
        puts("3) Agregar un nuevo contacto.");break;
    case UPDATE:
        puts("4) Editar contacto.");break;
    case DELETE:
        puts("5) Eliminar contacto.");break;
    case CLOSE:
        puts("0) Salir de la agenda.");
        exit(0);break;
    }

    return 0;
}