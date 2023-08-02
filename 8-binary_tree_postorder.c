#include "binary_trees.h"

/**
 * binary_tree_postorder - traverse binary tree in postorder way
 * @tree: pointer to root of tree
 * @func: pointer to function use it on each data of node
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *ptr;

	if (tree == NULL || func == NULL)
		return;

	ptr = tree;

	if (ptr->left)
		binary_tree_postorder(ptr->left, func);

	if (ptr->right)
		binary_tree_postorder(ptr->right, func);

	func(ptr->n);
}
