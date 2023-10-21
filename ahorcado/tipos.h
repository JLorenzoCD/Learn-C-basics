#if !defined(_TIPOS_H_)

#define _TIPOS_H_
typedef enum { Fruta, Animal, Pais, Objeto }Categoria;

typedef struct {
	int intentos;
	int puntos;

	Categoria categoria;

	int longitud;
	char *palabra_a_adivinar;
	char *frase;

} JuegoAhorcado;

#endif // _TIPOS_H_
