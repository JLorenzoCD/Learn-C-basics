# include "../entidades.h"

struct Contacto {
    char *nombre;
    char *apellido;
    char *telefono;
    char *email;
};

PContacto contacto_crear(char nombre[], char apellido[], char telefono[], char email[]) {
    PContacto nuevo_contacto = (PContacto)malloc(sizeof(Contacto));

    size_t len_string = strlen(nombre) + 1;
    nuevo_contacto->nombre = (char*)malloc(len_string * sizeof(char));

    if (nuevo_contacto->nombre == NULL) {
        free(nuevo_contacto);
        puts("Error al asignar memoria para el nombre del contacto");
        exit(1);
    }

    len_string = strlen(apellido) + 1;
    nuevo_contacto->apellido = (char*)malloc(len_string * sizeof(char));

    if (nuevo_contacto->apellido == NULL) {
        free(nuevo_contacto->nombre);
        free(nuevo_contacto);
        puts("Error al asignar memoria para el apellido del contacto");
        exit(1);
    }

    len_string = strlen(telefono) + 1;
    nuevo_contacto->telefono = (char*)malloc(len_string * sizeof(char));

    if (nuevo_contacto->telefono == NULL) {
        free(nuevo_contacto->nombre);
        free(nuevo_contacto->apellido);
        free(nuevo_contacto);
        puts("Error al asignar memoria para el telefono del contacto");
        exit(1);
    }

    len_string = strlen(email) + 1;
    nuevo_contacto->email = (char*)malloc(len_string * sizeof(char));

    if (nuevo_contacto->email == NULL) {
        free(nuevo_contacto->nombre);
        free(nuevo_contacto->apellido);
        free(nuevo_contacto->telefono);

        free(nuevo_contacto);
        puts("Error al asignar memoria para el email del contacto");
        exit(1);
    }

    strcpy(nuevo_contacto->nombre, nombre);
    strcpy(nuevo_contacto->apellido, apellido);
    strcpy(nuevo_contacto->telefono, telefono);
    strcpy(nuevo_contacto->email, email);

    return nuevo_contacto;
}

void contacto_destruir(PContacto contacto) {
    free(contacto->nombre);
    free(contacto->apellido);
    free(contacto->telefono);
    free(contacto->email);

    free(contacto);
    contacto = NULL;
}

void contacto_destruir_array(size_t *len, ListaContactos contactos) {
    for (size_t i = 0; i < (*len); i++) {
        contacto_destruir(contactos[i]);
    }

    free(contactos);
    contactos = NULL;
}

void contacto_imprimir(PContacto contacto) {
    printf("Nombre: %s\n", contacto->nombre);
    printf("Apellido: %s\n", contacto->apellido);
    printf("Tel.: %s\n", contacto->telefono);
    printf("Email: %s\n", contacto->email);
}

void contacto_imprimir_array(size_t tam, ListaContactos contactos) {
    for (size_t i = 0; i < tam; i++) {
        printf("\nContacto N°%lu\n", i + 1);
        puts("-------------------------------");
        contacto_imprimir(contactos[i]);
    }
    puts("-------------------------------");
}

PContacto contacto_clonar(PContacto contacto_a_clonar) {
    return contacto_crear(
        contacto_a_clonar->nombre,
        contacto_a_clonar->apellido,
        contacto_a_clonar->telefono,
        contacto_a_clonar->email
    );
}

void contacto_modificar_valores(PContacto contacto, char **nombre, char **apellido, char **telefono, char **email) {
    free(contacto->nombre);
    free(contacto->apellido);
    free(contacto->telefono);
    free(contacto->email);

    contacto->nombre = *nombre;
    contacto->apellido = *apellido;
    contacto->telefono = *telefono;
    contacto->email = *email;
}

bool contacto_tiene_valor(PContacto contacto, Contacto_Propiedades propiedad, char valor[]) {
    bool tiene_valor = false;

    switch (propiedad) {
    case CONTACTO_APELLIDO:
        if (strcasecmp(contacto->apellido, valor) == 0) {
            tiene_valor = true;
        }break;

    case CONTACTO_NOMBRE:
        if (strcasecmp(contacto->nombre, valor) == 0) {
            tiene_valor = true;
        }break;

    case CONTACTO_TELEFONO:
        if (strcasecmp(contacto->telefono, valor) == 0) {
            tiene_valor = true;
        }break;

    case CONTACTO_EMAIL:
        if (strcasecmp(contacto->email, valor) == 0) {
            tiene_valor = true;
        }break;
    }

    return tiene_valor;
}

ListaContactos contacto_filtrar_por_propiedad(size_t *tam, ListaContactos contactos, Contacto_Propiedades propiedad, char valor[]) {
    ListaContactos contactos_filtrados = (ListaContactos)malloc(sizeof(PContacto) * (*tam));
    int indice_filtrados = 0;

    for (size_t i = 0; i < (*tam); i++) {
        if (contacto_tiene_valor(contactos[i], propiedad, valor)) {
            contactos_filtrados[indice_filtrados] = contactos[i];

            indice_filtrados++;
        }
    }

    contactos_filtrados = (ListaContactos)realloc(contactos_filtrados, sizeof(PContacto) * (indice_filtrados + 1));
    contactos_filtrados[indice_filtrados] = NULL;   // Marcar el final del arreglo

    *tam = indice_filtrados;

    return contactos_filtrados;
}

size_t contacto_array_len(ListaContactos contactos) {
    size_t i = 0;

    while (contactos[i] != NULL) {
        i++;
    }

    return i;
}

bool contacto_array_eliminar(size_t *tam, ListaContactos *contactos, Contacto_Propiedades propiedad, char valor[]) {
    size_t index_contacto_to_eliminar = SIZE_MAX;

    for (size_t i = 0; i < (*tam) && index_contacto_to_eliminar == SIZE_MAX; i++) {
        if (contacto_tiene_valor((*contactos)[i], propiedad, valor)) {
            index_contacto_to_eliminar = i;
        }
    }

    if (index_contacto_to_eliminar == SIZE_MAX) {
        return false;
    }

    contacto_destruir((*contactos)[index_contacto_to_eliminar]);

    *tam = *tam - 1;
    for (size_t i = index_contacto_to_eliminar; i < *tam; i++) {
        (*contactos)[i] = (*contactos)[i + 1];
    }

    // Reajustar la memoria asignada para el array de contactos
    ListaContactos temp = (ListaContactos)realloc((*contactos), ((*tam) + 1) * sizeof(PContacto));

    if (temp == NULL) {
        printf("Error al realocar memoria.\n");
        exit(-1);
        *tam = *tam + 1;
    }

    (*contactos) = temp;

    // Marcando el final del array
    (*contactos)[*tam] = NULL;

    return true;
}

void contacto_array_agregar(size_t *tam, ListaContactos *contactos, PContacto nuevo_contacto) {
    // Se utiliza ***contactos en lugar de **contactos o *contactos[] para modificar el espacio de memoria de la variable de fuera
    *tam = *tam + 1;
    ListaContactos temp = (ListaContactos)realloc(*contactos, ((*tam) + 1) * sizeof(PContacto));

    if (temp == NULL) {
        printf("Error al realocar memoria.\n");
        exit(-1);
    }

    (*contactos) = temp;

    (*contactos)[((*tam) - 1)] = nuevo_contacto;

    (*contactos)[*tam] = NULL; // Marcando el final del array
}

// Temas de prueba
ListaContactos contacto_prueba_array(size_t contactos_a_generar) {
    PContacto contacto_prueba1 = contacto_crear("Lorenzo", "Canovas", "484866634515", "lorenzo.canovas@gmail.com");
    PContacto contacto_prueba2 = contacto_crear("Pepe", "Fereira", "4154126541", "pepe.fereira@gmail.com");

    ListaContactos contactos = (ListaContactos)malloc(sizeof(PContacto) * (contactos_a_generar + 1));

    if (contactos == NULL) {
        puts("Error al asignar memoria en 'contacto_prueba_array'");
        exit(1);
    }

    for (size_t i = 0; i < contactos_a_generar; i++) {
        if (i % 2 == 0) {
            contactos[i] = contacto_clonar(contacto_prueba1);
        }
        else {
            contactos[i] = contacto_clonar(contacto_prueba2);
        }
    }

    contacto_destruir(contacto_prueba1);
    contacto_destruir(contacto_prueba2);

    // Marcando el final del array
    contactos[contactos_a_generar] = NULL;

    return contactos;
}