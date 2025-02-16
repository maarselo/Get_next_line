# Proyecto: **get_next_line** - 42 Barcelona

Bienvenido al proyecto **get_next_line** de 42 Barcelona. En este desafío, deberás implementar una función que lea una línea de un archivo utilizando su descriptor de archivo (fd) y la devuelva. Este proyecto te ayudará a comprender el uso de buffers, la gestión de archivos y la manipulación de memoria en C.

## 🚀 Objetivo

El objetivo de este proyecto es implementar la función `get_next_line()` que lee una línea de un descriptor de archivo (fd) y la devuelve como una cadena de caracteres. La lectura se realiza línea a línea, hasta que se alcanza el final del archivo o se produce un error.

### Requisitos

- La función debe devolver una línea leída del archivo o `NULL` si se ha llegado al final o ha ocurrido un error.
- La línea devuelta debe terminar con un salto de línea (`\n`), excepto si se ha llegado al final del archivo.
- Debes manejar correctamente tanto archivos normales como `stdin`.

## 🛠️ Requisitos Técnicos

### Archivos a Entregar

1. **`get_next_line.c`**: Implementación principal de la función `get_next_line`.
2. **`get_next_line_utils.c`**: Funciones de ayuda necesarias para el funcionamiento de `get_next_line`.
3. **`get_next_line.h`**: Contendrá el prototipo de la función `get_next_line` y otras definiciones necesarias.

### Funciones Permitidas

- **`read`**, **`malloc`**, **`free`**

### Comportamiento de la Función

La función debe ser capaz de:

- Leer una línea de un descriptor de archivo (fd).
- Si no hay más datos que leer, debe devolver `NULL`.
- Debe gestionar correctamente la lectura de archivos y la entrada estándar (`stdin`).
- La línea leída debe terminar con el carácter `\n`, excepto si se ha llegado al final del archivo sin un salto de línea.

### Definición de la Función

```c
char *get_next_line(int fd);
```

## 🛠️ Compilación del Proyecto

Para compilar tu proyecto **get_next_line**, debes usar el siguiente comando en la terminal:

```bash
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o get_next_line

