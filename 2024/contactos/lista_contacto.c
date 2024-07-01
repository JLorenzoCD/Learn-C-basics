#include "inc/lista_contacto.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "inc/contacto.h"

#define LISTA_CONTACTO_SIZE sizeof(struct ListaContacto)

struct ListaContacto {
    uint capacidad;
    uint length;
    Contacto *array;
};




ListaContacto lista_contacto_crear() {
    ListaContacto lista_contacto = NULL;
    uint capacidad = 1u;

    lista_contacto = (ListaContacto)malloc(LISTA_CONTACTO_SIZE);
    assert(lista_contacto != NULL);

    lista_contacto->array = NULL;
    lista_contacto->length = 0u;
    lista_contacto->capacidad = capacidad;

    size_t contacto_size = contacto_size_t();
    lista_contacto->array = (Contacto*)calloc(lista_contacto->capacidad, contacto_size);
    assert(lista_contacto->array != NULL);

    return lista_contacto;
}

uint lista_contacto_size(ListaContacto lista_contacto) {
    return lista_contacto->length;
}

Contacto lista_contacto_obtener_at(ListaContacto lista_contacto, uint index) {
    assert(index < lista_contacto->length);

    return lista_contacto->array[index];
}

void lista_contacto_destruir(ListaContacto *lista_contacto) {
    ListaContacto lc = *lista_contacto;

    for (uint i = 0; i < lc->length; i++) {
        contacto_destruir(&(lc->array[i]));
    }

    free(lc);
    *lista_contacto = NULL;
}

void lista_contacto_add(ListaContacto *lista_contacto, Contacto contacto) {
    ListaContacto lc = *lista_contacto;

    if (lc->capacidad <= lc->length) {
        lc->capacidad = lc->capacidad * 2;

        size_t contacto_size = contacto_size_t();
        lc->array = (Contacto*)realloc(lc->array, contacto_size * lc->capacidad);
        assert(lc != NULL);
    }

    lc->array[lc->length] = contacto;
    lc->length++;

    *lista_contacto = lc;
}

ListaContacto lista_contacto_from_file() {
    char filepath[] = "db/contacto.db";

    FILE *file = NULL;
    file = fopen(filepath, "r");

    if (file == NULL) {
        fprintf(stderr, "%s", "File does not exist.\n");
        exit(EXIT_FAILURE);
    }

    ListaContacto lista_contacto = lista_contacto_crear();
    while (!feof(file)) {
        Contacto c = contacto_from_file_line(file);

        if (c == NULL) {
            break;
        }

        lista_contacto_add(&lista_contacto, c);
    }
    fclose(file);

    return lista_contacto;
}