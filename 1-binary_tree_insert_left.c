#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert a node as left child to
 * this parent node
 * @parent: pointer to parent node to add node to left child
 * @value: data value of new node
 * Return: pointer to new node
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node, *temp;

	if (parent == NULL)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);
	node->n = value;
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;

	if (parent->left == NULL)
		parent->left = node;
	else
	{
		temp = parent->left;
		parent->left = node;
		node->left = temp;
		temp->parent = node;
	}

	return (node);
}
