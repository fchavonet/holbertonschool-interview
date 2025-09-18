<img height="50" align="right" src="https://raw.githubusercontent.com/fchavonet/fchavonet/refs/heads/main/assets/images/logo-holberton_school.webp" alt="Holberton School logo">

# Radix Sort

## Table of contents

<details>
    <summary>
        CLICK TO ENLARGE 😇
    </summary>
    <a href="#description">Description</a>
    <br>
    <a href="#objectives">Objectives</a>
    <br>
    <a href="#requirements">Requirements</a>
    <br>
    <a href="#instructions">Instructions</a>
    <br>
    <a href="#tech-stack">Tech stack</a>
    <br>
    <a href="#files-description">Files description</a>
    <br>
    <a href="#installation_and_how_to_use">Installation and how to use</a>
    <br>
    <a href="#thanks">Thanks</a>
    <br>
    <a href="#authors">Authors</a>
</details>

## <span id="description">Description</span>

This project consists of implementing the Radix Sort algorithm in C to sort an array of non-negative integers in ascending order using the LSD (Least Significant Digit) approach.

Radix Sort is a non-comparative sorting algorithm that sorts numbers digit by digit, starting from the least significant digit and moving to the most significant digit. This method is particularly efficient for sorting integers with a fixed range of digits.

## <span id="objectives">Objectives</span>

At the end of this project, I should be able to explain to anyone, **without the help of Google**:

- How the LSD Radix Sort algorithm works.
- How to sort numbers by each digit starting from the least significant.
- How to use counting sort as a subroutine for each digit.
- How to print the array at each significant digit step for debugging.

## <span id="requirements">Requirements</span>

- My programs and functions will be compiled with `gcc` using the flags `-Wall`, `-Werror`, `-Wextra` and `-pedantic`.
- All my files should end with a new line.
- My code should use the Betty style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/main/betty-style.pl) and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/main/betty-doc.pl).
- I am not allowed to use global variables.
- No more than 5 functions per file.
- The prototypes of all my functions should be included in my header file called `sort.h`.
- Don’t forget to push my header file...
- All my header files should be include guarded.

## <span id="instructions">Instructions</span>

### Mandatory

<details>
    <summary>
        <b> Radix sort</b>
    </summary>
    <br>

Write a function that sorts an array of integers in ascending order using the [Radix sort](https://en.wikipedia.org/wiki/Radix_sort) algorithm:

- Prototype: `void radix_sort(int *array, size_t size);`.
- You must implement the `LSD` radix sort algorithm.
- You can assume that `array` will contain only numbers `>= 0`.
- You are allowed to use `malloc` and `free` for this task.
- You’re expected to print the `array` each time you increase your `significant digit` (see example below).

```bash
alexa@ubuntu-xenial:radix_sort$ cat 0-main.c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    radix_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
alexa@ubuntu-xenial:radix_sort$ gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-radix_sort.c print_array.c -o radix
alexa@ubuntu-xenial:radix_sort$ ./radix
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

71, 52, 13, 73, 96, 86, 7, 48, 19, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
alexa@ubuntu-xenial:radix_sort$
```

#
**Repo:**
- GitHub repository: `holbertonschool-interview`.
- Directory: `radix_sort`.
- File: `0-radix_sort.c`.
<hr>
</details>

## <span id="tech-stack">Tech stack</span>

<p align="left">
    <img src="https://img.shields.io/badge/C-a8b9cc?logo=&logoColor=black&style=for-the-badge" alt="C badge">
    <img src="https://img.shields.io/badge/GIT-f05032?logo=git&logoColor=white&style=for-the-badge" alt="Git badge">
    <img src="https://img.shields.io/badge/GITHUB-181717?logo=github&logoColor=white&style=for-the-badge" alt="GitHub badge">
    <img src="https://img.shields.io/badge/MARKDOWN-000000?logo=markdown&logoColor=white&style=for-the-badge" alt="Markdown badge">
    <img src="https://img.shields.io/badge/VIM-019733?logo=vim&logoColor=white&style=for-the-badge" alt="VIM badge">
</p>

## <span id="files-description">Files description</span>

| **FILES**        | **DESCRIPTION**                                      |
| :--------------: | ---------------------------------------------------- |
| `sort.h`         | Header file containing prototypes for all functions. |
| `0-radix_sort.c` | Implementation of the Radix Sort algorithm.          |
| `print_array.c`  | Helper function to print an array of integers.       |
| `0-main.c`       | Example main file for testing Radix Sort.            |
| `README.md`      | The README file you are currently reading 😉.        |

## <span id="installation_and_how_to_use">Installation and how to use</span>

### Installation:

1. Clone this repository:
    - Open your preferred Terminal.
    - Navigate to the directory where you want to clone the repository.
    - Run the following command:

```bash
git clone https://github.com/fchavonet/holbertonschool-interview.git
```

2. Open the repository you've just cloned.

3. Navigate to the `radix_sort` directory:

```bash
cd radix_sort
```

4. Compile the program using `gcc`:

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-radix_sort.c print_array.c -o radix
```

### How to use:

1. Run the binary:

```bash
./radix
```

> The program prints the original array, the array at each significant digit step, and the final sorted array.

## <span id="thanks">Thanks</span>

- A big thank you to all my Holberton School peers for their help and support throughout this project.

## <span id="authors">Authors</span>

**Fabien CHAVONET**
- GitHub: [@fchavonet](https://github.com/fchavonet)
