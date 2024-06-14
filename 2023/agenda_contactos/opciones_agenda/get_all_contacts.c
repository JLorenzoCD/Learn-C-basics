# include "../opciones_agenda.h"

void mostrar_todos_contactos(void) {
    imprimir_cabecera_mostrar_todos_contactos();

    contacto_imprimir_array(GLOBAL_LEN_CONTACTOS, GLOBAL_CONTACTOS);

    pausar_terminal();
}
