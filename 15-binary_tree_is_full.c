#include "binary_trees.h"

/**
 * binary_tree_is_full - check if binary tree is full or not
 * @tree: pointer of root of binary tree
 * Return: 1 if full or 0 if not full
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int lt, rt;

	if (tree == NULL)
		return (0);

	if (tree->right == NULL && tree->left == NULL)
		return (1);

	lt = binary_tree_is_full(tree->left);
	rt = binary_tree_is_full(tree->right);

	if (lt && rt)
		return (1);
	else
		return (0);
}
