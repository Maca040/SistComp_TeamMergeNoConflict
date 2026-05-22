// calculadora.c
#include <stdio.h>

extern int procesar_gini_asm(float gini_value);

int procesar_gini(float gini_value) {
    printf("[Capa C] Valor original recibido: %.2f\n", gini_value);

    // Llamamos a la función en ensamblador, pasando el valor de gini_value.
    int resultado = procesar_gini_asm(gini_value);
    
    printf("[Capa C] Valor convertido y sumado por ASM: %d\n", resultado);
    
    return resultado;
}