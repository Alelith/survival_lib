# 🚀 Survival Library

![Estado](https://img.shields.io/badge/estado-En%20desarrollo-blue)
![Lenguaje](https://img.shields.io/badge/lenguaje-C-orange)
![Standard](https://img.shields.io/badge/standard-C99-yellow)
![Licencia](https://img.shields.io/badge/licencia-MIT-green)
![Última actualización](https://img.shields.io/github/last-commit/Alelith/survival_lib)

---

## 🧠 Descripción

**Survival Library** es una biblioteca integral de utilidades escritas en C estándar (C99), diseñada para proporcionar herramientas esenciales de programación para el desarrollo de sistemas y aplicaciones de propósito general. Esta biblioteca sirve como base robusta para construir programas en C con capacidades confiables de manipulación de cadenas, gestión de memoria, conversión de datos y validación de caracteres. Implementada sin dependencias externas más allá de la biblioteca estándar, ofrece portabilidad, claridad y eficiencia en sistemas Unix-like.

---

## 🧩 Tabla de contenidos

- [Descripción](#-descripción)
- [Características](#-características)
- [Tecnologías utilizadas](#%EF%B8%8F-tecnologías-utilizadas)
- [Arquitectura](#%EF%B8%8F-arquitectura)
- [Estructura del proyecto](#-estructura-del-proyecto)
- [Instalación](#-instalación)
- [Ejecución](#%EF%B8%8F-ejecución)
- [Uso o ejemplos](#-uso-o-ejemplos)
- [Documentación](#-documentación)
- [Aprendizajes y mejoras futuras](#-aprendizajes-y-mejoras-futuras)
- [Créditos y agradecimientos](#-créditos-y-agradecimientos)
- [Licencia](#-licencia)
- [Autora](#%E2%80%8D-autora)

---

## 🌟 Características

### ✅ Módulos implementados

- **Validación de caracteres**: Predicados para verificar tipos de caracteres (alfabéticos, numéricos, imprimibles, espacios en blanco)
- **Comparación de cadenas**: Funciones de comparación completa y parcial con estrategias de coincidencia variadas
- **Conversión de tipos**: Conversión bidireccional entre cadenas y tipos numéricos (enteros, flotantes, bases arbitrarias)
- **Transformación de caso**: Conversión a mayúsculas y minúsculas
- **Gestión de memoria**: Operaciones de asignación, copia, comparación, búsqueda e inicialización de memoria
- **Manipulación de cadenas**: Suite completa de operaciones (concatenación, copia, división, búsqueda, recorte, extracción)
- **Impresión formateada**: Función personalizada similar a printf con especificadores de formato variables
- **Lectura de archivos línea por línea**: Utilidad get_next_line con soporte para múltiples descriptores de archivo concurrentes

### 🔄 En progreso

- Expansión de especificadores de formato para `print_format`
- Pruebas unitarias exhaustivas para todos los módulos
- Optimización de rendimiento en operaciones de memoria

### 🚧 Características futuras

- Soporte para operaciones con cadenas multibyte
- Gestión avanzada de errores con códigos de retorno estandarizados
- Funciones de análisis y formateo de fechas/tiempo
- Utilidades de manipulación de rutas de archivo

---

## ⚙️ Tecnologías utilizadas

| Categoría | Tecnología | Versión |
|-----------|------------|---------|
| **Lenguaje** | C | C99 |
| **Compilador** | GCC | Compatible con flags `-Wall -Wextra -Werror` |
| **Sistema de construcción** | Make | GNU Make |
| **Documentación** | Doxygen | 1.9.1+ |
| **Estilo de documentación** | Doxygen Awesome CSS | - |
| **Control de versiones** | Git | - |
| **Estándares** | POSIX | Para operaciones de E/S |

---

## 🏗️ Arquitectura

La biblioteca está organizada en componentes modulares independientes, cada uno enfocado en un dominio específico de funcionalidad. Todos los módulos son implementados como unidades independientes con dependencias mínimas, asegurando flexibilidad y facilidad de integración.

### Módulos principales

```
survival_lib
│
├── Check Functions       → Validación de caracteres y comparación de cadenas
├── Conversion Functions  → Conversión de tipos y transformación de caso
├── Memory Functions      → Gestión y manipulación de memoria de bajo nivel
├── String Functions      → Procesamiento y manipulación de cadenas de alto nivel
├── Print Functions       → Salida formateada personalizada
└── Get Next Line         → Lectura de archivos línea por línea
```

**Principios de diseño:**
- **Modularidad**: Cada módulo puede usarse independientemente
- **Sin dependencias externas**: Solo utiliza la biblioteca estándar de C
- **Portabilidad**: Compatible con sistemas Unix-like
- **Claridad**: Código limpio y bien documentado
- **Eficiencia**: Implementaciones optimizadas para rendimiento

---

## 📂 Estructura del proyecto

```
survival_lib/
├── Doxyfile                      # Configuración de Doxygen para generar documentación
├── LICENSE                       # Licencia MIT del proyecto
├── Makefile                      # Sistema de construcción automatizado
├── README.md                     # Este archivo
├── include/
│   └── survival_lib.h            # Header principal con todas las declaraciones
└── src/
    ├── check/                    # Módulo de validación de caracteres
    │   ├── is_alphabetic.c
    │   ├── is_alphanumeric.c
    │   ├── is_ascii.c
    │   ├── is_digit.c
    │   ├── is_from_set.c
    │   ├── is_print.c
    │   ├── is_space.c
    │   ├── str_compare_all.c
    │   ├── str_compare_n.c
    │   └── str_contains.c
    ├── conversion/               # Módulo de conversión de tipos
    │   ├── bnum_to_str.c        # Conversión a bases arbitrarias
    │   ├── float_to_str.c
    │   ├── int_to_str.c
    │   ├── str_to_float.c
    │   ├── str_to_int.c
    │   ├── str_to_uint.c
    │   ├── to_lower.c
    │   ├── to_upper.c
    │   └── uint_to_str.c
    ├── gnl/                      # Get Next Line
    │   └── get_next_line.c
    ├── memory/                   # Módulo de gestión de memoria
    │   ├── callocation.c
    │   ├── mem_compare.c
    │   ├── mem_copy.c
    │   ├── mem_len.c
    │   ├── mem_move.c
    │   ├── mem_search.c
    │   ├── mem_set.c
    │   ├── reallocation.c
    │   └── set_zero.c
    ├── printf/                   # Módulo de impresión formateada
    │   ├── print_format.c
    │   └── internal/
    │       ├── printf_internal.h
    │       ├── print_nbr.c
    │       └── print_str.c
    └── string/                   # Módulo de manipulación de cadenas
        ├── str_concat.c
        ├── str_copy.c
        ├── str_duplicate.c
        ├── str_join.c
        ├── str_len.c
        ├── str_search_char.c
        ├── str_search_rev_char.c
        ├── str_search_str.c
        ├── str_split.c
        ├── str_substring.c
        └── str_trim.c
```

---

## 📦 Instalación

### 🔧 Requisitos previos

- **Sistema operativo**: Linux, macOS o cualquier sistema Unix-like
- **Compilador**: GCC (o compatible con flags estrictos de compilación)
- **Make**: GNU Make para automatizar la construcción
- **Doxygen** (opcional): Para generar la documentación del código

### 💾 Pasos

1. **Clonar el repositorio**

```bash
git clone https://github.com/Alelith/survival_lib.git
cd survival_lib
```

2. **Compilar la biblioteca**

```bash
make
```

Esto generará el archivo estático `survivalib.a` en el directorio raíz.

3. **Limpiar archivos objeto (opcional)**

```bash
make clean    # Elimina archivos .o
make fclean   # Elimina todos los archivos generados incluyendo la biblioteca
make re       # Recompila desde cero (fclean + make)
```

4. **Generar documentación (opcional)**

```bash
make docs
```

La documentación HTML se generará en el directorio `html/`.

---

## ▶️ Ejecución

### Uso en tus proyectos

1. **Incluir el header en tu código fuente:**

```c
#include "survival_lib.h"
```

2. **Compilar tu programa enlazando con la biblioteca:**

```bash
gcc -o mi_programa mi_programa.c -I./include -L. -lsurvival
```

Donde:
- `-I./include`: Indica la ruta del header
- `-L.`: Indica que la biblioteca está en el directorio actual
- `-lsurvival`: Enlaza con `survivalib.a` (se omite el prefijo 'lib' y la extensión)

3. **Ejemplo alternativo con ruta completa:**

```bash
gcc -o mi_programa mi_programa.c /ruta/a/survival_lib/include/survival_lib.h /ruta/a/survival_lib/survivalib.a
```

---

## 🧪 Uso o ejemplos

### Ejemplo 1: Validación de caracteres

```c
#include "survival_lib.h"
#include <stdio.h>

int main(void)
{
    char c = 'A';
    
    if (is_alphabetic(c))
        printf("%c es alfabético\n", c);
    
    if (is_digit('5'))
        printf("5 es un dígito\n");
    
    if (is_from_set('x', "xyz"))
        printf("x está en el conjunto xyz\n");
    
    return 0;
}
```

### Ejemplo 2: Conversión de tipos

```c
#include "survival_lib.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // String a entero
    int num = str_to_int("42");
    printf("Número: %d\n", num);
    
    // Entero a string
    char *str = int_to_str(-123);
    printf("String: %s\n", str);
    free(str);
    
    // Número a hexadecimal
    char *hex = bnum_to_str(255, 16, 1);
    printf("Hex: %s\n", hex);  // FF
    free(hex);
    
    // Float con precisión
    char *flt = float_to_str(3.14159, 2);
    printf("Float: %s\n", flt);  // 3.14
    free(flt);
    
    return 0;
}
```

### Ejemplo 3: Manipulación de cadenas

```c
#include "survival_lib.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Duplicar string
    char *dup = str_duplicate("Hola Mundo");
    printf("Duplicado: %s\n", dup);
    
    // Unir strings
    char *joined = str_join("Hola ", "Mundo");
    printf("Unido: %s\n", joined);
    
    // Dividir string
    char **parts = str_split("uno,dos,tres", ',');
    for (int i = 0; parts[i]; i++)
    {
        printf("Parte %d: %s\n", i, parts[i]);
        free(parts[i]);
    }
    free(parts);
    
    // Trim espacios
    char *trimmed = str_trim("   texto   ", " ");
    printf("Trimmed: '%s'\n", trimmed);
    
    // Substring
    char *sub = str_substring("Universidad", 3, 5);
    printf("Substring: %s\n", sub);  // versi
    
    free(dup);
    free(joined);
    free(trimmed);
    free(sub);
    
    return 0;
}
```

### Ejemplo 4: Gestión de memoria

```c
#include "survival_lib.h"
#include <stdio.h>

int main(void)
{
    // Callocation (calloc personalizado)
    int *arr = callocation(5, sizeof(int));
    
    // Inicializar con mem_set
    mem_set(arr, 0, 5 * sizeof(int));
    
    // Copiar memoria
    int src[] = {1, 2, 3, 4, 5};
    mem_copy(arr, src, 5 * sizeof(int));
    
    // Comparar memoria
    if (mem_compare(arr, src, 5 * sizeof(int)) == 0)
        printf("Memoria idéntica\n");
    
    // Buscar en memoria
    int *found = mem_search(arr, 3, 5 * sizeof(int));
    if (found)
        printf("Encontrado: %d\n", *found);
    
    free(arr);
    return 0;
}
```

### Ejemplo 5: Get Next Line

```c
#include "survival_lib.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int fd = open("archivo.txt", O_RDONLY);
    if (fd < 0)
        return 1;
    
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Línea: %s", line);
        free(line);
    }
    
    close(fd);
    return 0;
}
```

### Ejemplo 6: Print Format

```c
#include "survival_lib.h"

int main(void)
{
    print_format("Hola %s!\n", "Mundo");
    print_format("Número: %d\n", 42);
    print_format("Carácter: %c\n", 'A');
    print_format("Hex: %x\n", 255);
    
    return 0;
}
```

---

## 📖 Documentación

La documentación completa del código está generada con Doxygen. Puedes consultarla en:

🔗 **[Documentación del Código](https://alelith.github.io/survival_lib-documentation/)**

Para generar la documentación localmente:
```bash
make docs
```

La documentación incluye:
- **Descripción detallada** de todas las funciones y macros
- **Diagramas de relaciones** entre módulos
- **Ejemplos de uso** de las APIs internas
- **Guía de arquitectura** modular
- **Especificaciones técnicas** de cada función
- **Advertencias y notas** sobre comportamiento especial

### 🎨 Estilo

La documentación utiliza **Doxygen Awesome CSS** para una presentación moderna y clara.

---

## 🧭 Aprendizajes y mejoras futuras

### 📘 Aprendizajes durante el desarrollo

- **Gestión de memoria en C**: Profundización en asignación dinámica, punteros y prevención de fugas de memoria
- **Modularización efectiva**: Diseño de componentes independientes con interfaces claras
- **Documentación exhaustiva**: Uso avanzado de Doxygen para crear documentación profesional y accesible
- **Estándares de codificación**: Implementación de código limpio siguiendo convenciones estrictas de C99
- **Manejo de edge cases**: Validación robusta de entrada y gestión de casos límite
- **Optimización**: Balance entre claridad del código y eficiencia de ejecución

### 🚀 Mejoras futuras planificadas

- **Testing completo**: Implementar suite de pruebas unitarias con framework como Criterion o Unity
- **Benchmarking**: Comparación de rendimiento con funciones estándar de libc
- **Manejo de errores**: Sistema de códigos de error estandarizado con errno
- **Funciones adicionales**: 
  - Operaciones con expresiones regulares
  - Funciones de hash (MD5, SHA)
  - Estructuras de datos (listas, pilas, colas, árboles)
- **Portabilidad mejorada**: Soporte explícito para Windows mediante abstracciones
- **Versión dinámica**: Compilación como biblioteca compartida (.so / .dll)
- **Integración CI/CD**: Automatización de tests y generación de documentación

---

## 🤝 Créditos y agradecimientos

Esta biblioteca fue desarrollada como proyecto educativo y de práctica personal, inspirándose en:

- **42 School**: Metodología de aprendizaje basada en proyectos prácticos
- **GNU C Library (glibc)**: Referencia para implementaciones estándar de funciones C
- **Doxygen Awesome CSS**: Por el tema moderno para la documentación ([Doxygen Awesome](https://jothepro.github.io/doxygen-awesome-css/))
- **Comunidad Open Source**: Por la filosofía de código abierto y compartición de conocimiento

---

## 📜 Licencia

Este proyecto está licenciado bajo la **Licencia MIT**.
Consulta el archivo [LICENSE](LICENSE) para más detalles.

---

## 👩‍💻 Autora

**Lilith Estévez Boeta**

Programadora Backend & Multiplataforma  
📍 Málaga, España  
🔗 [GitHub](https://github.com/Alelith) · [LinkedIn](https://www.linkedin.com/in/alelith/)

---

<p align="center">
  <b>⭐ Si este proyecto te resulta útil, ¡considera darle una estrella en GitHub! ⭐</b>
</p>
