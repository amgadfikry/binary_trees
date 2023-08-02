#include "binary_trees.h"

/**
 * binary_tree_is_leaf - check if node is leaf node or not
 * @node: pointer of node to check it
 * Return: 0 if not leaf and 1 if is a leaf node
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->right == NULL && node->left == NULL)
		return (1);
	else
		return (0);
}
