#include "binary_trees.h"

/**
 * binary_tree_preorder - traverse binary tree through preorder way
 * @tree: pointer to root node of tree
 * @func: pointer to call on each node data
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *ptr;

	if (tree == NULL || func == NULL)
		return;

	ptr = tree;
	func(ptr->n);

	if (ptr->left)
		binary_tree_preorder(ptr->left, func);
	if (ptr->right)
		binary_tree_preorder(ptr->right, func);
}
