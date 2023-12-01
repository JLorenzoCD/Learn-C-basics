# pragma once

# include "./../base_estructuras.h"

struct Cola {
    PNodo primero;
    PNodo ultimo;
    size_t tam;
};

typedef struct Cola Cola;
typedef Cola *PCola;

Cola cola_crear(void);
void cola_agregar(PCola cola, T dato);
T cola_quitar(PCola cola);