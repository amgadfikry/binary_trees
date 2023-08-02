#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotate tree to right
 * @tree: pointer to root of tree need to rotate
 * Return: pointer of new root of tree
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *temp, *new;

	if (tree == NULL)
		return (NULL);

	if (tree->right == NULL && tree->left == NULL)
		return (tree);

	new = tree->left;
	temp = tree->parent;
	tree->parent = new;
	new->parent = temp;
	tree->left = new->right;
	new->right = tree;
	return (new);
}
