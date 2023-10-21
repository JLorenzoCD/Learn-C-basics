// Modulos estandar
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <assert.h>
# include <stdbool.h>

// Mis modulos
# include "tipos.h"
# include "constantes.h"
# include "imprimir.h"
# include "utilidades.h"

void seleccionar_categoria(void);
void obtener_palabra_a_adivinar(void);
void iniciar_juego(void);
void empezar_partida(void);

bool hay_acierto(char letra);
bool se_gano(void);

void completar_frase(char letra);

void asignar_memoria_para_frase_y_palabra(void);

int main(void) {
	bool continuar_jugando = true;
	do {
		iniciar_juego();
		empezar_partida();

		continuar_jugando = imprimir_pregunta_seguir_jugando();
	} while (continuar_jugando);

	imprimir_msg_fin();

	return 0;
}

void seleccionar_categoria(void) {
	int op;
	do {
		imprimir_opciones_categorias();

		printf(" Ingresa una opcion: "); scanf("%i", &op);
	} while (!(1 <= op && op <= 4));
	assert((1 <= op && op <= 4) && "La opcion seleccionada no se encuentra entre el intervalo [1, 4]");

	DATOS_JUEGO.categoria = op - 1;
}

void obtener_palabra_a_adivinar(void) {
	int index_palabra_adivinar = generar_entero_hasta(10);

	switch (DATOS_JUEGO.categoria) {
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
	for (int i = 0; i < DATOS_JUEGO.longitud; i++) {
		DATOS_JUEGO.frase[i] = '_';
	}
}

void iniciar_juego(void) {
	seleccionar_categoria();
	obtener_palabra_a_adivinar();

	DATOS_JUEGO.intentos = 0;
	DATOS_JUEGO.puntos = 1200;
}

void empezar_partida(void) {
	char letra;
	bool partida_terminada = false;
	bool acierto;
	bool ganado = false;

	do {
		acierto = false;

		imprimir_ahorcado();

		limpiar_buffer();
		printf("\n\n Digite una letra: "); scanf(" %c", &letra);
		letra = toupper(letra);

		acierto = hay_acierto(letra);

		if (acierto) {
			completar_frase(letra);
			ganado = se_gano();
		}
		else {
			DATOS_JUEGO.intentos++;
			DATOS_JUEGO.puntos -= 200;
		}

		if (DATOS_JUEGO.intentos == MAX_INTENTOS) {
			imprimir_msg_perdiste();

			partida_terminada = true;
		}

		if (ganado) {
			imprimir_msg_ganaste();

			partida_terminada = true;
		}

	} while (!partida_terminada);
	printf("\n\n");
}

bool se_gano(void) {
	int espacios = 0;

	for (int i = 0; i < DATOS_JUEGO.longitud; i++) {
		if (DATOS_JUEGO.frase[i] == '_')
			espacios++;
	}

	return espacios == 0;
}


bool hay_acierto(char letra) {
	bool encontrado = false;

	if (strchr(DATOS_JUEGO.palabra_a_adivinar, letra) != NULL) {
		encontrado = true;
	}

	return encontrado;
}

void completar_frase(char letra) {
	for (int i = 0; i < DATOS_JUEGO.longitud; i++) {
		if (letra == DATOS_JUEGO.palabra_a_adivinar[i]) {
			DATOS_JUEGO.frase[i] = DATOS_JUEGO.palabra_a_adivinar[i];
		}
	}
}

void asignar_memoria_para_frase_y_palabra(void) {
	int largo_str = DATOS_JUEGO.longitud + 1; // Termina en \0

	DATOS_JUEGO.palabra_a_adivinar = (char*)malloc(largo_str * sizeof(char));
	DATOS_JUEGO.frase = (char*)malloc(largo_str * sizeof(char));

	if (DATOS_JUEGO.palabra_a_adivinar == NULL || DATOS_JUEGO.frase == NULL) {
		printf("Ocurrio un error al asignar espacio en la memoria\n");
		exit(1);
	}
}