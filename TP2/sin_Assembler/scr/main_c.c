#include <stdio.h>

extern int procesar_gini(float gini_value);

int main() {
    float gini_prueba = 42.8f; // Simulamos un valor que nos devolvería la API
    
    printf("--- Iniciando prueba en C puro para GDB ---\n");
    
    int resultado_final = procesar_gini(gini_prueba);
    
    printf("Resultado final en main_c: %d\n", resultado_final);
    
    return 0;
}