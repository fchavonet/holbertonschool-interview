<img height="50px" align="right" src="https://raw.githubusercontent.com/fchavonet/fchavonet/main/assets/images/logo-holberton_school.png" alt="Holberton School logo">

# 2048 (Single Line)

## 🔖 Table of contents

<details>
        <summary>
        CLICK TO ENLARGE 😇
        </summary>
        📄 <a href="#description">Description</a>
        <br>
        🎓 <a href="#objectives">Objectives</a>
        <br>
        📋 <a href="#requirements">Requirements</a>
        <br>
        📝 <a href="#instructions">Instructions</a>
        <br>
        🔨 <a href="#tech-stack">Tech stack</a>
        <br>
        📂 <a href="#files-description">Files description</a>
        <br>
        💻 <a href="#installation_and_how_to_use">Installation and how to use</a>
        <br>
        ♥️ <a href="#thanks">Thanks</a>
        <br>
        👷 <a href="#authors">Authors</a>
</details>

## 📄 <span id="description">Description</span>

This project involves implementing the mechanics of the popular [2048 game](https://play2048.co), but on a single horizontal line. The goal is to be able to slide and merge an array of integers either to the left or to the right, following the rules of 2048 where identical numbers, if they are contiguous or separated by zeros, are merged.

The function to implement will take an array of integers and slide it either left or right, depending on the given direction, and merge matching numbers.

For example:
<br>
Input: `2 2 0 0`
<br>
Slide Left: `4 0 0 0`

## 🎓 <span id="objectives">Objectives</span>

At the end of this project, I had to be able to explain to anyone, **without the help of Google** :

- The mechanics of the 2048 game in terms of array manipulation.
- How to implement array operations without using dynamic memory allocation.
- The concept of sliding and merging elements in a given direction.
- Write modular, clean, and efficient C code.

## 📋 <span id="requirements">Requirements</span>

- My programs and functions will be compiled with `gcc` using the flags `-Wall`, `-Werror`, `-Wextra` and `-pedantic`.
- All my files should end with a new line.
- My code should use the Betty style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/main/betty-style.pl) and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/main/betty-doc.pl).
- I am not allowed to use global variables.
- No more than 5 functions per file.
- The prototypes of all my functions should be included in my header file called `sandpiles.h`.
- Don’t forget to push my header file...
- All my header files should be include guarded.

## 📝 <span id="instructions">Instructions</span>

<details>
    <summary>
        <b>0. Slide line</b>
    </summary>
    <br>

The goal of this task is to reproduce the [2048 game](https://play2048.co)(NSFW !!) mechanics on a single horizontal line.

Given an array of integers, we want to be able to slide & merge it to the left or to the right. Identical numbers, if they are contiguous or separated by zeros, should be merged (see example).

- Write a function that slides and merges an array of integers.
- Prototype: `int slide_line(int *line, size_t size, int direction);`.
- Where `line` points to an array of integers containing size elements, that must be slided & merged to the direction represented by `direction`. `direction` can be either:
    - `SLIDE_LEFT`.
    - `SLIDE_RIGHT`.
    - If it is something else, the function must fail.
    - Both macros `SLIDE_LEFT` and `SLIDE_RIGHT` must be defined in `slide_line.h`.
- Your function must return `1` upon success, or `0` upon failure.
- You are **not allowed** to allocate memory dynamically (malloc, calloc, …).

```
alex@~/slide_line$ cat 0-main.c 
#include <stdlib.h>
#include <stdio.h>

#include "slide_line.h"

#define LINE_SIZE   32

/**
 * print_array - Prints out an array of integer, followed by a new line
 * 
 * @array: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 */
static void print_array(int const *array, size_t size)
{
    size_t i;

    printf("Line: ");
    for (i = 0; i < size; i++)
        printf("%s%d", i > 0 ? ", " : "", array[i]);
    printf("\n");
}

/**
 * main - Entry point
 *
 * @ac: Arguments counter
 * @av: Arguments vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int ac, char **av)
{
    int line[LINE_SIZE];
    int direction;
    size_t i, size;

    if (ac < 3)
    {
        fprintf(stderr, "Usage: %s <R/L> <n1> [n2...]\n", av[0]);
        return (EXIT_FAILURE);
    }

    /* Command line arguments to array of int */
    size = ac - 2;
    if (size > LINE_SIZE)
        size = LINE_SIZE;
    for (i = 0; i < size; i++)
        line[i] = atoi(av[i + 2]);

    /* Print the array */
    print_array(line, size);

    /* Parse direction */
    switch (*(av[1]))
    {
    case 'L':
        direction = SLIDE_LEFT;
        printf("Slide to the left\n");
        break;
    case 'R':
        direction = SLIDE_RIGHT;
        printf("Slide to the right\n");
        break;
    default:
        fprintf(stderr, "Unknown direction '%c'. Please use 'L' or 'R'", *(av[1]));
        return (EXIT_FAILURE);
    }

    /* Slide and merge */
    if (!slide_line(line, size, direction))
    {
        fprintf(stderr, "Failed to slide and merge line\n");
        return (EXIT_FAILURE);
    }

    /* Print the array */
    print_array(line, size);

    return (EXIT_SUCCESS);
}
alex@~/slide_line$ gcc -Wall -Wextra -Werror -pedantic -o 0-slide_line 0-main.c 0-slide_line.c
alex@~/slide_line$ ./0-slide_line L 2 2 0 0
Line: 2, 2, 0, 0
Slide to the left
Line: 4, 0, 0, 0
alex@~/slide_line$ ./0-slide_line L 2 2 0 0 0 0 0 2 0 0 0 2 0 4
Line: 2, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 4
Slide to the left
Line: 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
alex@~/slide_line$ ./0-slide_line R 2 2 2 2
Line: 2, 2, 2, 2
Slide to the right
Line: 0, 0, 4, 4
alex@~/slide_line$ ./0-slide_line R 2 2 2 2 2
Line: 2, 2, 2, 2, 2
Slide to the right
Line: 0, 0, 2, 4, 4
alex@~/slide_line$ ./0-slide_line L 2 4 8 16
Line: 2, 4, 8, 16
Slide to the left
Line: 2, 4, 8, 16
alex@~/slide_line$ ./0-slide_line R 2 4 8 16
Line: 2, 4, 8, 16
Slide to the right
Line: 2, 4, 8, 16
alex@~/slide_line$ ./0-slide_line R 4 4 8 16
Line: 4, 4, 8, 16
Slide to the right
Line: 0, 8, 8, 16
alex@~/slide_line$
```

#
**Repo:**
- GitHub repository: `holbertonschool-interview`.
- Directory: `slide_line`.
- File: `0-slide_line.c`, `slide_line.h`.
<hr>
</details>

## 🔨 <span id="tech-stack">Tech stack</span>

<p align="left">
    <img src="https://img.shields.io/badge/C-a8b9cc?logo=&logoColor=black&style=for-the-badge" alt="C badge">
</p>

## 📂 <span id="files-description">File description</span>

| **FILE**         | **DESCRIPTION**                                       |
| :--------------: | ----------------------------------------------------- |
| `0-main.c`       | Sample `main` program to test `slide_line` functions. | 
| `0-slide_libe.c` |  Implementation oif the `slide_line` function.        |
| `README.md`      | The readme file you are currently reading 😉.         |
| `slide_line.h`   | Header file with function prototypes.                 |

## 💻 <span id="installation_and_how_to_use">Installation and how to use</span>

**Installation:**

1. Clone this repository:
    - Open your preferred Terminal.
    - Navigate to the directory where you want to clone the repository.
    - Run the following command:

```
git clone https://github.com/fchavonet/holbertonschool-interview.git
```

2. Open the repository you've just cloned.

3. Navigate to the `slide_line` directory:

```
cd slide_line
```

4. Compile the program using gcc:

```
gcc -Wall -Wextra -Werror -pedantic -o 0-slide_line 0-main.c 0-slide_line.c
```

**How to use:**

1. Once compiled, run the program with one of the following commands (or try your own examples):

```
./0-slide_line L 2 2 0 0
```

```
./0-slide_line R 2 2 2 2
```

```
./0-slide_line L 2 2 0 0 0 0 0 2 0 0 0 2 0 4
```

## ♥️ <span id="thanks">Thanks</span>

A big thank you to all my Holberton School peers for their help and support throughout these projects.

## 👷 <span id="authors">Authors</span>

**Fabien CHAVONET**
- Github: [@fchavonet](https://github.com/fchavonet)
