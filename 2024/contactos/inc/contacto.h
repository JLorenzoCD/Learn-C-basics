#ifndef _CONTACTO_H
#define _CONTACTO_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define CONTACTO_MAX_SIZE_ATRIBUTO 50u

typedef unsigned int uint;

typedef struct Contacto* Contacto;

typedef enum { NOMBRE, APELLIDO, TELEFONO, EMAIL } ContactoPropiedad;
#define CONTACTO_PROPIEDAD_PRIMERA NOMBRE
#define CONTACTO_PROPIEDAD_ULTIMA EMAIL



Contacto contacto_crear(const char *nombre, const char *apellido, const char *telefono, const char *email);
char* contacto_obtener_nombre(Contacto contacto);
char* contacto_obtener_apellido(Contacto contacto);
char* contacto_obtener_telefono(Contacto contacto);
char* contacto_obtener_email(Contacto contacto);
void contacto_imprimir(Contacto c);
Contacto contacto_clonar(Contacto contacto_a_clonar);
void contacto_destruir(Contacto *c);

Contacto contacto_craer_por_input(const char *mensaje_pedir_nombre, const char *mensaje_pedir_apellido, const char *mensaje_pedir_telefono, const char *mensaje_pedir_email);
Contacto contacto_from_file_line(FILE *file);

size_t contacto_size_t();
char *contacto_propiedad_a_str(ContactoPropiedad propiedad);
bool contacto_propiedad_es_valido(int opcion);

#endif
