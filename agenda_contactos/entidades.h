# pragma once

// Modulos estandar
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdbool.h>

// Entidad Contacto
struct Contacto {
    char *nombre;
    char *apellido;
    char *telefono;
    char *email;
};

enum Contacto_Propiedades { CONTACTO_NOMBRE, CONTACTO_APELLIDO, CONTACTO_TELEFONO, CONTACTO_EMAIL };

typedef struct Contacto Contacto;
typedef enum Contacto_Propiedades Contacto_Propiedades;

Contacto *contacto_crear(char nombre[], char apellido[], char telefono[], char email[]);

void contacto_destruir(Contacto *contacto);
void contacto_destruir_array(unsigned int len, Contacto **contactos);

void contacto_imprimir(Contacto *contacto);
void contacto_imprimir_array(unsigned int tam, Contacto *contactos[]);

unsigned int contacto_array_len(Contacto *contactos[]);
bool contacto_tiene_valor(Contacto *contacto, Contacto_Propiedades propiedad, char valor[]);
Contacto **contacto_filtrar_por_propiedad(unsigned int tam, Contacto *contactos[], Contacto_Propiedades propiedad, char valor[]);

// Temas de prueba
Contacto **contacto_prueba_array(unsigned int contactos_a_generar);