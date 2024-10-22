#include <stdio.h>
#include <string.h>
#include "funciones.h"


void leerProducto(char prod[10][50], float prec[10], int num, int i) {
    printf("Ingrese el producto %d: \n", num);
    fgets(prod[i], 50, stdin);  
    
   
    for (int j = 0; j < 50; j++) {
        if (prod[i][j] == '\n') {
            prod[i][j] = '\0';  
            break;
        }
    }
    
    do {
        printf("Ingrese el precio del producto %d (no puede ser negativo): \n", num);
        scanf("%f", &prec[i]);
        if (prec[i] < 0) {
            printf("El precio no puede ser negativo. Intente de nuevo.\n");
        }
    } while (prec[i] < 0);

    while (getchar() != '\n');  
}

void imprimirProducto(char prod[10][50], float prec[10], int num, int i) {
    printf("Producto %d: %s\n", num, prod[i]);
    printf("Precio: %.2f\n", prec[i]);
}


void buscarProducto(char prod[10][50], float prec[10], char buscar[50], int i) {
    int encontrado = 0;
 for (int i = 0; i < 10; i++) {
        if (strcmp(prod[i], buscar) == 0) {
            printf("El precio de %s es: %.2f\n", buscar, prec[i]);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado\n");
    }
}



float totalPrecio(float prec[10], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += prec[i];
    }
    return total;
}


void productoCaroBarato(char prod[10][50], float prec[10], int n) {
    int caro = 0, barato = 0;
    for (int i = 1; i < n; i++) {
        if (prec[i] > prec[caro]) caro = i;
        if (prec[i] < prec[barato]) barato = i;
    }
    printf("Mas caro: %s (%.2f)\n", prod[caro], prec[caro]);
    printf("Mas barato: %s (%.2f)\n", prod[barato], prec[barato]);
}


float promedioPrecio(float prec[10], int n) {
    float suma = 0;
    for (int i = 0; i < n; i++) {
        suma += prec[i];
    }
    return suma / n;
}