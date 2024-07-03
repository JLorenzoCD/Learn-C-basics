#ifndef _CONTACTO_H
#define _CONTACTO_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Contacto* Contacto;

Contacto contacto_crear(const char *nombre, const char *apellido, const char *telefono, const char *email);
char* contacto_obtener_nombre(Contacto contacto);
char* contacto_obtener_apellido(Contacto contacto);
char* contacto_obtener_telefono(Contacto contacto);
char* contacto_obtener_email(Contacto contacto);
void contacto_imprimir(Contacto c);
Contacto contacto_clonar(Contacto contacto_a_clonar);
void contacto_destruir(Contacto *c);

Contacto contacto_from_file_line(FILE *file);

size_t contacto_size_t();

#endif
