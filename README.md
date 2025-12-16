*This project has been created as part of the 42 curriculum by thasampa.*

# Description

This project implements the `get_next_line` function, which reads a file descriptor (FD) line by line. It returns one line at a time, without reading the entire file into memory. The function efficiently handles multiple calls, allowing for reading from a file, standard input, or even multiple file descriptors simultaneously.

The goal of the project is to implement a function that reads a file one line at a time, managing memory efficiently, while using static variables and handling edge cases like end-of-file (EOF) and multiple file descriptors.

# Instructions

### Compilation

To compile the project, make sure you have a C compiler (e.g., GCC) installed. Run the following command in your terminal:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c -o get_next_line
```
You will also need a `main.c` file to test this function. Below is a simple example:
```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("file", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```
## Resources

- `man 2 read` — Official Linux manual page for the `read()` system call  
- `man 2 open` — Documentation for opening and handling file descriptors  
- 42 project subject and internal documentation  
- C language reference documentation  

### AI Usage

AI tools were used to:
- clarify the behavior of the `read()` system call and file descriptors
- reason about edge cases and memory management
- review the algorithm design and project requirements

All implementation decisions and the final code were written, tested, and validated by the author.
