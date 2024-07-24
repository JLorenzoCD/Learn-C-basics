#ifndef _AGENDA_CONTACTO_H
#define _AGENDA_CONTACTO_H

typedef unsigned int uint;

#include "./opciones_agenda.h"

// Función para realizar cierta acción en la agenda de contactos según la opción seleccionada por el usuario
void agenda_contacto_realizar_accion(OpcionesAgenda opcion);

// Función para inicializar la agenda de contactos
void agenda_contacto_iniciar();

// Función para destruir o finalizar la agenda de contactos y evitar leaks de memoria
void agenda_contacto_destruir();

#endif
