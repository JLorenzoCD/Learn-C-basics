# include <stdio.h>

int suma(int x, int y);
int resta(int x, int y);
int multiplicacion(int x, int y);
int divicion_entera(int x, int y);

void realizar_operacion(int x, int y, int(*operacion)(int, int));

int main(void) {
    realizar_operacion(15, 20, &suma);
    realizar_operacion(15, 20, &resta);
    realizar_operacion(15, 3, &divicion_entera);

    return 0;
}

int suma(int x, int y) { return x + y; }

int resta(int x, int y) { return x - y; }

int multiplicacion(int x, int y) { return x * y; }

int divicion_entera(int x, int y) { return x / y; }

void realizar_operacion(int x, int y, int(*operacion)(int, int)) {
    puts("Estoy a punto de realizar una operacion con los siguientes enteros: ");
    printf("x = %d\n", x);
    printf("y = %d\n", y);

    int res = operacion(x, y);

    printf("\nEl resultado de la operacion es: %d\n", res);
}