// Mis modulos
# include "constantes.h"
# include "global.h"
# include "tablero.h"
# include "utilidades.h"
# include "imprimir.h"
# include "jugadores.h"

int main() {
    char ganador = ' ';
    char continuar_jugando = ' ';

    do {
        ganador = ' ';
        continuar_jugando = ' ';
        resetear_tablero();

        while (ganador == ' ' && revisando_si_hay_espacios_disponibles() != 0) {
            imprimir_tablero();

            movimiento_jugador();
            ganador = revisar_ganadores();

            if (ganador == ' ' && revisando_si_hay_espacios_disponibles() != 0) {
                movimiento_computadora();
                ganador = revisar_ganadores();
            }
        }

        imprimir_tablero();
        imprimir_ganador(ganador);

        imprimir_pregunta_continuar_jugando(&continuar_jugando);
    } while (continuar_jugando == 'Y');

    imprimir_msg_salida();

    return 0;
}