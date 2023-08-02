#include "binary_trees.h"

/**
 * binary_tree_nodes - count number of nodes with at least
 * one child in binary tree
 * @tree: pointer of root node of tree
 * Return: count of nodes has al least on child
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t lt, rt;

	if (tree == NULL)
		return (0);

	lt = binary_tree_nodes(tree->left);
	rt = binary_tree_nodes(tree->right);

	if (tree->left == NULL && tree->right == NULL)
		return (rt + lt);
	else
		return (1 + rt + lt);
}
