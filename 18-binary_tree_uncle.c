#include "binary_trees.h"

/**
 * binary_tree_uncle - get uncle of given node
 * @node: pointer to node
 * Return: pointer of uncle of node
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *grand;

	if (node == NULL)
		return (NULL);
	parent = node->parent;
	if (parent == NULL)
		return (NULL);
	grand = parent->parent;
	if (grand == NULL)
		return (NULL);
	if (grand->left == NULL || grand->right == NULL)
		return (NULL);
	if (grand->left->n == parent->n)
		return (grand->right);
	else
		return (grand->left);
}
