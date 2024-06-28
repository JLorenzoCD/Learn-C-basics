#ifndef _CONTACTO_H
#define _CONTACTO_H

typedef unsigned int uint;

typedef struct Contacto* Contacto;
typedef struct ListaContacto* ListaContacto;

ListaContacto lista_contacto_from_file();
uint lista_contacto_size(ListaContacto lista_contacto);
Contacto lista_contacto_obtener_at(ListaContacto lista_contacto, uint index);

#endif
