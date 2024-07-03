#ifndef _OPCIONES_AGENDA_H
#define _OPCIONES_AGENDA_H

typedef unsigned int uint;

typedef enum {
    MOSTRAR_TODOS_LOS_CONTACTOS,
    BUSCAR_UN_CONTACTO,
    ALMACENAR_CONTACTO,
    EDITAR_CONTACTO,
    ELIMINAR_CONTACTO,
    SALIR
} OpcionesAgenda;

OpcionesAgenda obtener_opcion();
char *opcion_a_str(OpcionesAgenda opcion);

#endif
