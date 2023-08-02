#include "binary_trees.h"

/**
 * binary_tree_height - calculate height of binary tree
 * @tree: pointer to root of tree
 * Return: height of binary tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lt, rt;

	if (tree == NULL)
		return (0);

	if (tree->right == NULL && tree->left == NULL)
		return (0);

	lt = binary_tree_height(tree->left);
	rt = binary_tree_height(tree->right);

	if (lt > rt)
		return (1 + lt);
	else
		return (1 + rt);
}
