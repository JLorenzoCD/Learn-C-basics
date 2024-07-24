#ifndef _LISTA_CONTACTO_H
#define _LISTA_CONTACTO_H

#include <stdbool.h>

#include "contacto.h"

typedef unsigned int uint;
typedef struct ListaContacto* ListaContacto;

// Función para crear una nueva lista de contactos
ListaContacto lista_contacto_crear();



// Función para añadir un contacto a la lista
void lista_contacto_add(ListaContacto *lista_contacto, Contacto contacto);

// Función para obtener un contacto en una posición específica de la lista
Contacto lista_contacto_obtener_at(ListaContacto lista_contacto, uint index);

// Función para obtener el tamaño (número de contactos) de la lista
uint lista_contacto_size(ListaContacto lista_contacto);

// Función para verificar si un contacto con el mismo nombre ya existe en la lista
bool lista_contacto_existe_nombre_contacto(ListaContacto lista_contacto, Contacto contacto);

// Función para obtener un contacto de la lista por su ID
Contacto lista_contacto_obtener_contacto_por_id(ListaContacto lista_contacto, uint contacto_id);

// Función para eliminar un contacto de la lista por su ID
void lista_contacto_eliminar_contacto_por_id(ListaContacto lista_contacto, uint contacto_id);




// Función para filtrar la lista de contactos según una propiedad y un valor específicos
ListaContacto lista_contacto_filtrar(ListaContacto lista_contacto, ContactoPropiedad filtro, const char* valor);




// Función para cargar una lista de contactos desde un archivo
ListaContacto lista_contacto_from_file();

// Función para guardar la lista de contactos en un archivo
void lista_contacto_to_file(ListaContacto lista_contacto);




// Función para destruir (liberar) la lista de contactos
void lista_contacto_destruir(ListaContacto *lista_contacto);

#endif
