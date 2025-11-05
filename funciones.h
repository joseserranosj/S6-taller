#ifndef FUNCIONES_H
#define FUNCIONES_H

int ingreso_datos(char nombres[][50], float precios[], int cantidad_inicial);
float calcular_total(float precios[], int cantidad);
void producto_caro_barato(char nombres[][50], float precios[], int cantidad);
float promedio_precios(float precios[], int cantidad);
int buscar_producto(char nombres[][50], float precios[], int cantidad, char buscado[]);

#endif



