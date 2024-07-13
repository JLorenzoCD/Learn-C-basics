#ifndef _LISTA_CONTACTO_H
#define _LISTA_CONTACTO_H

#include <stdbool.h>

#include "contacto.h"

typedef unsigned int uint;
typedef struct ListaContacto* ListaContacto;

ListaContacto lista_contacto_from_file();
uint lista_contacto_size(ListaContacto lista_contacto);
void lista_contacto_add(ListaContacto *lista_contacto, Contacto contacto);
Contacto lista_contacto_obtener_at(ListaContacto lista_contacto, uint index);
bool lista_contacto_existe_nombre_contacto(ListaContacto lista_contacto, Contacto contacto);
Contacto lista_contacto_obtener_contacto_por_id(ListaContacto lista_contacto, uint contacto_id);
void lista_contacto_eliminar_contacto_por_id(ListaContacto lista_contacto, uint contacto_id);
ListaContacto lista_contacto_filtrar(ListaContacto lista_contacto, ContactoPropiedad filtro, const char* valor);
void lista_contacto_destruir(ListaContacto *lista_contacto);

#endif
