<img  height="50px" align="right" src="https://raw.githubusercontent.com/fchavonet/fchavonet/main/resources/images/logo-holberton_school.png" alt="Holberton School logo">

# Sandpiles

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

This project simulates the behavior of sandpiles, which is a mathematical model from dynamical systems and physics. It uses a grid where each cell holds a number of grains of sand. If a cell holds 4 or more grains, it "topples," distributing its grains to neighboring cells, which can cause a chain reaction.

To understand the concept more visually, you can watch this [YouTube video](https://www.youtube.com/watch?v=1MtEUErz7Gg) explaining sandpiles.

The project is implemented in C, and involves adding two 3x3 sandpiles and stabilizing the result through a series of toppling events.

## 🎓 <span id="objectives">Objectives</span>

At the end of this project, I had to be able to explain to anyone, **without the help of Google** :

- Understand and implement the [Abelian Sandpile Model](https://en.wikipedia.org/wiki/Abelian_sandpile_model).
- Work with 2D arrays in C and perform operations on them.
- Implement an iterative stabilization process for sandpiles.
- Write modular, clean, and efficient C code.
- Display intermediate steps and the final result of the stabilization process.

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
        <b>0. Sandpiles sum</b>
    </summary>
    <br>

Write a function that computes the sum of two sandpiles.

- Prototype: `void sandpiles_sum(int grid1[3][3], int grid2[3][3]);`.
- I can assume that both `grid1` and `grid2` are individually **stable**.
- A sandpile is considered **stable** when none of its cells contains more than 3 grains.
- When my function is done, `grid1` must be stable.
- `grid1` must be printed before each toppling round, only if it is unstable (see example).
- I am not allowed to allocate memory dynamically.

```
alex@~/sandpiles$ cat 0-main.c 
#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

/**
 * print_grid_sum - Print 3x3 grids sum
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 */
static void print_grid_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid1[i][j]);
        }

        printf(" %c ", (i == 1 ? '+' : ' '));

        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid2[i][j]);
        }
        printf("\n");
    }
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    int grid1[3][3] = {
        {3, 3, 3},
        {3, 3, 3},
        {3, 3, 3}
    };
    int grid2[3][3] = {
        {1, 3, 1},
        {3, 3, 3},
        {1, 3, 1}
    };

    print_grid_sum(grid1, grid2);

    sandpiles_sum(grid1, grid2);

    printf("=\n");
    print_grid(grid1);

    return (EXIT_SUCCESS);
}
alex@~/sandpiles$ gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-sandpiles.c -o 0-sandpiles
alex@~/sandpiles$ ./0-sandpiles 
3 3 3   1 3 1
3 3 3 + 3 3 3
3 3 3   1 3 1
=
4 6 4
6 6 6
4 6 4
=
2 5 2
5 6 5
2 5 2
=
4 2 4
2 6 2
4 2 4
=
0 5 0
5 2 5
0 5 0
=
2 1 2
1 6 1
2 1 2
=
2 2 2
2 2 2
2 2 2
alex@~/sandpiles$ cat 1-main.c
Same as 0-main.c except:
int grid1[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    int grid2[3][3] = {
        {3, 3, 3},
        {3, 3, 3},
        {3, 3, 3}
    };
alex@~/sandpiles$ gcc -Wall -Wextra -Werror -pedantic 1-main.c 0-sandpiles.c -o 0-sandpiles
alex@~/sandpiles$ ./0-sandpiles 
0 0 0   3 3 3
0 0 0 + 3 3 3
0 0 0   3 3 3
=
3 3 3
3 3 3
3 3 3
alex@~/sandpiles$
```

#
**Repo:**
- GitHub repository: `holbertonschool-interview`.
- Directory: `sandpiles`.
- File: `0-sandpiles.c`.
<hr>
</details>

## 🔨 <span id="tech-stack">Tech stack</span>

<p align="left">
    <img src="https://img.shields.io/badge/C-a8b9cc?logo=&logoColor=black&style=for-the-badge" alt="C badge">
</p>
 
## 📂 <span id="files-description">File description</span>

| **FILE**        | **DESCRIPTION**                                   |
| :-------------: | ------------------------------------------------- |
| `0-main.c`      | Sample `main` program to test sandpile functions. | 
| `0-sandpiles.c` | Implementation of sandpile operations in C.       |
| `README.md`     | The readme file you are currently reading 😉.     |
| `sandpiles.h`   | Header file with function prototypes.             |

## 💻 <span id="installation_and_how_to_use">Installation and how to use</span>

**Installation:**

1. Clone this repository:
    - Open your preferred Terminal.
    - Navigate to the directory where you want to clone the repository.
    - Run the following command:

```
git clone https://github.com/fchavonet/holbertonschool-interview.git
```

2. Open the repository you've just cloned and go in the `sandpiles` folder.

3. Compile the program using gcc:

```
gcc -Wall -Wextra -Werror -pedantic 1-main.c 0-sandpiles.c -o 0-sandpiles
```

**How to use:**

1. Once compiled, run the program with:

```
./sandpiles
```

2. Modify the `main.c` file if you want to test the program with different initial sandpiles.

3. The program will print intermediate states whenever the sandpile is unstable, as well as the final stabilized configuration.

## ♥️ <span id="thanks">Thanks</span>

A big thank you to all my Holberton School peers for their help and support throughout these projects.

## 👷 <span id="authors">Authors</span>

**Fabien CHAVONET**
- Github: [@fchavonet](https://github.com/fchavonet)
