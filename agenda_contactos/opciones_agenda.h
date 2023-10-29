# pragma once

// Modulos estandar
# include <stdlib.h>

// Mis modulos
# include "entidades.h"

enum OpcionesAgenda { CLOSE, GET_ALL, GET, STORE, UPDATE, DELETE };

typedef enum OpcionesAgenda OpcionesAgenda;

// Acciones del menu de la agenda
void mostrar_todos_contactos(void);
void buscar_contacto(void);