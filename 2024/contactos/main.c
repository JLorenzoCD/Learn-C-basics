#include <stdlib.h>

#include "inc/agenda_contacto.h"
#include "inc/opciones_agenda.h"
#include "inc/terminal.h"

int main(void) {
    agenda_contacto_iniciar();

    OpcionesAgenda opcion;
    do {
        opcion = obtener_opcion();

        agenda_contacto_realizar_accion(opcion);
        detener_terminal();
    } while (opcion != SALIR);

    agenda_contacto_destruir();

    return EXIT_SUCCESS;
}