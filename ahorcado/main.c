// Modulos estandar
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <assert.h>
# include <stdbool.h>

// Mis modulos
# include "tipos.h"
# include "global.h"
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
		// Usuario selecciona categoria y se le da una palabra al azar a adivinar
		iniciar_juego();
		// El usuario juega hasta adivinar o que se le acaben los intentos
		empezar_partida();

		// Se le pregunta al usuario si desea seguir jugando
		continuar_jugando = imprimir_pregunta_seguir_jugando();
	} while (continuar_jugando);

	// El usuario no quiere seguir jugando, por lo que se le imprime mensaje de cierre del juego
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

	const char *palabra_adivinar;
	switch (DATOS_JUEGO.categoria) {
	case Fruta:
		palabra_adivinar = FRUTAS[index_palabra_adivinar];break;

	case Animal:
		palabra_adivinar = ANIMALES[index_palabra_adivinar];break;

	case Pais:
		palabra_adivinar = PAISES[index_palabra_adivinar];break;

	case Objeto:
		palabra_adivinar = OBJETOS[index_palabra_adivinar];break;
	}

	DATOS_JUEGO.longitud = strlen(palabra_adivinar);
	asignar_memoria_para_frase_y_palabra();
	strcpy(DATOS_JUEGO.palabra_a_adivinar, palabra_adivinar);

	// Estableciendo las letras de la frase a adivinar como caracteres '_'
	for (int i = 0; i < DATOS_JUEGO.longitud; i++) {
		DATOS_JUEGO.frase[i] = '_';
	}
}

void iniciar_juego(void) {
	// El usuario selecciona que tipo de palabra va a adivinar segun ciertas categorias
	seleccionar_categoria();
	// Segun la categoria asignada se selecciona al azar una palabra
	obtener_palabra_a_adivinar();

	DATOS_JUEGO.intentos = 0;
	DATOS_JUEGO.puntos = 1200;
}

void empezar_partida(void) {
	char letra; // Variable utilizada para recibir la letra que puede estar en la palabra a adivinar
	bool partida_terminada = false;
	bool se_aserto;
	bool ganado = false;

	do {
		se_aserto = false;

		// Imprime el dibujo del ahorcado, el puntaje, la categoria, la palabra que se esta adivinando
		imprimir_ahorcado();

		// Limpia cualquier caracter que se alla colocado en el buffer del teclado
		limpiar_buffer();
		printf("\n\n Digite una letra: "); scanf(" %c", &letra);
		letra = toupper(letra);

		// Revisando si la letra se encuentra en la palabra a adivinar
		se_aserto = hay_acierto(letra);

		if (se_aserto) {
			// Si hubo hacierto se completa la palabra y se revisa si ya no hay mas letras a adivinar
			completar_frase(letra);
			ganado = se_gano();
		}
		else {
			// No hubo acierto, por lo que se le resta puntos y se le quita intentos
			DATOS_JUEGO.intentos++;
			DATOS_JUEGO.puntos -= 200;
		}

		// Si se acabaron los intentos, la partida termina
		if (DATOS_JUEGO.intentos == MAX_INTENTOS) {
			imprimir_msg_perdiste();

			partida_terminada = true;
		}

		// Si se gano la partida termina
		if (ganado) {
			imprimir_msg_ganaste();

			partida_terminada = true;
		}

	} while (!partida_terminada);
	printf("\n\n");
}

bool se_gano(void) {
	bool falta_adivinar_letra = false;

	for (int i = 0; i < DATOS_JUEGO.longitud && !falta_adivinar_letra; i++) {
		if (DATOS_JUEGO.frase[i] == '_') falta_adivinar_letra = true;
	}

	return !falta_adivinar_letra;
}

bool hay_acierto(char letra) {
	bool encontrado = false;

	// Revisa si la letra se encuentra en la palabra a adivinar
	if (strchr(DATOS_JUEGO.palabra_a_adivinar, letra) != NULL) {
		encontrado = true;
	}

	return encontrado;
}

void completar_frase(char letra) {

	// Busca el indice en el cual la letra se encuentra en la palabra a adivinar para completar la frase
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