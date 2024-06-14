# include "imprimir.h"

void imprimir_opciones_agenda(void) {
    limpiar_terminal();

    puts("        AGENDA DE CONTACTO");
    puts("Seleccione alguna de las siguientes opciones:");
    puts("1) Mostrar todos los contactos agendados.");
    puts("2) Buscar contacto.");
    puts("3) Agregar un nuevo contacto.");
    puts("4) Editar contacto.");
    puts("5) Eliminar contacto.");

    puts("0) Salir de la agenda.");
}

void imprimir_msg_salir_agenda(void) {
    puts("\nCerrando la agenda de contactos.");
}

void imprimir_cabecera_mostrar_todos_contactos(void) {
    limpiar_terminal();

    puts("########### Contactos ###########");
    puts("Estos son todos tus contactos:");
}

void imprimir_cabecera_buscar_contacto(void) {
    limpiar_terminal();

    puts("########### Busqueda de contacto ###########");
    puts("Por cual de las siguientes propiedades deseas buscar a tu contacto?");
    puts("1) Nombre.");
    puts("2) Apellido.");
    puts("3) Numero de telefono.");
    puts("4) Email.");

    puts("0) Ir al menu.");
}

void imprimir_cabecera_alamcenar_contacto(void) {
    limpiar_terminal();

    puts("########### Añadiendo nuevo contacto ###########");
    puts("Ingrese los datos del contacto: ");
}

void imprimir_opciones_alamcenar_contacto(void) {
    puts("\nDesea: ");
    puts("1) Almacenar.");
    puts("2) Reacer.");
    puts("3) Almacenar y crear nuevo contacto.");

    puts("0) Descartar contacto e ir al menu.");
}

void imprimir_cabecera_modificar_contacto(void) {
    limpiar_terminal();

    puts("########### Edicion de contacto ###########");
    puts("Por cual de las siguientes propiedades deseas buscar al contacto a modificar?");
    puts("1) Nombre.");
    puts("2) Apellido.");
    puts("3) Numero de telefono.");
    puts("4) Email.");

    puts("0) Ir al menu.");
}

void imprimir_cabecera_eliminar_contacto(void) {
    limpiar_terminal();

    puts("########### Eliminar contacto ###########");
    puts("Por cual de las siguientes propiedades deseas eliminar a tu contacto?");
    puts("1) Nombre.");
    puts("2) Apellido.");
    puts("3) Numero de telefono.");
    puts("4) Email.");

    puts("0) Ir al menu.");
}