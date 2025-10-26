# Survival Library

A comprehensive C library providing standard utility functions commonly used in C programming on Linux systems, including character checking, string manipulation, memory management, number conversion, and formatted printing.

## 📋 Table of Contents

- [Overview](#overview)
- [Directory Structure](#directory-structure)
- [Requirements](#requirements)
- [Installation](#installation)
- [Features](#features)
- [API Documentation](#api-documentation)
- [Usage Example](#usage-example)
- [Building](#building)
- [License](#license)
- [Author](#author)

## 🎯 Overview

Survival Library is a collection of lightweight, well-tested C functions designed to simplify common programming tasks. It provides implementations of standard C library functions plus additional utility functions organized into logical categories.

The library is built as a static archive (`survivalib.a`) and can be easily linked into your C projects.

## 📁 Directory Structure

```
survival_lib/
├── Makefile                 # Build configuration
├── Doxyfile                 # Doxygen documentation config
├── README.md                # This file
├── include/
│   └── survival_lib.h       # Main header file
└── src/
    ├── check/               # Character and string checking functions
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
    ├── conversion/          # Data type conversion functions
    │   ├── bnum_to_str.c
    │   ├── float_to_str.c
    │   ├── int_to_str.c
    │   ├── str_to_float.c
    │   ├── str_to_int.c
    │   ├── str_to_uint.c
    │   ├── to_lower.c
    │   ├── to_upper.c
    │   └── uint_to_str.c
    ├── memory/              # Memory management functions
    │   ├── callocation.c
    │   ├── mem_compare.c
    │   ├── mem_copy.c
    │   ├── mem_len.c
    │   ├── mem_move.c
    │   ├── mem_search.c
    │   ├── mem_set.c
    │   ├── reallocation.c
    │   └── set_zero.c
    ├── printf/              # Formatted printing functions
    │   ├── print_format.c
    │   └── internal/
    │       ├── printf_internal.h
    │       ├── print_nbr.c
    │       └── print_str.c
    ├── string/              # String manipulation functions
    │   ├── str_concat.c
    │   ├── str_copy.c
    │   ├── str_duplicate.c
    │   ├── str_join.c
    │   ├── str_len.c
    │   ├── str_search_char.c
    │   ├── str_search_rev_char.c
    │   ├── str_search_str.c
    │   ├── str_split.c
    │   ├── str_substring.c
    │   └── str_trim.c
    └── gnl/                 # Get Next Line (file I/O)
        └── get_next_line.c
```

## 📋 Requirements

### System Requirements
- **OS**: Linux (or Unix-like systems)
- **C Compiler**: GCC or Clang with support for C99 or later
- **Build Tool**: GNU Make

### Development Tools
- `cc` - C compiler (with `-Wall`, `-Wextra`, `-Werror` flags enforced)
- `make` - GNU Make for building the library
- `ar` - Archive tool for creating static libraries
- (Optional) `doxygen` - For generating API documentation

### Installation of Requirements

#### Debian/Ubuntu
```bash
sudo apt-get update
sudo apt-get install build-essential
```

#### RHEL/CentOS/Fedora
```bash
sudo yum groupinstall "Development Tools"
```

#### macOS (if porting)
```bash
brew install gcc make
```

## 🛠️ Installation

### Build the Library

1. **Clone or navigate to the repository**:
```bash
cd /path/to/survival_lib
```

2. **Build the library**:
```bash
make
```

This will:
- Create an `obj/` directory for object files
- Compile all source files with strict warning flags
- Generate the static library `survivalib.a`

### Make Targets

```bash
make              # Build the library (default)
make clean        # Remove object files
make fclean       # Remove object files and library
make re           # Clean and rebuild everything
```

### Output

After building, you'll have:
- `survivalib.a` - Static library file
- `obj/` directory - Compiled object files

## ✨ Features

### Check Functions
Character and string validation functions:
- `is_alphabetic()` - Check if character is alphabetic
- `is_alphanumeric()` - Check if character is alphanumeric
- `is_ascii()` - Check if character is ASCII
- `is_digit()` - Check if character is a digit
- `is_from_set()` - Check if character is in a set
- `is_print()` - Check if character is printable
- `is_space()` - Check if character is whitespace
- `str_compare_all()` - Compare entire strings
- `str_compare_n()` - Compare n characters of strings
- `str_contains()` - Check if string contains characters from a set

### Conversion Functions
Convert between different data types and formats:
- `int_to_str()` - Convert integer to string
- `uint_to_str()` - Convert unsigned integer to string
- `float_to_str()` - Convert float to string with decimal places
- `bnum_to_str()` - Convert number to string in any base
- `str_to_int()` - Parse string to integer
- `str_to_uint()` - Parse string to unsigned integer
- `str_to_float()` - Parse string to float
- `to_upper()` - Convert character to uppercase
- `to_lower()` - Convert character to lowercase

### Memory Functions
Efficient memory management operations:
- `callocation()` - Allocate and initialize memory (like calloc)
- `reallocation()` - Resize allocated memory (like realloc)
- `mem_compare()` - Compare memory blocks
- `mem_copy()` - Copy memory block (like memcpy)
- `mem_move()` - Move memory block (like memmove, safer for overlapping regions)
- `mem_search()` - Search for byte in memory
- `mem_set()` - Set memory block to value (like memset)
- `mem_len()` - Get length of memory block
- `set_zero()` - Zero-initialize memory block

### String Functions
Comprehensive string manipulation:
- `str_concat()` - Concatenate strings safely
- `str_copy()` - Copy string safely
- `str_duplicate()` - Create a dynamic copy of string
- `str_join()` - Join two strings
- `str_len()` - Get string length
- `str_search_char()` - Find character in string
- `str_search_rev_char()` - Find character from end of string
- `str_search_str()` - Search for substring
- `str_split()` - Split string by delimiter
- `str_substring()` - Extract substring
- `str_trim()` - Remove characters from beginning/end

### Formatted Printing
- `print_format()` - Printf-like formatted output

### File I/O
- `get_next_line()` - Read next line from file descriptor

## 📖 API Documentation

For comprehensive API documentation, generate Doxygen documentation:

```bash
doxygen Doxyfile
```

This will generate HTML documentation in the `html/` directory.

Open `html/index.html` in a web browser to view the documentation.

## 💡 Usage Example

### Basic Usage

```c
#include "survival_lib.h"
#include <stdio.h>

int main(void)
{
    // String operations
    char *str = str_join("Hello, ", "World!");
    print_format("Result: %s\n", str);
    
    // Number conversion
    char *num_str = int_to_str(42);
    print_format("Number as string: %s\n", num_str);
    
    // String checking
    if (is_digit('5'))
        print_format("5 is a digit\n");
    
    // String comparison
    if (str_compare_all("test", "test"))
        print_format("Strings match\n");
    
    // Memory allocation
    int *arr = (int *)callocation(10, sizeof(int));
    
    // Free allocated memory
    free(str);
    free(num_str);
    free(arr);
    
    return (0);
}
```

### Compilation and Linking

1. **Compile with the library**:
```bash
gcc -Wall -Wextra -Werror -I survival_lib/include \
    -L survival_lib -o my_program my_program.c -l survivalib
```

2. **Or use in a Makefile**:
```makefile
CFLAGS = -Wall -Wextra -Werror -I survival_lib/include
LDFLAGS = -L survival_lib -l survivalib

my_program: my_program.o
	gcc $(CFLAGS) -o $@ $^ $(LDFLAGS)

my_program.o: my_program.c
	gcc $(CFLAGS) -c $< -o $@
```

## 🔨 Building

### Full Build Workflow

```bash
# Clean previous builds
make fclean

# Build the library
make

# If you want to rebuild everything
make re

# Link with your project
gcc -I include -L . -o my_app main.c -l survivalib
```

### Build Flags

The library is compiled with these strict flags:
- `-Wall` - Enable all standard warnings
- `-Wextra` - Enable extra warnings
- `-Werror` - Treat warnings as errors
- `-g` - Include debugging symbols

This ensures high code quality and compatibility.

## 📝 Notes

- All string functions handle NULL pointers gracefully
- Memory allocation functions use `malloc()` and `free()` internally
- The library is thread-safe for read-only operations
- Functions are designed to be compatible with standard C library equivalents
- Buffer size for certain operations can be configured with `BUFFER_SIZE` macro (default: 256)

## 🔧 Troubleshooting

### Compilation Errors
- Ensure you have a C compiler installed: `gcc --version`
- Check that all dependencies are installed: `make --version`
- Verify the file permissions: `ls -la`

### Linker Errors
- Ensure `survivalib.a` exists in the library directory
- Check include path with `-I` flag points to the header files
- Verify library linking with `-L` and `-l survivalib` flags

### Runtime Issues
- Check for NULL pointer returns from allocation functions
- Ensure adequate system memory for allocation operations
- Use valgrind for memory leak detection: `valgrind ./my_program`

## 📚 Additional Resources

- [C Standard Library Reference](https://en.cppreference.com/w/c)
- [GNU Make Manual](https://www.gnu.org/software/make/manual/)
- [Doxygen Documentation](http://www.doxygen.nl/)

## 📄 License

This project maintains its original structure and licensing. Check the source files for license information.

## 👤 Author

**Lilith Estévez Boeta**

- Developer and maintainer of the Survival Library

---

**Last Updated**: October 26, 2025

For more information or to report issues, please refer to the repository's issue tracker.
