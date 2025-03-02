Get Next Line
Get Next Line es un proyecto en C que tiene como objetivo la creación de una función capaz de leer una línea de un descriptor de archivo y devolverla.
El desafío principal de este proyecto es gestionar la lectura de manera eficiente utilizando un buffer de tamaño configurable
y manejar correctamente los descriptores de archivo, asegurando que no se pierdan datos entre las llamadas. 
El uso de variables estáticas es esencial para lograr el funcionamiento correcto de la función,
además de evitar comportamientos indefinidos en situaciones como archivos binarios o cambios en el descriptor de archivo.

📌 Objetivos
El principal objetivo de este proyecto es crear una función llamada get_next_line, 
que será responsable de leer una línea de un descriptor de archivo (fd) y devolverla. 
Este proyecto te permitirá entender el concepto de las variables estáticas en C y
cómo manejarlas correctamente para implementar una solución eficiente en términos de memoria y rendimiento.
Además, el proyecto profundiza en la manipulación de buffers y la lectura de archivos a nivel bajo.

📂 Archivos y Estructura
bash
Copiar
Editar
get_next_line/
├── get_next_line.c        # Implementación principal de la función
├── get_next_line_utils.c  # Funciones auxiliares para el procesamiento
├── get_next_line.h        # Declaraciones de funciones
├── Makefile               # Archivo de compilación
└── README.md              # Documentación del proyecto
🛠️ Instalación y Uso
Para compilar el proyecto, puedes usar el siguiente comando:

sh
Copiar
Editar
make
Esto generará el archivo objeto necesario para usar la función get_next_line. Asegúrate de incluir el archivo de cabecera en tu código:

c
Copiar
Editar
#include "get_next_line.h"
Comandos de Makefile
make: Compila el proyecto.
make clean: Elimina los archivos objeto temporales.
make fclean: Elimina los archivos objeto y el ejecutable.
make re: Realiza una compilación limpia y recompila el proyecto.

📖 Funcionalidad
get_next_line
Prototipo:

c
Copiar
Editar
char *get_next_line(int fd);
Parámetros:

fd: El descriptor de archivo desde el cual se leerá la línea.
Valor devuelto:

La línea leída del archivo, incluyendo el salto de línea al final, o NULL si ocurre un error o se ha alcanzado el final del archivo.
La función leerá el archivo en bloques y devolverá una línea cada vez que se llame.
Si se alcanza el final del archivo o si ocurre un error durante la lectura, devolverá NULL.

Comportamiento esperado:
La función debe ser capaz de manejar entradas desde diferentes tipos de archivos (incluso stdin).
La línea leída debe terminar con un salto de línea, excepto si se ha llegado al final del archivo.
Se debe evitar la lectura redundante del archivo completo; la función solo leerá lo necesario para obtener una línea.
🚀 Reglas y Normas
El proyecto debe cumplir con la Norma 42.
No se pueden utilizar variables globales ni la biblioteca libft.
Se debe gestionar adecuadamente la memoria asignada en el heap y evitar leaks.
No se deben utilizar funciones como lseek para navegar por el archivo.
🧩 Bonus
Una vez completada la parte obligatoria, puedes intentar agregar los siguientes bonus:

Uso de una sola variable estática para gestionar el estado de la función y mejorar la eficiencia.
Manejo de múltiples descriptores de archivo al mismo tiempo, lo que permite leer de varios archivos de manera independiente.
Los archivos correspondientes a la parte bonus deberán estar separados con el sufijo _bonus y deben seguir las mismas reglas de la parte obligatoria.

📜 Licencia
Este proyecto sigue los lineamientos de 42 y es parte de su currículo. El código está bajo licencia abierta y puede ser utilizado para fines educativos o como base para otros proyectos dentro del entorno de 42.
