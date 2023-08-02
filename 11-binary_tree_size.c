#include "binary_trees.h"

/**
 * binary_tree_size - measure size of binary tree
 * @tree: pointer to root node
 * Return: size of binary tree
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t lt, rt;

	if (tree == NULL)
		return (0);

	lt = binary_tree_size(tree->left);
	rt = binary_tree_size(tree->right);

	return (1 + lt + rt);
}
