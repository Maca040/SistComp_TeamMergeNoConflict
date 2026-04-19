// calculadora.c
#include <stdio.h>

int procesar_gini(float gini_value) {
    // La consigna pide convertir de float a entero y sumarle 1
    int valor_entero = (int)gini_value;
    int resultado = valor_entero + 1;
    
    // Imprimimos en C para validar que el dato llegó bien desde Python
    printf("[Capa C] Valor original recibido: %.2f\n", gini_value);
    printf("[Capa C] Valor convertido y sumado: %d\n", resultado);
    
    return resultado;
}