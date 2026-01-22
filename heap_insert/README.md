<img height="50" align="right" src="https://raw.githubusercontent.com/fchavonet/fchavonet/refs/heads/main/assets/images/logo-holberton_school.webp" alt="Holberton School logo">

# Heap Insert

## Description

This project focuses on implementing a Max Binary Heap in C, with a specific emphasis on inserting values while preserving both the complete binary tree structure and the Max Heap ordering property.

The goal is to deepen the understanding of tree-based data structures and their underlying insertion logic, commonly encountered in technical interviews.

## Objectives

At the end of this project, I should be able to explain to anyone, **without the help of Google**:

- What a Binary Heap is and how it differs from other binary trees.
- The properties of a Max Binary Heap.
- How to insert a value into a Max Heap while maintaining heap order.
- How to navigate a binary tree using implicit array indexing logic.
- The time complexity of heap insertion.

## Requirements

- All files must end with a new line.
- Code must follow the [Betty](https://github.com/hs-hq/Betty/tree/main) coding style.
- No more than 5 functions per file (except where explicitly allowed).
- The standard C library is allowed.
- No global variables allowed.
- All function prototypes must be declared in `binary_trees.h`.
- All header files must be include guarded.
- Compilation will be done using `gcc` with the flags:
  - `-Wall`
  - `-Werror`
  - `-Wextra`
  - `-pedantic`

## Instructions

### Mandatory

<details>
	<summary>
		<b>0. New node</b>
	</summary>
	<br>

Write a function that creates a binary tree node:

- Prototype: `binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);`.
- `parent` is a pointer to the parent node of the node to create.
- `value` is the value to put in the new node.
- When created, a node does not have any children.
- Your function must return a pointer to the new node, or `NULL` on failure.

```
alex@/tmp/binary_trees$ cat 0-main.c 
#include 
#include "binary_trees.h"

/**
 * _binary_tree_delete - Deallocate a binary tree
 *
 * @tree: Pointer to the root of the tree to delete
 */
static void _binary_tree_delete(binary_tree_t *tree)
{
    if (tree)
    {
        _binary_tree_delete(tree->left);
        _binary_tree_delete(tree->right);
        free(tree);
    }
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);

    root->left = binary_tree_node(root, 12);
    root->left->left = binary_tree_node(root->left, 6);
    root->left->right = binary_tree_node(root->left, 16);

    root->right = binary_tree_node(root, 402);
    root->right->left = binary_tree_node(root->right, 256);
    root->right->right = binary_tree_node(root->right, 512);

    binary_tree_print(root);
    _binary_tree_delete(root);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-binary_tree_node.c -o 0-node
alex@/tmp/binary_trees$ ./0-node
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (016)     (256)     (512)
alex@/tmp/binary_trees$
```

#
**Repo:**
- GitHub repository: `holbertonschool-interview`.
- Directory: `heap_insert`.
- File: `0-binary_tree_node.c`.
<hr>
</details>

<details>
	<summary>
		<b>1. Heap - Insert</b>
	</summary>
	<br>

Write a function that inserts a value into a Max Binary Heap:

- Prototype: `heap_t *heap_insert(heap_t **root, int value);`.
- `root` is a double pointer to the root node of the Heap.
- `value` is the value to store in the node to be inserted.
- Your function must return a pointer to the inserted node, or `NULL` on failure.
- If the address stored in `root` is `NULL`, the created node must become the root node.
- You have to respect a `Max Heap` ordering.
- You are allowed to have up to `6` functions in your file.

Your file `0-binary_tree_node.c` will be compiled during the correction.

```
alex@/tmp/binary_trees$ cat 1-main.c
#include 
#include 
#include "binary_trees.h"

/**
 * _binary_tree_delete - Deallocate a binary tree
 *
 * @tree: Pointer to the root of the tree to delete
 */
static void _binary_tree_delete(binary_tree_t *tree)
{
    if (tree)
    {
        _binary_tree_delete(tree->left);
        _binary_tree_delete(tree->right);
        free(tree);
    }
}

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    heap_t *root;
    heap_t *node;

    root = NULL;
    node = heap_insert(&root, 98);
    printf("Inserted: %d\n", node->n);
    binary_tree_print(root);
    node = heap_insert(&root, 402);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = heap_insert(&root, 12);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = heap_insert(&root, 46);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = heap_insert(&root, 128);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = heap_insert(&root, 256);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = heap_insert(&root, 512);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = heap_insert(&root, 50);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    _binary_tree_delete(root);
    return (0);
}

alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 1-main.c 1-heap_insert.c 0-binary_tree_node.c -o 1-heap_insert
alex@/tmp/binary_trees$ ./1-heap_insert
Inserted: 98
(098)

Inserted: 402
  .--(402)
(098)

Inserted: 12
  .--(402)--.
(098)     (012)

Inserted: 46
       .--(402)--.
  .--(098)     (012)
(046)

Inserted: 128
       .-------(402)--.
  .--(128)--.       (012)
(046)     (098)

Inserted: 256
       .-------(402)-------.
  .--(128)--.         .--(256)
(046)     (098)     (012)

Inserted: 512
       .-------(512)-------.
  .--(128)--.         .--(402)--.
(046)     (098)     (012)     (256)

Inserted: 50
            .-------(512)-------.
       .--(128)--.         .--(402)--.
  .--(050)     (098)     (012)     (256)
(046)
alex@/tmp/binary_trees$
```

#
**Repo:**
- GitHub repository: `holbertonschool-interview`.
- Directory: `heap_insert`.
- File: `1-heap_insert.c`, `0-binary_tree_node.c`.
<hr>
</details>

## Tech Stack

## File Description

| **FILE**               | **DESCRIPTION**                                                         |
| :--------------------: | ----------------------------------------------------------------------- |
| `binary_trees.h`       | Header file containing structures and function prototypes.              |
| `0-binary_tree_node.c` | Implementation of binary tree node creation.                            |
| `1-heap_insert.c`      | Implementation of value insertion into a Max Binary Heap.               |
| `binary_tree_print.c`  | Helper function provided by Holberton School to visualize binary trees. |
| `main.c`               | Generic test file used to validate heap insertion behavior locally.     |
| `README.md`            | The README file you are currently reading 😉.                           |

## Installation & Usage

### Installation

1. Clone this repository:
    - Open your preferred Terminal.
    - Navigate to the directory where you want to clone the repository.
    - Run the following command:

```
git clone https://github.com/fchavonet/holbertonschool-interview.git
```

2. Open the cloned repository.

3.  Navigate to the `heap_insert` directory:

```
cd heap_insert
```

4. Compile the program using `gcc`:

```
gcc -Wall -Werror -Wextra -pedantic *.c -o heap_insert
```

> The `binary_tree_print` function is provided by Holberton School for visualization purposes only and was not implemented by me.

### Usage

1. Once compiled, run the program with:

```
./heap_insert
```

You will see this output in your Terminal :

```
Inserted: 98
(098)

Inserted: 402
  .--(402)
(098)

Inserted: 12
  .--(402)--.
(098)     (012)

Inserted: 46
       .--(402)--.
  .--(098)     (012)
(046)

Inserted: 128
       .-------(402)--.
  .--(128)--.       (012)
(046)     (098)

Inserted: 256
       .-------(402)-------.
  .--(128)--.         .--(256)
(046)     (098)     (012)

Inserted: 512
       .-------(512)-------.
  .--(128)--.         .--(402)--.
(046)     (098)     (012)     (256)

Inserted: 50
            .-------(512)-------.
       .--(128)--.         .--(402)--.
  .--(050)     (098)     (012)     (256)
(046)
```

## What's Next?

- Implement heap extraction (remove the root).
- Add heap sort functionality.
- Extend the project to support Min Binary Heaps.

## Thanks

- A big thank you to all my Holberton School peers for their help and support throughout this project.

## Author(s)

**Fabien CHAVONET**
- GitHub: [@fchavonet](https://github.com/fchavonet)
