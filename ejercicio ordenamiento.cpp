#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int arreglo[], int izquierda, int derecha) {
    if (izquierda < derecha) {
        int i = izquierda, j = derecha;
        int pivote = arreglo[(izquierda + derecha) / 2];

        while (i <= j) {
            while (arreglo[i] < pivote)
                i++;
            while (arreglo[j] > pivote)
                j--;
            if (i <= j) {
                int temp = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = temp;
                i++;
                j--;
            }
        }

        quicksort(arreglo, izquierda, j);
        quicksort(arreglo, i, derecha);
    }
}

int main() {
    srand(time(NULL));
    int n = rand() % 30 + 1;
    int arreglo[n];

    for (int i = 0; i < n; i++) {
        arreglo[i] = rand() % 31; 
    }

    printf("Cantidad de elementos generados: %d\n", n);

    printf("Arreglo generado (sin ordenar):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    quicksort(arreglo, 0, n - 1);

    printf("Arreglo ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    int maximo = arreglo[n - 1];
    int minimo = arreglo[0];
    printf("El valor maximo es: %d\n", maximo);
    printf("El valor minimo es: %d\n", minimo);

    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += arreglo[i];
    }
    float media = (float)suma / n;
    printf("La media es: %.2f\n", media);

    float mediana;
    if (n % 2 == 0) {
        mediana = (arreglo[n / 2 - 1] + arreglo[n / 2]) / 2.0;
    } else {
        mediana = arreglo[n / 2];
    }
    printf("La mediana es: %.2f\n", mediana);

    int moda = arreglo[0];
    int contador = 1;
    int maxContador = 1;

    for (int i = 1; i < n; i++) {
        if (arreglo[i] == arreglo[i - 1]) {
            contador++;
        } else {
            contador = 1;
        }

        if (contador > maxContador) {
            maxContador = contador;
            moda = arreglo[i];
        }
    }

    printf("La moda es: %d\n", moda);

  
    printf("Histograma:\n");
    int numero_total_de_datos = n;
    for (int i = 0; i <= 30; i++) {
        int frecuencia = 0;
        for (int j = 0; j < n; j++) {
            if (arreglo[j] == i) {
                frecuencia++;
            }
        }
        float probabilidad = 100.0 * (float)frecuencia / numero_total_de_datos; // Normalizar utilizando la función
        int asteriscos = (int)(probabilidad / 2); // Escalar para ajustar a 40 asteriscos
        printf("%2d: ", i);
        for (int k = 0; k < asteriscos; k++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

