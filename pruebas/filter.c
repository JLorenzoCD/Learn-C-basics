# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <time.h>

void imprimir_arreglo(size_t len, int a[]);
size_t obtener_len(int *arr);

int *filteri(size_t len, int *arr, bool(*fun_filter)(int), size_t *len_filtrados);

bool mayores_diez(int x);
bool es_par(int x);

int numero_aleatorio(int hasta);
void rellenar_arr(size_t len, int arr[]);

# define N 5
int main(void) {
    int arr[N];

    rellenar_arr(N, arr);
    imprimir_arreglo(N, arr);

    size_t len_arr_filtrado = 0;
    int *arr_filtrado = filteri(N, arr, &es_par, &len_arr_filtrado);

    imprimir_arreglo(len_arr_filtrado, arr_filtrado);

    free(arr_filtrado);

    return 0;
}

int numero_aleatorio(int hasta) {
    int x = rand() % hasta;

    if (hasta <= 0) {
        return rand() % 10;
    }

    return x;
}

void rellenar_arr(size_t len, int arr[]) {
    srand(time(NULL));

    for (size_t i = 0; i < len; i++) {
        arr[i] = numero_aleatorio(20);
    }

}

void imprimir_arreglo(size_t len, int a[]) {
    printf("\n");
    printf("arr = [");
    for (size_t i = 0; i < len; i++) {
        printf("%d", a[i]);

        if (i + 1 < len) {
            printf(", ");
        }
    }
    printf("]\n\n");
}

int *filteri(size_t len, int *arr, bool(*fun_filter)(int), size_t *len_filtrados) {
    if (len == 0) {
        return NULL;
    }

    int *arr_filtrado = (int*)malloc(len * sizeof(int));

    if (arr_filtrado == NULL) {
        puts("Error al asignar un espacio de memoria para el array filtrado");
        exit(-1);
    }

    size_t elementos_filtrados = 0;

    for (size_t i = 0; i < len; i++) {
        if (fun_filter(arr[i])) {
            arr_filtrado[elementos_filtrados] = arr[i];

            elementos_filtrados++;
        }
    }

    int *temp = (int*)realloc(arr_filtrado, (elementos_filtrados) * sizeof(int));

    if (temp == NULL) {
        free(arr_filtrado);
        puts("Error al asignar un espacio de memoria para el array filtrado");
        exit(-1);
    }

    arr_filtrado = temp;
    *len_filtrados = elementos_filtrados;

    return arr_filtrado;
}

bool es_par(int x) {
    return x % 2 == 0;
}

bool mayores_diez(int x) {
    return 10 < x;
}