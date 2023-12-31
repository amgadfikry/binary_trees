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
		return (1);
	if (tree->left)
		lt = b_height(tree->left);
	if (tree->right)
		rt = b_height(tree->right);

	if (lt > rt)
		return (1 + lt);
	else
		return (1 + rt);
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
	int balance;

	if (tree == NULL)
		return (0);

	balance = b_height(tree->left) - b_height(tree->right);
	if (is_full(tree) && balance == 0)
		return (1);
	else
		return (0);
}
