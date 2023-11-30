# pragma once

# include "./../base_estructuras.h"

struct Cola {
    PNodo primero;
    PNodo ultimo;
};

typedef struct Cola Cola;
typedef Cola *PCola;

Cola cola_crear(void);
void cola_agregar(PCola cola, T dato);
T cola_quitar(PCola cola);