import requests
import ctypes

# --- 1. Consumo de la API REST ---
url = "https://api.worldbank.org/v2/en/country/all/indicator/SI.POV.GINI?format=json&date=2011:2020&per_page=32500&page=1"
respuesta = requests.get(url)
datos = respuesta.json()

gini_argentina = 0.0
anio = ""

# Buscamos ESPECÍFICAMENTE a Argentina y que no tenga valor nulo
for registro in datos[1]:
    if registro['country']['value'] == 'Argentina' and registro['value'] is not None:
        gini_argentina = float(registro['value'])
        anio = registro['date']
        break # Apenas encuentra el más reciente válido de Argentina, frena.

print(f"Dato de la API -> GINI Argentina ({anio}): {gini_argentina}")

# --- 2. Llamada a la librería C ---
# Cargamos la librería que compilamos previamente usando ruta relativa (debe estar en el mismo directorio que este script)
libcalculadora = ctypes.CDLL('./libcalculadora.so')

# Le avisamos a Python que la función de C recibe un float (c_float) y devuelve un int
libcalculadora.procesar_gini.argtypes = (ctypes.c_float,)
libcalculadora.procesar_gini.restype = ctypes.c_int

# Ejecutamos la función de C y guardamos el resultado
resultado = libcalculadora.procesar_gini(gini_argentina)

print(f"Resultado final devuelto por C (convertido + 1): {resultado}")