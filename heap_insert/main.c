#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_delete - Deallocate a binary tree.
 * @tree: pointer to the root of the tree to delete.
 */
static void binary_tree_delete(binary_tree_t *tree)
{
	if (tree)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}

/**
 * main - Entry point.
 *
 * Return: always 0
 */
int main(void)
{
	heap_t *root = NULL;
	heap_t *node;
	int values[] = {98, 402, 12, 46, 128, 256, 512, 50};
	size_t i, size = sizeof(values) / sizeof(values[0]);

	printf("\n");

	for (i = 0; i < size; i++)
	{
		node = heap_insert(&root, values[i]);
		if (node == NULL)
		{
			printf("Error inserting value %d\n", values[i]);
			binary_tree_delete(root);
			return (1);
		}

		printf("Inserted: %d\n", node->n);
		binary_tree_print(root);
		printf("\n");
	}

	binary_tree_delete(root);
	return (0);
}
