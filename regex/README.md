<img height="50" align="right" src="https://raw.githubusercontent.com/fchavonet/fchavonet/refs/heads/main/assets/images/logo-holberton_school.webp" alt="Holberton School logo">

# RegEx

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

In this project, you will implement a function in C that checks whether a given regular expression pattern matches an entire input string. The engine must support two special characters:

- `.` (dot) matches any single character.
- `*` (asterisk) matches zero or more occurrences of the preceding character.

For example, the pattern `H*` matches `"H"`, `"HH"`, or even an empty string, while `.*` matches any string. The function must return `1` if the pattern matches the entire string, or `0` otherwise.

## <span id="objectives">Objectives</span>

At the end of this project, I should be able to explain to anyone, **without the help of Google**:

- How to design and implement a recursive algorithm for simple regular expression matching.
- How to handle the special behavior of `.` and `*` in a pattern.
- How to structure C code with header files and implementation files while adhering to style guidelines.
- How to use include guards and avoid global variables in a C project.

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
        <b>0. Simple RegEx</b>
    </summary>
    <br>

Write a function that checks whether a given pattern matches a given string.

- Prototype: `int regex_match(char const *str, char const *pattern);`, where:
    - `str` is the string to scan.
    - `pattern` is the regular expression.
- Your function must return `1` if the pattern matches the string, or `0` if it doesn’t.
- `str` can be empty, and can contain any ASCII character in the exception of `.` and `*`.
- `pattern` can be empty, and can contain any ASCII character, including `.` and `*`.
The regular expression matching must support the characters `.` and `*`:
  - `.` matches any single character.
  - `*` matches zero or more of the preceding character.

```bash
alex@~/holbertonschool-interview_prep/regex$ cat main.c
#include <stdlib.h>
#include <stdio.h>

#include "regex.h"

#define TEST_MATCH(s, p)    do {\
    {\
        int res = regex_match(s, p);\
        printf("%s -> %s = %d\n", s, p, res);\
    }\
} while(0)

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    TEST_MATCH("H", "H");
    TEST_MATCH("HH", "H");
    TEST_MATCH("HH", "H*");
    TEST_MATCH("HHHHHHHHHHHHHHHHH", "H*");

    TEST_MATCH("Holberton", ".*");
    TEST_MATCH("Alex", ".*");
    TEST_MATCH("Guillaume", ".*");
    TEST_MATCH("Julien", ".*");

    TEST_MATCH("Holberton", "Z*H.*");
    TEST_MATCH("Holberton", "Z*H.*olberton");
    TEST_MATCH("Holberton", "Z*H.*o.");
    TEST_MATCH("Holberton", "Z*H.*o");

    TEST_MATCH("Holberton", "holberton");
    TEST_MATCH("Holberton", ".olberton");

    TEST_MATCH("!H@o#l$b%e^r&t(o)n_", "!.@.#.$.%.^.&.(.)._");

    return (EXIT_SUCCESS);
}
alex@~/holbertonschool-interview_prep/regex$ gcc -Wall -Wextra -Werror -pedantic main.c regex.c
alex@~/holbertonschool-interview_prep/regex$ ./a.out
H -> H = 1
HH -> H = 0
HH -> H* = 1
HHHHHHHHHHHHHHHHH -> H* = 1
Holberton -> .* = 1
Alex -> .* = 1
Guillaume -> .* = 1
Julien -> .* = 1
Holberton -> Z*H.* = 1
Holberton -> Z*H.*olberton = 1
Holberton -> Z*H.*o. = 1
Holberton -> Z*H.*o = 0
Holberton -> holberton = 0
Holberton -> .olberton = 1
!H@o#l$b%e^r&t(o)n_ -> !.@.#.$.%.^.&.(.)._ = 1
alex@~/holbertonschool-interview_prep/regex$
```

#
**Repo:**
- GitHub repository: `holbertonschool-interview`.
- Directory: `regex`.
- File: `regex.c`, `regex.h`, `main.c`.
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

## 📂 <span id="files-description">File description</span>

| **FILES**   | **DESCRIPTION**                                                                                    |
| :---------: | -------------------------------------------------------------------------------------------------- |
| `regex.h`   | Header file containing the prototype for `regex_match` and include guards.                         |
| `regex.c`   | Implementation of the `regex_match` function and its helper routines (`match_here`, `match_star`). |
| `main.c`    | Example `main.c` to test the `regex_match` function.                                               |
| `README.md` | The README file you are currently reading 😉.                                                      |


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

3. Navigate to the `regex` directory:

```bash
cd regex
```

4. Compile the program using `gcc`:

```bash
gcc -Wall -Wextra -Werror -pedantic regex.c main.c -o regex_test
```

### How to use:

1. Run the binary:

```bash
./regex_test
```

2. You should see this output:

```bash
H -> H = 1
HH -> H = 0
HH -> H* = 1
HHHHHHHHHHHHHHHHH -> H* = 1
Holberton -> .* = 1
Alex -> .* = 1
Guillaume -> .* = 1
Julien -> .* = 1
Holberton -> Z*H.* = 1
Holberton -> Z*H.*olberton = 1
Holberton -> Z*H.*o. = 1
Holberton -> Z*H.*o = 0
Holberton -> holberton = 0
Holberton -> .olberton = 1
!H@o#l$b%e^r&t(o)n_ -> !.@.#.$.%.^.&.(.)._ = 1
```

## <span id="thanks">Thanks</span>

- A big thank you to all my Holberton School peers for their help and support throughout this project.

## <span id="authors">Authors</span>

**Fabien CHAVONET**
- GitHub: [@fchavonet](https://github.com/fchavonet)
