# include "../opciones_agenda.h"

void mostrar_todos_contactos(void) {
    puts("########### Contactos ###########");
    puts("Estos son todos tus contactos:");

    unsigned int len_contactos = 4;
    Contacto **contactos = contacto_prueba_array(len_contactos);

    contacto_imprimir_array(len_contactos, contactos);

    contacto_destruir_array(len_contactos, contactos);
}
