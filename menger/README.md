<img height="50" align="right" src="https://raw.githubusercontent.com/fchavonet/fchavonet/refs/heads/main/assets/images/logo-holberton_school.webp" alt="Holberton School logo">

# Menger Sponge

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

This project consists of implementing a function `void menger(int level)` that draws a 2D Menger Sponge fractal.  
A Menger Sponge is a fractal curve built recursively:  
- A level 0 sponge is represented by the `#` character.  
- A level N sponge is a 3x3 square of level N-1 sponges, except the center one which is left empty.  
- The size of a level N sponge is `3^N`.  

The program outputs the representation of the sponge directly to the standard output.

## <span id="objectives">Objectives</span>

At the end of this project, I had to be able to explain to anyone, **without the help of Google**:

- What a Menger Sponge is and how it is constructed recursively.  
- How to compute the size of the sponge using powers of 3.  
- How to implement fractal algorithms in C.  
- How to structure clean, modular and Betty-compliant C code.  
- How to compile and link C code using GCC with strict flags. 

## <span id="requirements">Requirements</span>

- My programs and functions will be compiled with `gcc` using the flags `-Wall`, `-Werror`, `-Wextra` and `-pedantic`.
- All my files should end with a new line.
- My code should use the Betty style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/main/betty-style.pl) and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/main/betty-doc.pl).
- I'm not allowed to use global variables.
- No more than 5 functions per file.
- The prototypes of all my functions should be included in my header file called `menger.h`.
- Don’t forget to push my header file...
- All my header files should be include guarded.

## <span id="instructions">Instructions</span>

### Mandatory

<details>
    <summary>
        <b>0. 2D Menger sponge</b>
    </summary>
    <br>

Write a function that draws a 2D Menger Sponge.

Prototype: `void menger(int level);`:
- Where `level` is the level of the Menger Sponge to draw.
- If `level` is lower than `0`, your function must do nothing.
- You’re allowed to use the `math` library. Your program will be compiled using the `ld` flag `-lm`.

Format:

- First, read [Menger sponge](https://en.wikipedia.org/wiki/Menger_sponge).
- Here, we will only draw a 2D version of the Menger sponge, but the principle is the same.
- A level `N` sponge is a 3x3 square of level `N-1` sponges, except for the center one, which is left empty.
- A level 0 sponge is represented by the # character.
- Examples:
    - A level 0 sponge is a simple 1x1 square.
    - A level 1 sponge is a 3x3 square of level 0 sponges, except for the center one, which is left empty.
    - A level 2 sponge is a 3x3 square of level 1 sponges, except for the center one, which is left empty.
    - …

- TIP: The size of a level `N` Menger sponge is calculated as follows: `3^N`.

```bash
alex@~/menger$ cat 0-main.c 
#include <stdio.h>
#include <stdlib.h>

#include "menger.h"

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
    int level;

    if (ac < 2)
    {
        fprintf(stderr, "Usage: %s level\n", av[0]);
        return (EXIT_FAILURE);
    }

    level = atoi(av[1]);
    menger(level);

    return (EXIT_SUCCESS);
}
alex@~/menger$ gcc -Wall -Wextra -Werror -pedantic -o 0-menger 0-menger.c 0-main.c -lm
alex@~/menger$ ./0-menger 0
#
alex@~/menger$ ./0-menger 1
###
# #
###
alex@~/menger$ ./0-menger 2
#########
# ## ## #
#########
###   ###
# #   # #
###   ###
#########
# ## ## #
#########
alex@~/menger$ ./0-menger 3
###########################
# ## ## ## ## ## ## ## ## #
###########################
###   ######   ######   ###
# #   # ## #   # ## #   # #
###   ######   ######   ###
###########################
# ## ## ## ## ## ## ## ## #
###########################
#########         #########
# ## ## #         # ## ## #
#########         #########
###   ###         ###   ###
# #   # #         # #   # #
###   ###         ###   ###
#########         #########
# ## ## #         # ## ## #
#########         #########
###########################
# ## ## ## ## ## ## ## ## #
###########################
###   ######   ######   ###
# #   # ## #   # ## #   # #
###   ######   ######   ###
###########################
# ## ## ## ## ## ## ## ## #
###########################
alex@~/menger$ ./0-menger 4
#################################################################################
# ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## #
#################################################################################
###   ######   ######   ######   ######   ######   ######   ######   ######   ###
# #   # ## #   # ## #   # ## #   # ## #   # ## #   # ## #   # ## #   # ## #   # #
###   ######   ######   ######   ######   ######   ######   ######   ######   ###
#################################################################################
# ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## #
#################################################################################
#########         ##################         ##################         #########
# ## ## #         # ## ## ## ## ## #         # ## ## ## ## ## #         # ## ## #
#########         ##################         ##################         #########
###   ###         ###   ######   ###         ###   ######   ###         ###   ###
# #   # #         # #   # ## #   # #         # #   # ## #   # #         # #   # #
###   ###         ###   ######   ###         ###   ######   ###         ###   ###
#########         ##################         ##################         #########
# ## ## #         # ## ## ## ## ## #         # ## ## ## ## ## #         # ## ## #
#########         ##################         ##################         #########
#################################################################################
# ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## #
#################################################################################
###   ######   ######   ######   ######   ######   ######   ######   ######   ###
# #   # ## #   # ## #   # ## #   # ## #   # ## #   # ## #   # ## #   # ## #   # #
###   ######   ######   ######   ######   ######   ######   ######   ######   ###
#################################################################################
# ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## #
#################################################################################
###########################                           ###########################
# ## ## ## ## ## ## ## ## #                           # ## ## ## ## ## ## ## ## #
###########################                           ###########################
###   ######   ######   ###                           ###   ######   ######   ###
# #   # ## #   # ## #   # #                           # #   # ## #   # ## #   # #
###   ######   ######   ###                           ###   ######   ######   ###
###########################                           ###########################
# ## ## ## ## ## ## ## ## #                           # ## ## ## ## ## ## ## ## #
###########################                           ###########################
#########         #########                           #########         #########
# ## ## #         # ## ## #                           # ## ## #         # ## ## #
#########         #########                           #########         #########
###   ###         ###   ###                           ###   ###         ###   ###
# #   # #         # #   # #                           # #   # #         # #   # #
###   ###         ###   ###                           ###   ###         ###   ###
#########         #########                           #########         #########
# ## ## #         # ## ## #                           # ## ## #         # ## ## #
#########         #########                           #########         #########
###########################                           ###########################
# ## ## ## ## ## ## ## ## #                           # ## ## ## ## ## ## ## ## #
###########################                           ###########################
###   ######   ######   ###                           ###   ######   ######   ###
# #   # ## #   # ## #   # #                           # #   # ## #   # ## #   # #
###   ######   ######   ###                           ###   ######   ######   ###
###########################                           ###########################
# ## ## ## ## ## ## ## ## #                           # ## ## ## ## ## ## ## ## #
###########################                           ###########################
#################################################################################
# ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## #
#################################################################################
###   ######   ######   ######   ######   ######   ######   ######   ######   ###
# #   # ## #   # ## #   # ## #   # ## #   # ## #   # ## #   # ## #   # ## #   # #
###   ######   ######   ######   ######   ######   ######   ######   ######   ###
#################################################################################
# ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## #
#################################################################################
#########         ##################         ##################         #########
# ## ## #         # ## ## ## ## ## #         # ## ## ## ## ## #         # ## ## #
#########         ##################         ##################         #########
###   ###         ###   ######   ###         ###   ######   ###         ###   ###
# #   # #         # #   # ## #   # #         # #   # ## #   # #         # #   # #
###   ###         ###   ######   ###         ###   ######   ###         ###   ###
#########         ##################         ##################         #########
# ## ## #         # ## ## ## ## ## #         # ## ## ## ## ## #         # ## ## #
#########         ##################         ##################         #########
#################################################################################
# ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## #
#################################################################################
###   ######   ######   ######   ######   ######   ######   ######   ######   ###
# #   # ## #   # ## #   # ## #   # ## #   # ## #   # ## #   # ## #   # ## #   # #
###   ######   ######   ######   ######   ######   ######   ######   ######   ###
#################################################################################
# ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## #
#################################################################################
alex@~/menger$ ./0-menger -1
alex@~/menger$
```

#
**Repo:**
- GitHub repository: `holbertonschool-interview`.
- Directory: `menger`.
- File: `0-menger.c`, `menger.h`.
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

| **FILES**    | **DESCRIPTION**                                                   |
| :----------: | ----------------------------------------------------------------- |
| `menger.h`   | Header file containing the function prototype and include guards. |
| `0-menger.c` | Implementation of the `menger` function.                          |
| `0-main.c`   | Example usage of the `menger` function (for testing, not pushed). |
| `README.md`  | The README file you are currently reading 😉.                    |

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

3. Navigate to the `menger` directory:

```bash
cd menger
```

4. Compile the program using `gcc`:

```bash
gcc -Wall -Werror -Wextra -pedantic -o 0-menger 0-menger.c 0-main.c -lm
```

### How to use:

1. Once compiled, run the program with:

```bash
./0-menger 2
```

> Replace `2` with any desired level to draw the corresponding Menger Sponge.

## <span id="thanks">Thanks</span>

- A big thank you to all my Holberton School peers for their help and support throughout this project.

## <span id="authors">Authors</span>

**Fabien CHAVONET**
- GitHub: [@fchavonet](https://github.com/fchavonet)
