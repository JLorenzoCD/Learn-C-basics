# include <stdlib.h>
# include <stdio.h>
# include <string.h>

void limpiar_buffer(void);

typedef struct {
    char *nombre;
    char *apellido;
    int edad;
}Persona;


int main(void) {
    char nombre_archivo[] = "escritura.csv";

    FILE *archivo = fopen(nombre_archivo, "a");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    Persona nueva_persona;
    char temp[255];

    printf("-----------Ingresando datos de una persona-----------\n");
    printf("Nombre: ");scanf("%s", temp);
    limpiar_buffer();

    int len_nombre = strlen(temp) + 1;
    nueva_persona.nombre = (char*)malloc(len_nombre * sizeof(char));
    strcpy(nueva_persona.nombre, temp);

    memset(temp, 0, sizeof(temp));
    printf("Apellido: ");scanf("%s", temp);
    limpiar_buffer();

    int len_apellido = strlen(temp) + 1;
    nueva_persona.apellido = (char*)malloc(len_apellido * sizeof(char));
    strcpy(nueva_persona.apellido, temp);

    int aux = 0;
    printf("Edad: ");scanf("%i", &aux);
    nueva_persona.edad = aux;

    fprintf(archivo, "%s, %s, %i\n", nueva_persona.nombre, nueva_persona.apellido, nueva_persona.edad);

    fclose(archivo);

    free(nueva_persona.nombre);
    free(nueva_persona.apellido);
    nueva_persona.nombre = NULL;
    nueva_persona.apellido = NULL;

    return 0;
}

void limpiar_buffer(void) {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}