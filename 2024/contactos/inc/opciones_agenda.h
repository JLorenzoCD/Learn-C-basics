#ifndef _OPCIONES_AGENDA_H
#define _OPCIONES_AGENDA_H

#include "contacto.h"

typedef unsigned int uint;

typedef enum {
    MOSTRAR_TODOS_LOS_CONTACTOS,
    BUSCAR_UN_CONTACTO,
    ALMACENAR_CONTACTO,
    EDITAR_CONTACTO,
    ELIMINAR_CONTACTO,
    SALIR
} OpcionesAgenda;

#define PRIMERA_OPCION MOSTRAR_TODOS_LOS_CONTACTOS
#define ULTIMA_OPCION SALIR

// Función para obtener la opción seleccionada por el usuario
OpcionesAgenda agenda_contacto_obtener_opcion(void);

// Función para convertir una opción de la agenda a una cadena de caracteres
char *agenda_contacto_opcion_a_str(OpcionesAgenda opcion);


// Función para obtener una opción relacionada con las propiedades de un contacto
ContactoPropiedad contacto_propiedad_obtener_opcion(void);

#endif
