#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotate tree to left
 * @tree: pointer to root of tree need to rotate
 * Return: pointer of new root of tree
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp, *new;

	if (tree == NULL)
		return (NULL);

	if (tree->right == NULL && tree->left == NULL)
		return (tree);

	new = tree->right;
	temp = tree->parent;
	tree->parent = new;
	new->parent = temp;
	tree->right = new->left;
	new->left = tree;
	return (new);
}
