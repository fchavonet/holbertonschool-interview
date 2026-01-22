#include "binary_trees.h"

/**
 * heap_size - Computes the size of a binary heap.
 * @root: pointer to the root node.
 *
 * Return: size of the heap.
 */
static size_t heap_size(const heap_t *root)
{
	if (root == NULL)
		return (0);

	return (1 + heap_size(root->left) + heap_size(root->right));
}

/**
 * get_insert_parent - Finds the parent for the next inserted node.
 * @root: pointer to the root.
 * @size: current size of the heap.
 *
 * Return: pointer to the parent node.
 */
static heap_t *get_insert_parent(heap_t *root, size_t size)
{
	size_t path;
	heap_t *current;

	current = root;
	for (path = 1UL << (sizeof(size_t) * 8 - 1); !(size & path); path >>= 1)
		;

	for (path >>= 1; path > 1; path >>= 1)
	{
		if (size & path)
			current = current->right;
		else
			current = current->left;
	}

	return (current);
}

/**
 * heapify_up - Restores max heap property after insertion.
 * @node: pointer to the inserted node.
 *
 * Return: pointer to the final node position.
 */
static heap_t *heapify_up(heap_t *node)
{
	int tmp;

	while (node->parent && node->n > node->parent->n)
	{
		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;
		node = node->parent;
	}

	return (node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: double pointer to the root node.
 * @value: value to insert.
 *
 * Return: pointer to the inserted node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent, *node;
	size_t size;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	size = heap_size(*root);
	parent = get_insert_parent(*root, size + 1);
	node = binary_tree_node(parent, value);
	if (node == NULL)
		return (NULL);

	if (parent->left == NULL)
		parent->left = node;
	else
		parent->right = node;

	return (heapify_up(node));
}
