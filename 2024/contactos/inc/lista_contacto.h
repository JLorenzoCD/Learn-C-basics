#ifndef _LISTA_CONTACTO_H
#define _LISTA_CONTACTO_H

#include "contacto.h"

typedef unsigned int uint;
typedef struct ListaContacto* ListaContacto;

ListaContacto lista_contacto_from_file();
uint lista_contacto_size(ListaContacto lista_contacto);
Contacto lista_contacto_obtener_at(ListaContacto lista_contacto, uint index);
void lista_contacto_destruir(ListaContacto *lista_contacto);

#endif
