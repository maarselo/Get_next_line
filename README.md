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
````
## 🎁 Parte Bonus: Mejorando `get_next_line()` para Múltiples Descriptores de Archivo

En esta parte bonus del proyecto, la tarea es **mejorar la función `get_next_line()`** para que sea capaz de manejar **múltiples descriptores de archivo** a la vez, utilizando una sola variable estática. A continuación, te explico cómo lo resolví utilizando un array de punteros y una solución optimizada.

### **Solución Propuesta: Array de Punteros Estáticos**

En lugar de recurrir a estructuras complejas o almacenar estados de cada descriptor de archivo en múltiples variables estáticas, opté por una solución simple: utilicé un **array estático de punteros** para gestionar el estado de cada descriptor de archivo (fd).

#### **Explicación de la Solución:**

1. **`static char *buffer[1024];`**:
   - El array `buffer` tiene un tamaño de 1024 elementos, donde cada elemento es un puntero que apunta a un buffer de lectura para un **descriptor de archivo** específico.
   - **¿Por qué 1024?** Este valor es arbitrario y puede modificarse según las necesidades del proyecto. Se elige un valor lo suficientemente grande para manejar múltiples descriptores de archivo, que es el máximo de descriptores comunes en sistemas Unix.

2. **Almacenamiento de la información de cada `fd`:**
   - Cada vez que se llama a `get_next_line()` para un `fd` particular, se asigna un buffer específico para ese `fd` en el array `buffer`.
   - Esto permite leer de múltiples archivos de manera simultánea sin interferir entre ellos.

#### **Código del Bonus (Implementación):**

```c
char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read(fd, &buffer[fd]);
	if (!buffer[fd] || !*buffer[fd])
	{
		free(buffer[fd]);
		return (NULL);
	}
	line = ft_getline(buffer[fd]);
	if (!line)
		free(buffer[fd]);
	ft_nextline(&buffer[fd]);
	return (line);
}

