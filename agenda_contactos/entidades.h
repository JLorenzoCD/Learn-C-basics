# pragma once

// Modulos estandar
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

// Entidad Contacto
struct Contacto {
    char *nombre;
    char *apellido;
    char *telefono;
    char *email;
};

typedef struct Contacto Contacto;

Contacto *contacto_crear(char nombre[], char apellido[], char telefono[], char email[]);

void contacto_destruir(Contacto *contacto);
void contacto_destruir_array(unsigned int len, Contacto **contactos);

void contacto_imprimir(Contacto *contacto);
void contacto_imprimir_array(unsigned int tam, Contacto *contactos[]);

// Temas de prueba
Contacto **contacto_prueba_array(unsigned int contactos_a_generar);