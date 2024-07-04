#ifndef _TERMINAL_H
#define _TERMINAL_H

#include <stdlib.h>

void limpiar_stdin();
void detener_terminal();
int obtener_entero(const char *mensaje_pedir_dato, const char *mensaje_error_dato);
void obtener_str(char str[], size_t MAX_SIZE, const char *mensaje_pedir_dato);

#endif
