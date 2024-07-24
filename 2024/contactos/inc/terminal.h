#ifndef _TERMINAL_H
#define _TERMINAL_H

#include <stdlib.h>

// Función para limpiar el buffer de entrada estándar
void limpiar_stdin();

// Función para detener la terminal (espera que el usuario presione enter para continuar)
void detener_terminal();

// Función para obtener un entero del usuario, mostrando un mensaje para pedir el dato y otro en caso de error
int obtener_entero(const char *mensaje_pedir_dato, const char *mensaje_error_dato);

// Función para obtener un entero del usuario dentro de un rango específico, mostrando un mensaje para pedir el dato y otro en caso de error
int obtener_entero_entre(const char *mensaje_pedir_dato, const char *mensaje_error_dato, int num_min, int num_max);

// Función para obtener una cadena de caracteres del usuario, mostrando un mensaje para pedir el dato y asegurando que no exceda MAX_SIZE
void obtener_str(char str[], size_t MAX_SIZE, const char *mensaje_pedir_dato);

#endif
