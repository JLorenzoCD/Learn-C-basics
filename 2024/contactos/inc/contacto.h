#ifndef _CONTACTO_H
#define _CONTACTO_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define CONTACTO_MAX_SIZE_ATRIBUTO 50u

typedef unsigned int uint;

typedef struct Contacto* Contacto;

// Enumera las propiedades de un contacto
typedef enum { NOMBRE, APELLIDO, TELEFONO, EMAIL } ContactoPropiedad;
#define CONTACTO_PROPIEDAD_PRIMERA NOMBRE
#define CONTACTO_PROPIEDAD_ULTIMA EMAIL


// Función para generar un ID único para un contacto
uint contacto_generar_id();

// Función para crear un nuevo contacto
Contacto contacto_crear(uint id, const char *nombre, const char *apellido, const char *telefono, const char *email);

// Función para modificar una propiedad específica de un contacto
void contacto_modificar(Contacto contacto, ContactoPropiedad propiedad, const char* valor);

// Función para obtener el ID de un contacto
uint contacto_obtener_id(Contacto contacto);

// Función para obtener el nombre de un contacto
char* contacto_obtener_nombre(Contacto contacto);

// Función para obtener el apellido de un contacto
char* contacto_obtener_apellido(Contacto contacto);

// Función para obtener el teléfono de un contacto
char* contacto_obtener_telefono(Contacto contacto);

// Función para obtener el email de un contacto
char* contacto_obtener_email(Contacto contacto);

// Función para imprimir la información de un contacto
void contacto_imprimir(Contacto c);

// Función para clonar un contacto
Contacto contacto_clonar(Contacto contacto_a_clonar);




// Función para crear un contacto solicitando los datos al usuario
Contacto contacto_craer_por_input(const char *mensaje_pedir_nombre, const char *mensaje_pedir_apellido, const char *mensaje_pedir_telefono, const char *mensaje_pedir_email);

// Función para crear un contacto a partir de una línea de un archivo
Contacto contacto_from_file_line(FILE *file);

// Función para guardar un contacto en una línea de un archivo
void contacto_to_file_line(FILE *file, Contacto contacto);




// Función para obtener el tamaño de la estructura Contacto
size_t contacto_size_t();




// Función para convertir una propiedad del contacto a cadena de caracteres
char *contacto_propiedad_a_str(ContactoPropiedad propiedad);

// Función para verificar si una opción de propiedad de contacto es válida
bool contacto_propiedad_es_valido(int opcion);




// Función para destruir (liberar) un contacto
void contacto_destruir(Contacto *c);

#endif
