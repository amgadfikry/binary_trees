#include "binary_trees.h"

/**
 * b_height - calculate height of binary tree
 * @tree: pointer to root of tree
 * Return: height of binary tree
 */

int b_height(const binary_tree_t *tree)
{
	int lt, rt;

	if (tree == NULL)
		return (0);

	if (tree->right == NULL && tree->left == NULL)
		return (0);

	lt = b_height(tree->left);
	rt = b_height(tree->right);

	if (lt > rt)
		return (1 + lt);
	else
		return (1 + rt);
}

/**
 * binary_tree_balance - measure balnace factor of binary tree
 * @tree: pointer to root of binary tree
 * Return: 0 if same or positive number if left more than right
 * or negative if right more than left
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int lt = 0, rt = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		lt = 1 + b_height(tree->left);
	if (tree->right)
		rt = 1 + b_height(tree->right);

	return (lt - rt);
}
