#ifndef _TERMINAL_H
#define _TERMINAL_H

#include <stdlib.h>

void limpiar_stdin();
void detener_terminal();
int obtener_entero(const char *mensaje_pedir_dato, const char *mensaje_error_dato);
int obtener_entero_entre(const char *mensaje_pedir_dato, const char *mensaje_error_dato, int num_min, int num_max);
void obtener_str(char str[], size_t MAX_SIZE, const char *mensaje_pedir_dato);

#endif
