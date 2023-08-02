#include "binary_trees.h"

/**
 * b_size - measure size of binary tree
 * @tree: pointer to root node
 * Return: size of binary tree
 */

size_t b_size(const binary_tree_t *tree)
{
	size_t lt, rt;

	if (tree == NULL)
		return (0);

	lt = b_size(tree->left);
	rt = b_size(tree->right);

	return (1 + lt + rt);
}

/**
 * check_comp - check if complete tree or not
 * @tree: pointer to root of tree
 * @nodes: size of tree
 * @index: index of current node
 * Return: 0 if not complete and 1 if complete
 */

int check_comp(const binary_tree_t *tree, int nodes, int index)
{
	int lt, rt;

	if (tree == NULL)
		return (1);
	if (index >= nodes)
		return (0);
	lt = check_comp(tree->left, nodes, 2 * index + 1);
	rt = check_comp(tree->right, nodes, 2 * index + 2);

	if (rt && lt)
		return (1);
	else
		return (0);
}

/**
 * binary_tree_is_complete - check if binary tree if complete or not
 * @tree: pointer to root of tree
 * Return: 1 if complete and 0 if not
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (check_comp(tree, b_size(tree), 0));
}
