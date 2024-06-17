#ifndef _OPCIONES_AGENDA_H
#define _OPCIONES_AGENDA_H

typedef unsigned int uint;

typedef enum {
    OBTENER_TODOS_LOS_CONTACTOS,
    OBTENER_UN_CONTACTO,
    ALMACENAR_CONTACTO,
    ACTUALIZAR_CONTACTO,
    ELIMINAR_CONTACTO,
    SALIR
} OpcionesAgenda;

OpcionesAgenda obtener_opcion();

#endif
