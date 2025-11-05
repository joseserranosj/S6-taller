#include <stdio.h>
#include <string.h>
#include "funciones.h"

int ingreso_datos(char nombres[][50], float precios[], int cantidad_inicial)
{
    int cont = cantidad_inicial;
    int opc1 = 0;
    do
    {
        printf("Ingrese el nombre del producto %d: ", cont);
        fgets(nombres[cont], 50, stdin);
        nombres[cont][strcspn(nombres[cont], "\n")] = '\0';

        float precioTemp;
        int valido;
        do
        {
            printf("Ingrese el precio del producto %d: ", cont);
            valido = scanf("%f", &precioTemp);
            while (getchar() != '\n');
            if (valido != 1 || precioTemp <= 0)
            {
                printf("Precio inválido. Intente nuevamente.\n");
            }
        } while (valido != 1 || precioTemp <= 0);

        precios[cont] = precioTemp;
        cont++;

        do
        {
            printf("Desea ingresar otro producto? (1.Si / 2.No): ");
            if (scanf("%d", &opc1) != 1)
            {
                printf("Entrada inválida.\n");
                opc1 = 0;
            }
            while (getchar() != '\n');
        } while (opc1 != 1 && opc1 != 2);

    } while (opc1 == 1 && cont < 10);

    return cont - cantidad_inicial;
}

float calcular_total(float precios[], int cantidad)
{
    float total = 0;
    for (int i = 0; i < cantidad; i++)
        total += precios[i];
    return total;
}

void producto_caro_barato(char nombres[][50], float precios[], int cantidad)
{
    if (cantidad == 0)
    {
        printf("No hay productos ingresados.\n");
        return;
    }

    int max = 0, min = 0;
    for (int i = 1; i < cantidad; i++)
    {
        if (precios[i] > precios[max]) max = i;
        if (precios[i] < precios[min]) min = i;
    }

    printf("\nMás caro: %s - $%.2f\n", nombres[max], precios[max]);
    printf("Más barato: %s - $%.2f\n", nombres[min], precios[min]);
}

float promedio_precios(float precios[], int cantidad)
{
    if (cantidad == 0)
    {
        printf("No hay productos ingresados.\n");
        return 0;
    }

    float promedio = calcular_total(precios, cantidad) / cantidad;
    printf("Precio promedio: $%.2f\n", promedio);
    return promedio;
}

int buscar_producto(char nombres[][50], float precios[], int cantidad, char buscado[])
{
    for (int i = 0; i < cantidad; i++)
        if (strcmp(nombres[i], buscado) == 0)
        {
            printf("Encontrado: %s - $%.2f\n", nombres[i], precios[i]);
            return i;
        }

    printf("Producto no encontrado.\n");
    return -1;
}

