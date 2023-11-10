# pragma once

// Modulos estandar
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdint.h>

enum Contacto_Propiedades { CONTACTO_NOMBRE, CONTACTO_APELLIDO, CONTACTO_TELEFONO, CONTACTO_EMAIL };

// Tipo Opaco ( CONTACTO )
typedef struct Contacto Contacto;
typedef Contacto *PContacto;
typedef Contacto **ListaContactos;

typedef enum Contacto_Propiedades Contacto_Propiedades;

PContacto contacto_crear(char nombre[], char apellido[], char telefono[], char email[]);

void contacto_destruir(PContacto contacto);
void contacto_destruir_array(size_t *len, ListaContactos contactos);

void contacto_imprimir(PContacto contacto);
void contacto_imprimir_array(size_t tam, ListaContactos contactos);

size_t contacto_array_len(ListaContactos contactos);
void contacto_modificar_valores(PContacto contacto, char **nombre, char **apellido, char **telefono, char **email);
bool contacto_tiene_valor(PContacto contacto, Contacto_Propiedades propiedad, char valor[]);
ListaContactos contacto_filtrar_por_propiedad(size_t *tam, ListaContactos contactos, Contacto_Propiedades propiedad, char valor[]);
bool contacto_array_eliminar(size_t *tam, ListaContactos *contactos, Contacto_Propiedades propiedad, char valor[]);
void contacto_array_agregar(size_t *tam, ListaContactos *contactos, PContacto nuevo_contacto);

// Temas de prueba
ListaContactos contacto_prueba_array(size_t contactos_a_generar);