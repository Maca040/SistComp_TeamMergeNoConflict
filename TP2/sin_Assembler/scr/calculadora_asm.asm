global procesar_gini_asm

section .text

procesar_gini_asm:
    ; --- Armado del Stack Frame --- 
    push rbp            ; se guarda el Base Pointer de la función que nos llamó (C)
    mov rbp, rsp        ; el stack pointer actual se convierte en el nuevo base pointer para esta función

    ; --- LÓGICA DE LA CALCULADORA ---
    ; El float 'gini_value' está en xmm0.
    cvttss2si eax, xmm0 ; se convierte el float en xmm0 a un entero en eax, truncando hacia cero.
    inc eax ; se suma 1 al resultado entero.

    ; --- Desarmado del Stack Frame ---
    mov rsp, rbp        ; se restaura el Stack Pointer al valor del Base Pointer, limpiando el stack frame de esta función
    pop rbp             ; se restaura el Base Pointer de la función que nos llamó (C)
    ret                 ; se retorna al código que llamó a esta función (C), con el resultado en eax

    ; Para evitar warnings de seguridad relacionados con el stack, se incluye la siguiente sección:
    section .note.GNU-stack noalloc noexec nowrite progbits ; indica que esta sección no es ejecutable ni escribible, solo para el stack y es requerida por el formato ELF para asegurar la seguridad del programa. 