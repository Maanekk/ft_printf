*This project has been created as part of the 42 curriculum by mmankows.*

# ft_printf

## Description

This project recreates the mandatory part of the C `printf` function as a static
library named `libftprintf.a`. It supports the conversions `%c`, `%s`, `%p`,
`%d`, `%i`, `%u`, `%x`, `%X`, and `%%` without implementing libc's buffering.

## Instructions

Build the library from the project root:

```sh
make
```

This creates `libftprintf.a`. Include `ft_printf.h` in a program and link the
library, for example:

```sh
cc main.c -L. -lftprintf
```

`make clean`, `make fclean`, and `make re` remove objects, remove all generated
files, and rebuild the project respectively.

## Technical choices

The format string is processed from left to right. Ordinary characters are
written directly, while a conversion dispatches to a small function dedicated
to its argument type. Numbers are emitted recursively by repeatedly dividing
by the target base; the base string supplies the correct lowercase or uppercase
digit. No heap allocation or intermediate output buffer is needed, which keeps
the implementation close to the required system calls and gives constant
auxiliary memory usage apart from recursion depth.

## Resources

- `man 3 printf`
- `man 3 stdarg`
- C standard documentation for variadic arguments and `write(2)`

AI was used to  review edge cases such as `NULL` strings and `INT_MIN`, and prepare documentation.