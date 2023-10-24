# pragma once

// Modulos estandar
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>

// Mis modulos
# include "constantes.h"
# include "global.h"

void imprimir_tablero(void);
void imprimir_ganador(char ganador);
void imprimir_pregunta_continuar_jugando(char* continuar_jugando);
void imprimir_msg_salida(void);