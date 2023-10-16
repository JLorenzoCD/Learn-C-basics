# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <assert.h>
# include <stdbool.h>

# define MAX_INTENTOS 6

typedef enum {Fruta, Animal, Pais, Objeto}Categoria;
const char *NOMBRE_CATEGORIA[] = {"Frutas","Animales","Paises","Objetos"};

const char FRUTAS [10][15] = {"MELON","PAPAYA","SANDIA","MANZANA","PERA","NARANJA","UVA","CEREZA","CIRUELA","KIWI"};
const char ANIMALES [10][15] = {"PERRO","GATO","CABALLO","GALLINA","JIRAFA","MONO","VACA","CONEJO","TORTUGA","LOBO"};
const char PAISES [10][15] = {"PERU","COLOMBIA","ARGENTINA","NICARAGUA","ITALIA","MEXICO","CANADA","VENEZUELA","ECUADOR","BRASIL"};
const char OBJETOS [10][15] = {"MOCHILA","RELOJ","ZAPATILLA","MUEBLE","CUADERNO","SILLA","MESA","CELULAR","PUERTA","AURICULARES"};

typedef struct{
	int intentos;
	int puntos;

	Categoria categoria;

	int longitud;
	char *palabra_a_adivinar;
	char *frase;

} JuegoAhorcado;

void seleccionar_categoria(void);
void obtener_palabra_a_adivinar(void);
void estableciendo_valores_base_ahorcado(void);
void empezar_partida(void);
bool empezar_nueva_partida(void);

void imprimir_cabecera_ahorcado(void);
void dibujo(void);

bool hay_acierto(char letra);
bool se_gano(void);

void completar_frase(char letra);

int generar_entero_hasta(int n);
char a_mayuscula(char c);
void limpiar_buffer(void);

void asignar_memoria_para_frase_y_palabra(void);

JuegoAhorcado DATOS_JUEGO;

int main(void){
	bool continuar_jugando = true;
	do
	{
		estableciendo_valores_base_ahorcado();
		empezar_partida();

		continuar_jugando = empezar_nueva_partida();
	} while (continuar_jugando);

	printf("\n\n#############################################\n");
	printf("              Gracias por jugar!!");
	printf("\n#############################################\n\n");

	return 0;
}

void seleccionar_categoria(void){
	int op;
	do{
		system("clear");
		printf("\n\t\t\t\tJUEGO EL AHORCADO\n\n");
		printf(" CATEGORIAS\n\n");
		printf(" 1. Frutas\n");
		printf(" 2. Animales\n");
		printf(" 3. Paises\n");
		printf(" 4. Objetos\n\n");

		printf(" Ingresa una opcion: "); scanf("%i", &op);
	}while(!(1 <= op && op <= 4));
	assert((1 <= op && op <= 4) && "La opcion seleccionada no se encuentra entre el intervalo [1, 4]");

	DATOS_JUEGO.categoria = op - 1;
}

void obtener_palabra_a_adivinar(void){
	int index_palabra_adivinar = generar_entero_hasta(10);

	switch(DATOS_JUEGO.categoria){
		case Fruta:
			DATOS_JUEGO.longitud = strlen(FRUTAS[index_palabra_adivinar]);

			asignar_memoria_para_frase_y_palabra();
			strcpy(DATOS_JUEGO.palabra_a_adivinar, FRUTAS[index_palabra_adivinar]);
			break;

		case Animal:
			DATOS_JUEGO.longitud = strlen(ANIMALES[index_palabra_adivinar]);

			asignar_memoria_para_frase_y_palabra();
			strcpy(DATOS_JUEGO.palabra_a_adivinar, ANIMALES[index_palabra_adivinar]);
			break;

		case Pais:
			DATOS_JUEGO.longitud = strlen(PAISES[index_palabra_adivinar]);

			asignar_memoria_para_frase_y_palabra();
			strcpy(DATOS_JUEGO.palabra_a_adivinar, PAISES[index_palabra_adivinar]);
			break;

		case Objeto:
			DATOS_JUEGO.longitud = strlen(OBJETOS[index_palabra_adivinar]);

			asignar_memoria_para_frase_y_palabra();
			strcpy(DATOS_JUEGO.palabra_a_adivinar, OBJETOS[index_palabra_adivinar]);
			break;
	}

	// Estableciendo las letras de la frase a adivinar como caracteres '_'
	for(int i = 0; i < DATOS_JUEGO.longitud; i++){
		DATOS_JUEGO.frase[i] = '_';
	}
}

void estableciendo_valores_base_ahorcado(void){
	seleccionar_categoria();
	obtener_palabra_a_adivinar();

	DATOS_JUEGO.intentos = 0;
	DATOS_JUEGO.puntos = 1200;
}

void empezar_partida(void){
	char letra;
	bool partida_terminada = false;
	bool acierto;
	bool ganado = false;

	do{
		acierto = false;

		imprimir_cabecera_ahorcado();

		limpiar_buffer();
		printf("\n\n Digite una letra: "); scanf(" %c", &letra);
		letra = a_mayuscula(letra);

		acierto = hay_acierto(letra);

		if(acierto){
			completar_frase(letra);
			ganado = se_gano();
		}else{
			DATOS_JUEGO.intentos++;
			DATOS_JUEGO.puntos -= 200;
		}

		if (DATOS_JUEGO.intentos == MAX_INTENTOS){
			imprimir_cabecera_ahorcado();
			printf("\n\n PERDISTE!!\n");
			printf(" LA SOLUCION ERA: %s\n\n", DATOS_JUEGO.palabra_a_adivinar);

			partida_terminada = true;
		}

		if (ganado){
			imprimir_cabecera_ahorcado();
			printf("\n\n FELICIDADES.. GANASTE!!\n\n");

			partida_terminada = true;
		}

	}while(!partida_terminada);
	printf("\n\n");
}

bool se_gano(void){
	int espacios = 0;

	for (int i = 0; i < DATOS_JUEGO.longitud; i++){
		if (DATOS_JUEGO.frase[i] == '_')
			espacios++;
	}

	return espacios == 0;
}

void imprimir_cabecera_ahorcado(void){
	system("clear");
	printf("\n\t\t\t\tJUEGO EL AHORCADO\n\n");
	printf(" CATEGORIA: %s\n\n", NOMBRE_CATEGORIA[DATOS_JUEGO.categoria]);
	printf(" Intentos Disponibles: %i\t\t\t\tPuntuacion: %i\n\n", 6 - DATOS_JUEGO.intentos, DATOS_JUEGO.puntos);
	dibujo();

	//IMPRIME EL ARRAY DE CARACTERES FRASE
	printf("\n\n\n");
	for(int i = 0; i < DATOS_JUEGO.longitud; i++){
		printf(" %c ",DATOS_JUEGO.frase[i]);
	}
}

bool hay_acierto(char letra){
	bool encontrado = false;

	if (strchr(DATOS_JUEGO.palabra_a_adivinar, letra) != NULL) {
        encontrado = true;
    }

	printf("LETRA = %c\n\n", letra);

	return encontrado;
}

void completar_frase(char letra){
	for (int i = 0; i < DATOS_JUEGO.longitud; i++){
		if (letra == DATOS_JUEGO.palabra_a_adivinar[i]){
			DATOS_JUEGO.frase[i] = DATOS_JUEGO.palabra_a_adivinar[i];
		}
	}
}

void dibujo(void){
	int intentos = DATOS_JUEGO.intentos;

	printf("\n     _______\n");
	printf("    |       |\n");
	printf("    |       %c\n", 0 < intentos ? '0' : ' ');
	printf("    |      %c%c%c \n", 2 < intentos ? '/' : ' ', 1 < intentos ? '|' : ' ', 3 < intentos ? '\\' : ' ');
	printf("    |      %c %c \n", 4 < intentos ? '/' : ' ', 5 < intentos ? '\\' : ' ');
	printf("    |\n");
	printf("    |\n");
	printf(" ----------");
}

int generar_entero_hasta(int n){
	srand(time(NULL));

	if( n <= 0){
		return rand() % 10;
	}

	return rand() % n;
}

void asignar_memoria_para_frase_y_palabra(void){
	int largo_str = DATOS_JUEGO.longitud + 1; // Termina en \0

	DATOS_JUEGO.palabra_a_adivinar = (char*)malloc(largo_str*sizeof(char));
	DATOS_JUEGO.frase = (char*)malloc(largo_str*sizeof(char));

	if (DATOS_JUEGO.palabra_a_adivinar == NULL || DATOS_JUEGO.frase == NULL){
		printf("Ocurrio un error al asignar espacio en la memoria\n");
		exit(1);
	}
}

bool empezar_nueva_partida(void){
	char caracter;

	limpiar_buffer();

	printf("Desea para volver a jugar? (S/N): "); scanf(" %c", &caracter);

	return a_mayuscula(caracter) == 'S';
}

char a_mayuscula(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 32;
    }
    return c;
}

void limpiar_buffer(void){
	int c;
	while ((c = getchar()) != '\n' && c != EOF) { }
}