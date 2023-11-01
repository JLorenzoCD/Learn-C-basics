# include "../opciones_agenda.h"

void mostrar_todos_contactos(void) {
    system("clear");
    puts("########### Contactos ###########");
    puts("Estos son todos tus contactos:");

    contacto_imprimir_array(GLOBAL_LEN_CONTACTOS, GLOBAL_CONTACTOS);

    pausar_terminal();
}
