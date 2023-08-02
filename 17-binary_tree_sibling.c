#include "binary_trees.h"

/**
 * binary_tree_sibling - find sibling of given node
 * @node: pointer to node
 * Return: pointer of sibling node
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == NULL || node->parent->right == NULL)
		return (NULL);

	if (node->parent->right->n == node->n)
		return (node->parent->left);
	else
		return (node->parent->right);
}
