#include <stdlib.h>
#include <stdio.h>

// #include "inc/agenda_contacto.h"
#include "inc/contacto.h"
// #include "inc/opciones_agenda.h"
// #include "inc/terminal.h"

int main(void) {
    // agenda_contacto_iniciar();

    // OpcionesAgenda op;
    // do {
    //     op = obtener_opcion();

    //     agenda_contacto_realizar_accion(op);
    //     detener_terminal();
    // } while (op != SALIR);

    // agenda_contacto_destruir();

    ListaContacto lc = lista_contacto_from_file();

    printf("Cantidad de contactos en la db: %u\n", lista_contacto_size(lc));
    if (lista_contacto_size(lc) > 1u) {
        Contacto yo = lista_contacto_obtener_at(lc, 0u);
        contacto_imprimir(yo);

        printf("\n");

        Contacto tete = lista_contacto_obtener_at(lc, 1u);
        contacto_imprimir(tete);
    }

    lista_contacto_destruir(&lc);

    return EXIT_SUCCESS;
}