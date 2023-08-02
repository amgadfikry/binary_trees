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

	if (node->parent->left->n == node->n)
		return (node->parent->right);
	else
		return (node->parent->left);
}
