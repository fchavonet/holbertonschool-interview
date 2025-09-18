<img height="50" align="right" src="https://raw.githubusercontent.com/fchavonet/fchavonet/refs/heads/main/assets/images/logo-holberton_school.webp" alt="Holberton School logo">

# Substring With Concatenated Words

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

This project consists of implementing a function in C that finds all substrings within a string which are a concatenation of all words from a given list, exactly once, without intervening characters. All words are of the same length.

### Example:

```bash
s = "barfoothefoobarman";
words = ["foo","bar"];
Result -> Indices: [0, 9]
```

## <span id="objectives">Objectives</span>

At the end of this project, I should be able to explain to anyone, **without the help of Google**:

- How to scan a string to find all valid substrings formed by concatenating words.
- How to handle arrays of strings in C and work with pointers efficiently.
- How to allocate dynamic memory to store results.
- How to handle edge cases, like no solution found or repeated words.
- How to return results in a clean and structured way.

## <span id="requirements">Requirements</span>

- My programs and functions will be compiled with `gcc` using the flags `-Wall`, `-Werror`, `-Wextra` and `-pedantic`.
- All my files should end with a new line.
- My code should use the Betty style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/main/betty-style.pl) and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/main/betty-doc.pl).
- I am not allowed to use global variables.
- No more than 5 functions per file.
- The prototypes of all my functions should be included in my header file called `substring.h`.
- Don’t forget to push my header file...
- All my header files should be include guarded.

## <span id="instructions">Instructions</span>

### Mandatory

<details>
    <summary>
        <b>0. Substring with concatenated words</b>
    </summary>
    <br>

Write a function that finds all the possible substrings containing a list of words, within a given string.

- Prototype: `int *find_substring(char const *s, char const **words, int nb_words, int *n);`, where:
    - `s` is the string to scan.
    - `words` is the array of words all substrings must be a concatenation arrangement of.
    - `nb_words` is the number of elements in the array `words`.
    - `n` holds the address at which to store the number of elements in the returned array.
- Your function must return an allocated array, storing each index in s, at which a substring was found. If no solution is found, NULL can be returned.
- All words in the array `words` are the same length.
- A valid substring of `s` is the concatenation of each word in `words` exactly once and without any intervening characters.

```bash
alex@~/holbertonschool-interview_prep/substring$ cat main.c
#include <stdlib.h>
#include <stdio.h>

#include "substring.h"

int main(int ac, char const **av)
{
    char const *s;
    char const **words;
    int nb_words;
    int *indices;
    int n;
    int i;

    if (ac < 2)
    {
        fprintf(stderr, "Usage: %s <string> [word [word2 ...]]\n", av[0]);
        return (EXIT_FAILURE);
    }

    s = av[1];
    words = av + 2;
    nb_words = ac - 2;

    indices = find_substring(s, words, nb_words, &n);

    printf("Indices -> [");
    for (i = 0; i < n; i++)
    {
        if (i)
            printf(", ");
        printf("%d", indices[i]);
    }
    printf("]\n");

    return (EXIT_SUCCESS);
}
alex@~/holbertonschool-interview_prep/substring$ gcc -Wall -Wextra -Werror -pedantic main.c substring.c
alex@~/holbertonschool-interview_prep/substring$ ./a.out barfoothefoobarman foo bar
Indices -> [0, 9]
alex@~/holbertonschool-interview_prep/substring$ ./a.out wordgoodgoodgoodbestword word good best word
Indices -> []
alex@~/holbertonschool-interview_prep/substring$ ./a.out wordgoodgoodgoodbestword word good best good
Indices -> [8]
alex@~/holbertonschool-interview_prep/substring$
```

#
**Repo:**
- GitHub repository: `holbertonschool-interview`.
- Directory: `substring`.
- File: `substring.c`, `substring.h`.
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

| **FILES**          | **DESCRIPTION**                               |
| :----------------: | --------------------------------------------- |
| `substring.h` | Header file containing the function prototype.     |
| `substring.c` | Implementation of `find_substring`.                |
| `main.c`      | Example file to test the function (not mandatory). |
| `README.md`   | The README file you are currently reading 😉.      |

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

3. Navigate to the `substring` directory:

```bash
cd substring
```

4. Compile the program using `gcc`:

```bash
gcc -Wall -Wextra -Werror -pedantic main.c substring.c -o substring
```

### How to use:

1. Run the binary with a string and a list of words:

```bash
./substring wordgoodgoodgoodbestword word good best good
```

> The output will be `Indices -> [8]`.

## <span id="thanks">Thanks</span>

- A big thank you to all my Holberton School peers for their help and support throughout this project.

## <span id="authors">Authors</span>

**Fabien CHAVONET**
- GitHub: [@fchavonet](https://github.com/fchavonet)
