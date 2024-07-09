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

OpcionesAgenda agenda_contacto_obtener_opcion(void);
char *agenda_contacto_opcion_a_str(OpcionesAgenda opcion);

ContactoPropiedad contacto_propiedad_obtener_opcion(void);

#endif
