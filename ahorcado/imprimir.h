#if !defined(_IMPRIMIR_H_)
#define _IMPRIMIR_H_

// Modulos estandar
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <ctype.h>

// Mis modulos
# include "global.h"
# include "constantes.h"
# include "utilidades.h"

void imprimir_opciones_categorias(void);
void imprimir_ahorcado(void);
void imprimir_msg_perdiste(void);
void imprimir_msg_ganaste(void);
bool imprimir_pregunta_seguir_jugando(void);
void imprimir_msg_fin(void);


#endif // _IMPRIMIR_H_
