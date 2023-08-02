#include "binary_trees.h"

/**
 * b_height - calculate height of binary tree
 * @tree: pointer to root of tree
 * Return: height of binary tree
 */

int b_height(const binary_tree_t *tree)
{
	int lt = 0, rt = 0;

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
 * tree_balance - measure balnace factor of binary tree
 * @tree: pointer to root of binary tree
 * Return: 0 if same or positive number if left more than right
 * or negative if right more than left
 */

int tree_balance(const binary_tree_t *tree)
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

/**
 * is_full - check if binary tree is full or not
 * @tree: pointer of root of binary tree
 * Return: 1 if full or 0 if not full
 */

int is_full(const binary_tree_t *tree)
{
	int lt, rt;

	if (tree == NULL)
		return (0);

	if (tree->right == NULL && tree->left == NULL)
		return (1);

	lt = is_full(tree->left);
	rt = is_full(tree->right);

	if (lt && rt)
		return (1);
	else
		return (0);
}

/**
 * binary_tree_is_perfect - check if binary tree is perfect or not
 * @tree: pointer to root of binary tree
 * Return: 0 if not perfect and 1 if perfect
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (is_full(tree))
	{
		if (tree_balance(tree) == 0)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
