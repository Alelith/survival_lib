# 🚀 Survival Library

![Status](https://img.shields.io/badge/status-In%20development-blue)
![Language](https://img.shields.io/badge/language-C-orange)
![Standard](https://img.shields.io/badge/standard-C99-yellow)
![License](https://img.shields.io/badge/license-MIT-green)
![Last update](https://img.shields.io/github/last-commit/Alelith/survival_lib)

---

## 🧠 Description

**Survival Library** is a comprehensive utility library written in standard C (C99), designed to provide essential programming tools for system development and general-purpose applications. This library serves as a robust foundation for building C programs with reliable string manipulation, memory management, data conversion, and character validation capabilities. Implemented without external dependencies beyond the standard library, it offers portability, clarity, and efficiency on Unix-like systems.

---

## 🧩 Table of Contents

- [Description](#-description)
- [Features](#-features)
- [Technologies Used](#%EF%B8%8F-technologies-used)
- [Architecture](#%EF%B8%8F-architecture)
- [Project Structure](#-project-structure)
- [Installation](#-installation)
- [Usage](#%EF%B8%8F-usage)
- [Examples](#-examples)
- [Documentation](#-documentation)
- [Learnings and Future Improvements](#-learnings-and-future-improvements)
- [Credits and Acknowledgments](#-credits-and-acknowledgments)
- [License](#-license)
- [Author](#%E2%80%8D-author)

---

## 🌟 Features

### ✅ Implemented Modules

- **Character Validation**: Predicates to verify character types (alphabetic, numeric, printable, whitespace)
- **String Comparison**: Complete and partial comparison functions with varied matching strategies
- **Type Conversion**: Bidirectional conversion between strings and numeric types (integers, floats, arbitrary bases)
- **Case Transformation**: Uppercase and lowercase conversion
- **Memory Management**: Memory allocation, copy, comparison, search, and initialization operations
- **String Manipulation**: Complete suite of operations (concatenation, copy, split, search, trim, extraction)
- **Formatted Printing**: Custom printf-like function with variable format specifiers
- **Line-by-Line File Reading**: get_next_line utility with support for multiple concurrent file descriptors

### 🔄 In Progress

- Expansion of format specifiers for `print_format`
- Comprehensive unit tests for all modules
- Performance optimization in memory operations

### 🚧 Future Features

- Support for multibyte string operations
- Advanced error handling with standardized return codes
- Date/time parsing and formatting functions
- File path manipulation utilities

---

## ⚙️ Technologies Used

| Category | Technology | Version |
|----------|------------|---------|
| **Language** | C | C99 |
| **Compiler** | GCC | Compatible with `-Wall -Wextra -Werror` flags |
| **Build System** | Make | GNU Make |
| **Documentation** | Doxygen | 1.9.1+ |
| **Documentation Style** | Doxygen Awesome CSS | - |
| **Version Control** | Git | - |
| **Standards** | POSIX | For I/O operations |

---

## 🏗️ Architecture

The library is organized into independent modular components, each focused on a specific functionality domain. All modules are implemented as independent units with minimal dependencies, ensuring flexibility and ease of integration.

### Main Modules

```
survival_lib
│
├── Check Functions       → Character validation and string comparison
├── Conversion Functions  → Type conversion and case transformation
├── Memory Functions      → Low-level memory management and manipulation
├── String Functions      → High-level string processing and manipulation
├── Print Functions       → Custom formatted output
└── Get Next Line         → Line-by-line file reading
```

**Design Principles:**
- **Modularity**: Each module can be used independently
- **No External Dependencies**: Only uses the C standard library
- **Portability**: Compatible with Unix-like systems
- **Clarity**: Clean and well-documented code
- **Efficiency**: Performance-optimized implementations

---

## 📂 Project Structure

```
survival_lib/
├── Doxyfile                      # Doxygen configuration for documentation generation
├── LICENSE                       # MIT License of the project
├── Makefile                      # Automated build system
├── README.md                     # This file
├── include/
│   └── survival_lib.h            # Main header with all declarations
└── src/
    ├── check/                    # Character validation module
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
    ├── conversion/               # Type conversion module
    │   ├── bnum_to_str.c        # Conversion to arbitrary bases
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
    ├── memory/                   # Memory management module
    │   ├── callocation.c
    │   ├── mem_compare.c
    │   ├── mem_copy.c
    │   ├── mem_len.c
    │   ├── mem_move.c
    │   ├── mem_search.c
    │   ├── mem_set.c
    │   ├── reallocation.c
    │   └── set_zero.c
    ├── printf/                   # Formatted printing module
    │   ├── print_format.c
    │   └── internal/
    │       ├── printf_internal.h
    │       ├── print_nbr.c
    │       └── print_str.c
    └── string/                   # String manipulation module
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

## 📦 Installation

### 🔧 Prerequisites

- **Operating System**: Linux, macOS, or any Unix-like system
- **Compiler**: GCC (or compatible with strict compilation flags)
- **Make**: GNU Make to automate the build
- **Doxygen** (optional): To generate code documentation

### 💾 Steps

1. **Clone the repository**

```bash
git clone https://github.com/Alelith/survival_lib.git
cd survival_lib
```

2. **Compile the library**

```bash
make
```

This will generate the static file `survivalib.a` in the root directory.

3. **Clean object files (optional)**

```bash
make clean    # Remove .o files
make fclean   # Remove all generated files including the library
make re       # Recompile from scratch (fclean + make)
```

4. **Generate documentation (optional)**

```bash
make docs
```

The HTML documentation will be generated in the `html/` directory.

---

## ▶️ Usage

### Using in Your Projects

1. **Include the header in your source code:**

```c
#include "survival_lib.h"
```

2. **Compile your program linking with the library:**

```bash
gcc -o my_program my_program.c -I./include -L. -lsurvival
```

Where:
- `-I./include`: Specifies the header path
- `-L.`: Indicates that the library is in the current directory
- `-lsurvival`: Links with `survivalib.a` (the 'lib' prefix and extension are omitted)

3. **Alternative example with full path:**

```bash
gcc -o my_program my_program.c /path/to/survival_lib/include/survival_lib.h /path/to/survival_lib/survivalib.a
```

---

## 🧪 Examples

### Example 1: Character Validation

```c
#include "survival_lib.h"
#include <stdio.h>

int main(void)
{
    char c = 'A';
    
    if (is_alphabetic(c))
        printf("%c is alphabetic\n", c);
    
    if (is_digit('5'))
        printf("5 is a digit\n");
    
    if (is_from_set('x', "xyz"))
        printf("x is in the set xyz\n");
    
    return 0;
}
```

### Example 2: Type Conversion

```c
#include "survival_lib.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // String to integer
    int num = str_to_int("42");
    printf("Number: %d\n", num);
    
    // Integer to string
    char *str = int_to_str(-123);
    printf("String: %s\n", str);
    free(str);
    
    // Number to hexadecimal
    char *hex = bnum_to_str(255, 16, 1);
    printf("Hex: %s\n", hex);  // FF
    free(hex);
    
    // Float with precision
    char *flt = float_to_str(3.14159, 2);
    printf("Float: %s\n", flt);  // 3.14
    free(flt);
    
    return 0;
}
```

### Example 3: String Manipulation

```c
#include "survival_lib.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Duplicate string
    char *dup = str_duplicate("Hello World");
    printf("Duplicated: %s\n", dup);
    
    // Join strings
    char *joined = str_join("Hello ", "World");
    printf("Joined: %s\n", joined);
    
    // Split string
    char **parts = str_split("one,two,three", ',');
    for (int i = 0; parts[i]; i++)
    {
        printf("Part %d: %s\n", i, parts[i]);
        free(parts[i]);
    }
    free(parts);
    
    // Trim spaces
    char *trimmed = str_trim("   text   ", " ");
    printf("Trimmed: '%s'\n", trimmed);
    
    // Substring
    char *sub = str_substring("University", 3, 5);
    printf("Substring: %s\n", sub);  // versi
    
    free(dup);
    free(joined);
    free(trimmed);
    free(sub);
    
    return 0;
}
```

### Example 4: Memory Management

```c
#include "survival_lib.h"
#include <stdio.h>

int main(void)
{
    // Callocation (custom calloc)
    int *arr = callocation(5, sizeof(int));
    
    // Initialize with mem_set
    mem_set(arr, 0, 5 * sizeof(int));
    
    // Copy memory
    int src[] = {1, 2, 3, 4, 5};
    mem_copy(arr, src, 5 * sizeof(int));
    
    // Compare memory
    if (mem_compare(arr, src, 5 * sizeof(int)) == 0)
        printf("Identical memory\n");
    
    // Search in memory
    int *found = mem_search(arr, 3, 5 * sizeof(int));
    if (found)
        printf("Found: %d\n", *found);
    
    free(arr);
    return 0;
}
```

### Example 5: Get Next Line

```c
#include "survival_lib.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    if (fd < 0)
        return 1;
    
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line: %s", line);
        free(line);
    }
    
    close(fd);
    return 0;
}
```

### Example 6: Print Format

```c
#include "survival_lib.h"

int main(void)
{
    print_format("Hello %s!\n", "World");
    print_format("Number: %d\n", 42);
    print_format("Character: %c\n", 'A');
    print_format("Hex: %x\n", 255);
    
    return 0;
}
```

---

## 📖 Documentation

Complete code documentation is generated with Doxygen. You can consult it at:

🔗 **[Code Documentation](https://alelith.github.io/survival_lib-documentation/)**

To generate documentation locally:
```bash
make docs
```

The documentation includes:
- **Detailed description** of all functions and macros
- **Relationship diagrams** between modules
- **Usage examples** of internal APIs
- **Modular architecture guide**
- **Technical specifications** of each function
- **Warnings and notes** about special behavior

### 🎨 Style

The documentation uses **Doxygen Awesome CSS** for a modern and clear presentation.

---

## 🧭 Learnings and Future Improvements

### 📘 Learnings During Development

- **Memory Management in C**: Deep dive into dynamic allocation, pointers, and memory leak prevention
- **Effective Modularization**: Design of independent components with clear interfaces
- **Comprehensive Documentation**: Advanced use of Doxygen to create professional and accessible documentation
- **Coding Standards**: Implementation of clean code following strict C99 conventions
- **Edge Case Handling**: Robust input validation and boundary case management
- **Optimization**: Balance between code clarity and execution efficiency

### 🚀 Planned Future Improvements

- **Complete Testing**: Implement unit test suite with frameworks like Criterion or Unity
- **Benchmarking**: Performance comparison with standard libc functions
- **Error Handling**: Standardized error code system with errno
- **Additional Functions**: 
  - Regular expression operations
  - Hash functions (MD5, SHA)
  - Data structures (lists, stacks, queues, trees)
- **Improved Portability**: Explicit Windows support through abstractions
- **Dynamic Version**: Compilation as shared library (.so / .dll)
- **CI/CD Integration**: Automated tests and documentation generation

---

## 🤝 Credits and Acknowledgments

This library was developed as an educational and personal practice project, inspired by:

- **42 School**: Learning methodology based on practical projects
- **GNU C Library (glibc)**: Reference for standard C function implementations
- **Doxygen Awesome CSS**: For the modern documentation theme ([Doxygen Awesome](https://jothepro.github.io/doxygen-awesome-css/))
- **Open Source Community**: For the open source philosophy and knowledge sharing

---

## 📜 License

This project is licensed under the **MIT License**.
See the [LICENSE](LICENSE) file for more details.

---

## 👩‍💻 Author

**Lilith Estévez Boeta**

Backend & Multiplatform Developer  
📍 Málaga, Spain  
🔗 [GitHub](https://github.com/Alelith) · [LinkedIn](https://www.linkedin.com/in/alelith/)

---

<p align="center">
  <b>⭐ If you find this project useful, consider giving it a star on GitHub! ⭐</b>
</p>
