#ifndef _CONTACTO_H
#define _CONTACTO_H

typedef unsigned int uint;

typedef struct Contacto* Contacto;
typedef struct ListaContacto* ListaContacto;

char* contacto_obtener_nombre(Contacto contacto);
char* contacto_obtener_apellido(Contacto contacto);
char* contacto_obtener_telefono(Contacto contacto);
char* contacto_obtener_email(Contacto contacto);
void contacto_imprimir(Contacto c);

ListaContacto lista_contacto_from_file();
uint lista_contacto_size(ListaContacto lista_contacto);
Contacto lista_contacto_obtener_at(ListaContacto lista_contacto, uint index);
void lista_contacto_destruir(ListaContacto *lista_contacto);

#endif
