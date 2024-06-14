# pragma once

// Modulos estandar
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int obtener_opcion_valida(int primera_opcion, int ultima_opcion);
char *obtener_texto(char descripcion[]);

void limpiar_buffer(void);
void pausar_terminal(void);
void limpiar_terminal(void);