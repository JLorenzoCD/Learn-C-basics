# pragma once

// Modulos estandar
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

// Mis modulos
# include "entidades.h"
# include "utilidades.h"
# include "constantes.h"
# include "imprimir.h"

enum OpcionesAgenda { CLOSE, GET_ALL, GET, STORE, UPDATE, DELETE };

typedef enum OpcionesAgenda OpcionesAgenda;

// Acciones del menu de la agenda
void mostrar_todos_contactos(void);
void buscar_contacto(void);
void nuevo_contacto(void);
void modificar_contacto(void);
void eliminar_contacto(void);