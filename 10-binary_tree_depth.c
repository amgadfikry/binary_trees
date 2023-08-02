#include "binary_trees.h"

/**
 * binary_tree_depth - calculate depth of given node
 * @tree: pointer to node
 * Return: depth of node
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t count = 0;
	const binary_tree_t *ptr;

	if (tree == NULL)
		return (0);

	ptr = tree;
	while (ptr->parent)
	{
		ptr = ptr->parent;
		count++;
	}

	return (count);
}
