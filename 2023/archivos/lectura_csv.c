#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *nombre;
    char *apellido;
    unsigned int edad;
} Persona;

Persona crear_persona(char nombre[], char apellido[], unsigned int edad);
Persona destruyendo_persona(Persona p);
Persona* crear_array_personas(int numero_personas);

Persona formatear_linea_a_persona(char linea[]);
void mostrar_cada_persona(int tam, Persona personas[]);

char* trim(char *s);

int main(void) {
    char nombre_archivo[] = "prueba.csv";

    FILE *archivo = fopen(nombre_archivo, "r");
    char buffer[255];

    if (archivo == NULL) {
        printf("Error al leer el archivo '%s'.", nombre_archivo);
        exit(1);
    }

    // Cuenta las líneas en el archivo
    int numero_lineas = 0;
    while (!feof(archivo)) {
        fgets(buffer, sizeof(buffer), archivo);

        numero_lineas++;
    }

    // Vuelve al inicio del archivo
    rewind(archivo);

    Persona *personas = crear_array_personas(numero_lineas);
    Persona temp;
    int i = 0;
    while (i < numero_lineas) {
        fgets(buffer, sizeof(buffer), archivo);
        temp = formatear_linea_a_persona(buffer);

        personas[i] = temp;

        i++;
    }

    fclose(archivo);

    mostrar_cada_persona(numero_lineas, personas);

    // Liberando el espacio en memoria de cada propiedad de la persona
    for (int i = 0; i < numero_lineas; i++) {
        destruyendo_persona(personas[i]);
    }

    // Liberando el espacio de memoria del array de personas
    free(personas);
    personas = NULL;

    return 0;
}

Persona formatear_linea_a_persona(char linea[]) {
    char *trozo_texto;

    // Obtener el primer trozo de texto
    trozo_texto = strtok(linea, ",");

    // Almacenar los tokens en variables separadas
    char nombre[30];
    char apellido[30];
    unsigned int edad;

    if (trozo_texto == NULL) {
        printf("Error en el formato del archivo\n");
        exit(1);
    }

    strcpy(nombre, trozo_texto);
    trim(nombre);
    trozo_texto = strtok(NULL, ",");

    if (trozo_texto == NULL) {
        printf("Error en el formato del archivo\n");
        exit(1);
    }

    strcpy(apellido, trozo_texto);
    trim(apellido);

    trozo_texto = strtok(NULL, ",");

    if (trozo_texto == NULL) {
        printf("Error en el formato del archivo\n");
        exit(1);
    }

    edad = atoi(trozo_texto);

    return crear_persona(nombre, apellido, edad);
}

Persona crear_persona(char nombre[], char apellido[], unsigned int edad) {
    Persona nueva_persona;

    int len_nombre = strlen(nombre) + 1;
    int len_apellido = strlen(apellido) + 1;

    nueva_persona.nombre = (char*)malloc(len_nombre * sizeof(char));
    nueva_persona.apellido = (char*)malloc(len_apellido * sizeof(char));

    if (nueva_persona.nombre == NULL || nueva_persona.apellido == NULL) {
        printf("Error al crear una nueva persona\n");
        exit(1);
    }

    strcpy(nueva_persona.nombre, nombre);
    strcpy(nueva_persona.apellido, apellido);

    nueva_persona.edad = edad;

    return nueva_persona;
}

Persona destruyendo_persona(Persona p) {
    free(p.nombre);
    free(p.apellido);

    p.nombre = NULL;
    p.apellido = NULL;

    return p;
}

char* trim(char *s) {
    char *start = s;

    //Nos comemos los espacios al inicio
    while (*start && isspace(*start)) {
        ++start;
    }

    char *i = start;
    char *end = start;

    //Nos comemos los espacios al final
    while (*i) {
        if (!isspace(*(i++))) {
            end = i;
        }
    }

    //Escribimos el terminados
    *end = 0;

    return start;
}

Persona* crear_array_personas(int numero_personas) {
    Persona *personas = (Persona*)malloc(numero_personas * (sizeof(Persona)));

    if (personas == NULL) {
        printf("Error al asignar espacio para el array de personas\n");
        exit(1);
    }

    return personas;
}

void mostrar_cada_persona(int tam, Persona personas[]) {
    printf("\n\nLas personas almacenadas en el archivo son: \n");
    printf("-------------------------------\n");
    for (int i = 0; i < tam; i++) {
        printf("Nombre: %s\n", personas[i].nombre);
        printf("Apellido: %s\n", personas[i].apellido);
        printf("Edad: %d\n", personas[i].edad);
        printf("-------------------------------\n\n");
    }
}