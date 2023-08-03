#include "binary_trees.h"

/**
 * array_to_bst - convert array to BST
 * @array: pointer to begin of array
 * @size: size of array
 * Return: pointer to root of tree
 */

bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *root, *tree;

	if (array == NULL)
		return (NULL);

	tree = malloc(sizeof(bst_t));
	if (tree == NULL)
		return (NULL);
	tree = NULL;

	root = bst_insert(&tree, array[0]);
	for (i = 1; i < size; i++)
	{
		bst_insert(&tree, array[i]);
	}
	return (root);
}
