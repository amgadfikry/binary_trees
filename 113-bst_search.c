#include "binary_trees.h"

/**
 * bst_search - search for node with it's value
 * @tree: pointer to root of tree
 * @value: value to search by
 * Return: pointer to node if found or NULL
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	 bst_t *ptr = (bst_t *)tree;

	if (tree == NULL)
		return (NULL);

	while (ptr)
	{
		if (value == ptr->n)
			return (ptr);
		else if (value > ptr->n)
			ptr = ptr->right;
		else
			ptr = ptr->left;
	}
	return (NULL);
}
