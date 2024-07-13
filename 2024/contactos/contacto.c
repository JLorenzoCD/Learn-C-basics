#include "inc/contacto.h"


#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

#include "inc/terminal.h"


#define CONTACTO_FORMATO_ESPERADO "%u , %s , %s , %s , %s "
#define CONTACTO_CANTIDAD_ATRIBUTOS 5u

#define CONTACTO_SIZE sizeof(struct Contacto)

struct Contacto {
    uint id;
    char *nombre;
    char *apellido;
    char *telefono;
    char *email;
};


size_t contacto_size_t() { return CONTACTO_SIZE; }

uint contacto_generar_id() {
    int numero_random = arc4random();

    return (uint)numero_random;
}

Contacto contacto_craer_por_input(
    const char *mensaje_pedir_nombre,
    const char *mensaje_pedir_apellido,
    const char *mensaje_pedir_telefono,
    const char *mensaje_pedir_email
) {
    char nombre[CONTACTO_MAX_SIZE_ATRIBUTO] = "";
    char apellido[CONTACTO_MAX_SIZE_ATRIBUTO] = "";
    char telefono[CONTACTO_MAX_SIZE_ATRIBUTO] = "";
    char email[CONTACTO_MAX_SIZE_ATRIBUTO] = "";

    limpiar_stdin();
    obtener_str(nombre, CONTACTO_MAX_SIZE_ATRIBUTO, mensaje_pedir_nombre);
    obtener_str(apellido, CONTACTO_MAX_SIZE_ATRIBUTO, mensaje_pedir_apellido);
    obtener_str(telefono, CONTACTO_MAX_SIZE_ATRIBUTO, mensaje_pedir_telefono);
    obtener_str(email, CONTACTO_MAX_SIZE_ATRIBUTO, mensaje_pedir_email);

    uint id = contacto_generar_id();

    Contacto nuevo_contacto = contacto_crear(id, nombre, apellido, telefono, email);

    return nuevo_contacto;
}

Contacto contacto_crear(uint id, const char *nombre, const char *apellido, const char *telefono, const char *email) {
    Contacto nuevo_contacto = NULL;

    nuevo_contacto = (Contacto)malloc(CONTACTO_SIZE);
    assert(nuevo_contacto != NULL);

    size_t len;

    len = strlen(nombre);
    nuevo_contacto->nombre = (char*)malloc(sizeof(char) * (len + 1u));
    assert(nuevo_contacto->nombre != NULL);

    len = strlen(apellido);
    nuevo_contacto->apellido = (char*)malloc(sizeof(char) * (len + 1u));
    assert(nuevo_contacto->apellido != NULL);

    len = strlen(telefono);
    nuevo_contacto->telefono = (char*)malloc(sizeof(char) * (len + 1u));
    assert(nuevo_contacto->telefono != NULL);

    len = strlen(email);
    nuevo_contacto->email = (char*)malloc(sizeof(char) * (len + 1u));
    assert(nuevo_contacto->email != NULL);

    nuevo_contacto->id = id;
    strcpy(nuevo_contacto->nombre, nombre);
    strcpy(nuevo_contacto->apellido, apellido);
    strcpy(nuevo_contacto->telefono, telefono);
    strcpy(nuevo_contacto->email, email);

    return nuevo_contacto;
}

void contacto_modificar(Contacto contacto, ContactoPropiedad propiedad, const char* valor) {
    size_t len;

    switch (propiedad) {
    case NOMBRE:
        free(contacto->nombre);
        contacto->nombre = NULL;

        len = strlen(valor);
        contacto->nombre = (char*)malloc(sizeof(char) * (len + 1u));
        assert(contacto->nombre != NULL);

        strcpy(contacto->nombre, valor);
        break;

    case APELLIDO:
        free(contacto->apellido);
        contacto->apellido = NULL;

        len = strlen(valor);
        contacto->apellido = (char*)malloc(sizeof(char) * (len + 1u));
        assert(contacto->apellido != NULL);

        strcpy(contacto->apellido, valor);
        break;

    case TELEFONO:
        free(contacto->telefono);
        contacto->telefono = NULL;

        len = strlen(valor);
        contacto->telefono = (char*)malloc(sizeof(char) * (len + 1u));
        assert(contacto->telefono != NULL);

        strcpy(contacto->telefono, valor);
        break;

    case EMAIL:
        free(contacto->email);
        contacto->email = NULL;

        len = strlen(valor);
        contacto->email = (char*)malloc(sizeof(char) * (len + 1u));
        assert(contacto->email != NULL);

        strcpy(contacto->email, valor);
        break;
    }
}

uint contacto_obtener_id(Contacto contacto) {
    return contacto->id;
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
    // printf("ID: %u\n", c->id);
    printf("Nombre: %s\n", c->nombre);
    printf("Apellido: %s\n", c->apellido);
    printf("Tel.: %s\n", c->telefono);
    printf("Email: %s\n", c->email);
}

Contacto contacto_clonar(Contacto contacto_a_clonar) {
    return contacto_crear(
        contacto_a_clonar->id,
        contacto_a_clonar->nombre,
        contacto_a_clonar->apellido,
        contacto_a_clonar->telefono,
        contacto_a_clonar->email
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
    uint id = 0u;
    char fnombre[CONTACTO_MAX_SIZE_ATRIBUTO] = "";
    char fapellido[CONTACTO_MAX_SIZE_ATRIBUTO] = "";
    char ftelefono[CONTACTO_MAX_SIZE_ATRIBUTO] = "";
    char femail[CONTACTO_MAX_SIZE_ATRIBUTO] = "";

    int res = fscanf(file, CONTACTO_FORMATO_ESPERADO, &id, fnombre, fapellido, ftelefono, femail);

    if (res == -1) {  // No hay nada
        return NULL;
    }

    assert(res == CONTACTO_CANTIDAD_ATRIBUTOS);

    return contacto_crear(
        id,
        fnombre,
        fapellido,
        ftelefono,
        femail
    );
}


char *contacto_propiedad_a_str(ContactoPropiedad propiedad) {
    char *propiedad_str = NULL;

    switch (propiedad) {
    case NOMBRE:
        propiedad_str = "nombre";
        break;

    case APELLIDO:
        propiedad_str = "apellido";
        break;

    case TELEFONO:
        propiedad_str = "telefono";
        break;

    case EMAIL:
        propiedad_str = "email";
        break;

    default:
        propiedad_str = "";
    }

    return propiedad_str;
}

bool contacto_propiedad_es_valido(int opcion) {
    --opcion;

    return CONTACTO_PROPIEDAD_PRIMERA <= opcion && opcion <= CONTACTO_PROPIEDAD_ULTIMA;
}
