#include "binary_trees.h"

/**
 * binary_tree_inorder - traverse binary tree by inorder way
 * @tree: pointer to root of binary tree
 * @func: pointer to function that pass data of each node
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *ptr;

	if (tree == NULL || func == NULL)
		return;

	ptr = tree;

	if (ptr->left)
		binary_tree_inorder(ptr->left, func);

	func(ptr->n);

	if (ptr->right)
		binary_tree_inorder(ptr->right, func);
}
