#include "binary_trees.h"

/**
 * binary_tree_leaves - count number of leaves of binary tree
 * @tree: pointer of root node of tree
 * Return: count of leaves nodes
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t lt, rt;

	if (tree == NULL)
		return (0);

	lt = binary_tree_leaves(tree->left);
	rt = binary_tree_leaves(tree->right);

	if (tree->left == NULL && tree->right == NULL)
		return (1 + rt + lt);
	else
		return (rt + lt);
}
