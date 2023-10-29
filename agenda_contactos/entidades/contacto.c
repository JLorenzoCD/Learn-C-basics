# include "../entidades.h"

Contacto *contacto_crear(char nombre[], char apellido[], char telefono[], char email[]) {
    Contacto *nuevo_contacto = (Contacto*)malloc(sizeof(Contacto));

    unsigned int len_string = strlen(nombre) + 1;
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

void contacto_destruir(Contacto *contacto) {
    free(contacto->nombre);
    free(contacto->apellido);
    free(contacto->telefono);
    free(contacto->email);

    free(contacto);
    // contacto = NULL;
}

void contacto_destruir_array(unsigned int len, Contacto **contactos) {
    for (unsigned int i = 0; i < len; i++) {
        contacto_destruir(contactos[i]);
    }

}

void contacto_imprimir(Contacto *contacto) {
    puts("-------------------------------");
    printf("Nombre: %s\n", contacto->nombre);
    printf("Apellido: %s\n", contacto->apellido);
    printf("Tel.: %s\n", contacto->telefono);
    printf("Email: %s\n", contacto->email);
}

void contacto_imprimir_array(unsigned int tam, Contacto *contactos[]) {
    for (unsigned int i = 0; i < tam; i++) {
        contacto_imprimir(contactos[i]);
    }
    puts("-------------------------------");
}

Contacto *contacto_clonar(Contacto *contacto_a_clonar) {
    return contacto_crear(
        contacto_a_clonar->nombre,
        contacto_a_clonar->apellido,
        contacto_a_clonar->telefono,
        contacto_a_clonar->email
    );
}
// Temas de prueba
Contacto **contacto_prueba_array(unsigned int contactos_a_generar) {
    Contacto *contacto_prueba = contacto_crear("Lorenzo", "Canvoas", "484866634515", "lorenzo.canovas@gmail.com");

    Contacto **contactos = (Contacto**)malloc(sizeof(Contacto*) * contactos_a_generar);

    if (contactos == NULL) {
        puts("Error al asignar memoria en 'contacto_prueba_array'");
        exit(1);
    }

    for (unsigned int i = 0; i < contactos_a_generar; i++) {
        contactos[i] = contacto_clonar(contacto_prueba);
    }

    contacto_destruir(contacto_prueba);

    return contactos;
}