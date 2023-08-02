#include "binary_trees.h"

/**
 * binary_tree_insert_right - insert a node as right child to
 * this parent node
 * @parent: pointer to parent node to add node to right child
 * @value: data value of new node
 * Return: pointer to new node
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
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

	if (parent->right == NULL)
		parent->right = node;
	else
	{
		temp = parent->right;
		parent->right = node;
		node->right = temp;
		temp->parent = node;
	}

	return (node);
}
