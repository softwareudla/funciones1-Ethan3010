#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main() {
    char prod[10][50];  
    float prec[10];      
    int n;               
    char buscar[50];   
    char opcion[3];      

    
    do {
        printf("Cuantos productos desea ingresar (maximo 10): ");
        scanf("%d", &n);
        if (n <= 0 || n > 10) {
            printf("Numero de productos invalido. Debe ser entre 1 y 10.\n");
        }
    } while (n <= 0 || n > 10);

    
    while (getchar() != '\n');

   
    for (int i = 0; i < n; i++) {
        leerProducto(prod, prec, i+1, i);
    }

    
    for (int i = 0; i < n; i++) {
        imprimirProducto(prod, prec, i+1, i);
    }

    
    while (getchar() != '\n');

    do {
      
        printf("Producto a buscar: ");
        scanf("%s", buscar);  
        buscarProducto(prod, prec, buscar, n);

        
        do {
            printf("Desea buscar otro producto (si/no): ");
            scanf("%s", opcion);  
            if (strcmp(opcion, "si") != 0 && strcmp(opcion, "no") != 0) {
                printf("Opción no valida. Intente de nuevo.\n");
            }
        } while (strcmp(opcion, "si") != 0 && strcmp(opcion, "no") != 0);

    } while (strcmp(opcion, "si") == 0);

   
    printf("Total: %.2f\n", totalPrecio(prec, n));
    productoCaroBarato(prod, prec, n);
    printf("Promedio: %.2f\n", promedioPrecio(prec, n));

    return 0;
}