# Informe: Trabajo Práctico #5 - Devices Drivers

**Asignatura:** Sistemas de Computación  
**Institución:** Facultad de Ciencias Exactas, Físicas y Naturales (FCEFyN) – UNC  
**Docente:** Javier Alejandro Jorge  



## Datos del Grupo y Repositorio

* **Integrantes:** 
  - Macarena Vanina González 
  - Marcos Nieto 
  - Mario Pampiglione
* **Repositorio:** [https://github.com/Maca040/SistComp_TeamMergeNoConflict.git](https://github.com/Maca040/SistComp_TeamMergeNoConflict.git)


## 1. Objetivo del Trabajo Práctico
El objetivo principal de este trabajo práctico es desarrollar un controlador de dispositivos de caracteres (CDD) para Linux, diseñado para interactuar con puertos GPIO y leer dos señales externas tomando una muestra por segundo. Debido a desperfectos técnicos con el hardware físico durante la etapa de desarrollo, la ejecución y validación del driver se realiza sobre una máquina virtual emulada mediante QEMU (utilizando la herramienta qemu-rpi-gpio), la cual simula perfectamente la arquitectura y los pines de una Raspberry Pi.

A pesar de utilizar un entorno emulado,se aplica cross-compilation (compilación cruzada). En lugar de programar y compilar todo dentro de la máquina virtual, configuramos nuestro entorno para escribir y compilar el código fuente en nuestra PC anfitriona (arquitectura x86_64). Una vez generado el módulo del kernel, lo transferimos a la máquina virtual emulada (arquitectura ARM) mediante SSH para su ejecución.

Finalmente, para la visualización de los datos, decidimos descartar el uso de aplicaciones de escritorio pesadas para no consumir recursos innecesarios en el entorno emulado. En su lugar, implementamos una aplicación web ligera usando Python y Flask. Esta interfaz nos permite enviarle comandos al driver para elegir qué señal simular y ver cómo se grafica en tiempo real directamente desde el navegador de nuestra computadora anfitriona.