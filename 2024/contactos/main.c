#include <stdlib.h>
#include <stdio.h>

#include "inc/agenda_contacto.h"
#include "inc/opciones_agenda.h"
#include "inc/terminal.h"

int main(void) {
    agenda_contacto_iniciar();

    OpcionesAgenda op;
    do {
        op = obtener_opcion();

        agenda_contacto_realizar_accion(op);

        if (op != SALIR) { detener_terminal(); }
    } while (op != SALIR);

    agenda_contacto_destruir();

    return EXIT_SUCCESS;
}