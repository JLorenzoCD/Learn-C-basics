#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef unsigned int uint;

typedef enum {
    OBTENER_TODOS_LOS_CONTACTOS,
    OBTENER_UN_CONTACTO,
    ALMACENAR_CONTACTO,
    ACTUALIZAR_CONTACTO,
    ELIMINAR_CONTACTO,
    SALIR
} OpcionesAgenda;

const uint PRIMERA_OPCION = OBTENER_TODOS_LOS_CONTACTOS;
const uint ULTIMA_OPCION = SALIR;

static void limpiar_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

static void detener_terminal() {
    limpiar_stdin();

    printf(
        "\n\n"
        "Presiona Enter para continuar...\n"
    );
    while (getchar() != '\n');
}

static int obtener_entero(const char *mensaje_pedir_dato, const char *mensaje_error_dato) {
    int entero;
    int scf_res;

    do {
        printf("%s", mensaje_pedir_dato);
        scf_res = scanf("%i", &entero);

        if (scf_res != 1) {
            printf("%s", mensaje_error_dato);
            limpiar_stdin();
        }
    } while (scf_res != 1);

    return entero;
}

static bool opcion_agenda_entero_valido(int opcion) {
    --opcion;

    return PRIMERA_OPCION <= (uint)opcion && (uint)opcion <= ULTIMA_OPCION;
}

static OpcionesAgenda obtener_opcion() {
    int opcion;

    do {
        printf(
            "Selecciona una de las siguientes opciones:\n"
            "1 ........Mostrar todos los contactos.\n"
            "2 ........Buscar un contacto.\n"
            "3 ........Almacenar contacto.\n"
            "4 ........Modificar contacto.\n"
            "5 ........Eliminar contacto.\n"
            "6 ........Salir.\n"
        );
        opcion = (int)obtener_entero("Escriba la opcion a seleccionar:\n", "Se espera un numero entero positivo.\n\n");

        if (!opcion_agenda_entero_valido(opcion)) {
            printf("Opción invalida. Seleccione un numero dentro del rango [%u-%u].\n", PRIMERA_OPCION + 1u, ULTIMA_OPCION + 1u);
        }
        detener_terminal();
    } while (!opcion_agenda_entero_valido(opcion));

    return (OpcionesAgenda)opcion;
}

int main(void) {

    OpcionesAgenda opcion = obtener_opcion();

    printf("La opcion seleccionada es '%i'\n", (int)opcion);

    return EXIT_SUCCESS;
}