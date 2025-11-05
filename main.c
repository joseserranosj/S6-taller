#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main()
{
    int opc = 0;
    int validar;
    char nombres[10][50];
    float precios[10];
    int cantidad = 0;

    do
    {
        printf("\n===MENU===\n");
        printf("1. Ingresar datos de productos\n");
        printf("2. Precio total del inventario\n");
        printf("3. Buscar el producto mas caro y el mas barato\n");
        printf("4. Precio promedio de todos los productos\n");
        printf("5. Buscar un producto\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        validar = scanf("%d", &opc);
        if (validar != 1 || opc < 1 || opc > 6)
        {
            printf("Entrada invalida.\n");
            while (getchar() != '\n')
                ;
            opc = -1;
            continue;
        }
        while (getchar() != '\n')
            ;

        switch (opc)
        {
        case 1:
        {
            if (cantidad >= 10)
            {
                printf("\nSe alcanzó el número máximo de 10 productos.\n");
            }
            else
            {
                int nuevos = ingreso_datos(nombres, precios, cantidad, 10); 

                cantidad += nuevos;
            }
            break;
        }

        case 2:
            if (cantidad == 0)
                printf("Primero debe ingresar productos.\n");
            else
                printf("Precio total del inventario: $%.2f\n", calcular_total(precios, cantidad));
            break;
        case 3:
            producto_caro_barato(nombres, precios, cantidad);
            break;
        case 4:
            promedio_precios(precios, cantidad);
            break;
        case 5:
            if (cantidad == 0)
                printf("Primero debe ingresar productos.\n");
            else
            {
                char buscado[50];
                printf("Ingrese el nombre del producto a buscar: ");
                fgets(buscado, 50, stdin);
                buscado[strcspn(buscado, "\n")] = '\0';
                buscar_producto(nombres, precios, cantidad, buscado);
            }
            break;

        case 6:
            printf("Gracias por utilizar el programa\n");
            break;
        }
    } while (opc != 6);

    return 0;
}
