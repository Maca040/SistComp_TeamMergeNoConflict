# Informe: Trabajo Práctico #2 - Arquitectura de Capas (Iteración 1)

**Asignatura:** Sistemas de Computación  
**Institución:** Facultad de Ciencias Exactas, Físicas y Naturales (FCEFyN) – UNC  
**Docente:** Javier Alejandro Jorge  

---

## Datos del Grupo y Repositorio

* **Integrantes:** 
  - Macarena Vanina González 
  - Marcos Nieto 
  - Mario Pampiglione
* **Repositorio:** [https://github.com/Maca040/SistComp_TeamMergeNoConflict.git](https://github.com/Maca040/SistComp_TeamMergeNoConflict.git)

---

## 1. Introducción y Arquitectura
Este trabajo práctico aborda el diseño de una aplicación distribuida en capas para procesar datos socioeconómicos reales. En esta primera instancia (Iteración 1), el foco está puesto en la interoperabilidad entre un lenguaje de alto nivel (Python) y un lenguaje de nivel intermedio (C).

La arquitectura de esta iteración se compone de:
* **Capa Superior (Python):** Gestiona la obtención de datos desde la web.
* **Capa Intermedia (C):** Recibe los datos y realiza las conversiones y operaciones aritméticas requeridas.

## 2. Implementación Técnica: Iteración 1

Para esta etapa, se implementó una solución por consola que recupera el índice GINI de Argentina desde la API REST del Banco Mundial y lo procesa mediante una librería dinámica compilada en C.

### 2.1 Descripción de los Archivos del Proyecto
La lógica del programa se encuentra dividida en los siguientes archivos, cuyos códigos fuente pueden ser consultados en detalle dentro del repositorio adjunto:

* **`main.py`**: Es el script principal de la capa superior. Se encarga de utilizar la librería `requests` para consultar el endpoint del Banco Mundial. Extrae el valor más reciente y válido del índice GINI exclusivamente para Argentina. Luego, mediante la librería `ctypes`, carga la biblioteca dinámica y le transfiere el valor obtenido (en formato de punto flotante) para su procesamiento, imprimiendo finalmente el resultado devuelto.
* **`calculadora.c`**: Contiene el código fuente de la capa intermedia. Define la función que actúa como puente, la cual recibe el valor flotante transferido por Python, realiza el casteo (truncamiento) a un número entero y le suma una unidad matemática (+1), tal como especifica la consigna de la cátedra.
* **`libcalculadora.so`**: Es el archivo objeto compartido (librería dinámica) generado tras compilar `calculadora.c`. Este archivo es el que el entorno de Python vincula y ejecuta en tiempo de ejecución.

### 2.2 Validación de Funcionamiento y Resultados

Para demostrar la correcta comunicación y el pasaje de parámetros entre la capa de Python y la capa en C, se adjunta la salida por consola tras la ejecución del script principal:

![aplicación](./images/aplicacion.jpeg)

## 3. Conclusiones Provisorias
Se validó satisfactoriamente la integración entre Python y C. La utilización de `ctypes` permitió transferir parámetros de tipo punto flotante desde una capa de alto nivel hacia una librería nativa de forma transparente y eficiente. Esta estructura modular deja el terreno preparado para la siguiente iteración, donde la lógica de la capa intermedia delegará la carga de procesamiento a rutinas en lenguaje ensamblador para poner en práctica la manipulación del Stack Frame a nivel de hardware.

---
## Bibliografía
* Guía rápida para uso del debugger GDB - Departamento de Computación FCEFyN.
* Enunciado TP#2: Calculadora de índices GINI - Javier Jorge.