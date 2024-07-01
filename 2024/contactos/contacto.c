#include "inc/contacto.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONTACTO_FORMATO_ESPERADO "%s , %s , %s , %s "
#define CONTACTO_CANTIDAD_ATRIBUTOS 4u
#define CONTACTO_MAX_SIZE_ATRIBUTO 50u
#define CONTACTO_MAX_SIZE_BUFFER 255u

#define CONTACTO_SIZE sizeof(struct Contacto)

struct Contacto {
    char *nombre;
    char *apellido;
    char *telefono;
    char *email;
};

size_t contacto_size_t() { return CONTACTO_SIZE; }

Contacto contacto_crear(char *nombre, char *apellido, char *telefono, char *email) {
    Contacto nuevo_contacto = NULL;

    nuevo_contacto = (Contacto)malloc(CONTACTO_SIZE);
    assert(nuevo_contacto != NULL);

    nuevo_contacto->nombre = nombre;
    nuevo_contacto->apellido = apellido;
    nuevo_contacto->telefono = telefono;
    nuevo_contacto->email = email;

    return nuevo_contacto;
}

char* contacto_obtener_nombre(Contacto contacto) {
    return contacto->nombre;
}

char* contacto_obtener_apellido(Contacto contacto) {
    return contacto->apellido;
}

char* contacto_obtener_telefono(Contacto contacto) {
    return contacto->telefono;
}

char* contacto_obtener_email(Contacto contacto) {
    return contacto->email;
}

void contacto_imprimir(Contacto c) {
    printf("Nombre: %s\n", c->nombre);
    printf("Apellido: %s\n", c->apellido);
    printf("Tel.: %s\n", c->telefono);
    printf("Email: %s\n", c->email);
}

Contacto contacto_clonar(Contacto contacto_a_clonar) {
    size_t len;

    char *nombre, *apellido, *telefono, *email;
    nombre = apellido = telefono = email = NULL;

    len = strlen(contacto_a_clonar->nombre);
    nombre = (char*)malloc(sizeof(char) * (len + 1u));
    assert(nombre != NULL);

    len = strlen(contacto_a_clonar->apellido);
    apellido = (char*)malloc(sizeof(char) * (len + 1u));
    assert(apellido != NULL);

    len = strlen(contacto_a_clonar->telefono);
    telefono = (char*)malloc(sizeof(char) * (len + 1u));
    assert(telefono != NULL);

    len = strlen(contacto_a_clonar->email);
    email = (char*)malloc(sizeof(char) * (len + 1u));
    assert(email != NULL);

    strcpy(nombre, contacto_a_clonar->nombre);
    strcpy(apellido, contacto_a_clonar->apellido);
    strcpy(telefono, contacto_a_clonar->telefono);
    strcpy(email, contacto_a_clonar->email);

    return contacto_crear(
        nombre,
        apellido,
        telefono,
        email
    );
}

void contacto_destruir(Contacto *c) {
    Contacto contacto_a_borrar = *c;

    free(contacto_a_borrar->nombre);
    free(contacto_a_borrar->apellido);
    free(contacto_a_borrar->telefono);
    free(contacto_a_borrar->email);

    free(contacto_a_borrar);

    *c = NULL;
}

Contacto contacto_from_file_line(FILE *file) {
    char fnombre[CONTACTO_MAX_SIZE_ATRIBUTO] = "";
    char fapellido[CONTACTO_MAX_SIZE_ATRIBUTO] = "";
    char ftelefono[CONTACTO_MAX_SIZE_ATRIBUTO] = "";
    char femail[CONTACTO_MAX_SIZE_ATRIBUTO] = "";

    int res = fscanf(file, CONTACTO_FORMATO_ESPERADO, fnombre, fapellido, ftelefono, femail);

    if (res == -1) {  // No hay nada
        return NULL;
    }

    assert(res == CONTACTO_CANTIDAD_ATRIBUTOS);

    size_t len;
    char *nombre = NULL, *apellido = NULL, *telefono = NULL, *email = NULL;

    len = strlen(fnombre);
    nombre = (char*)malloc(sizeof(char) * (len + 1u));
    assert(nombre != NULL);

    len = strlen(fapellido);
    apellido = (char*)malloc(sizeof(char) * (len + 1u));
    assert(apellido != NULL);

    len = strlen(ftelefono);
    telefono = (char*)malloc(sizeof(char) * (len + 1u));
    assert(telefono != NULL);

    len = strlen(femail);
    email = (char*)malloc(sizeof(char) * (len + 1u));
    assert(email != NULL);

    strcpy(nombre, fnombre);
    strcpy(apellido, fapellido);
    strcpy(telefono, ftelefono);
    strcpy(email, femail);

    return contacto_crear(
        nombre,
        apellido,
        telefono,
        email
    );
}
