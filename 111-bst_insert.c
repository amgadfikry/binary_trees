#include "binary_trees.h"

/**
 * create_node - create node and return its pointer
 * @val: value of node
 * Return:pointer to new node
 */

bst_t *create_node(int val)
{
	bst_t *node;

	node = malloc(sizeof(bst_t));
	if (node == NULL)
		return (NULL);
	node->parent = NULL;
	node->n = val;
	node->right = NULL;
	node->left = NULL;

	return (node);
}

/**
 * bst_insert - insert new node to BST
 * @tree: double pointer of tree
 * @value: value of new node
 * Return: NULL if fail or pointer to new node
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *root, *node;

	if (tree == NULL)
		return (NULL);
	node = create_node(value);
	if (*tree == NULL)
	{
		*tree = node;
		return (*tree);
	}
	root = *tree;
	while (root)
	{
		if (root->n == value)
		{
			free(node);
			return (NULL);
		}
		else if (root->n < value)
		{
			if (root->right == NULL)
			{
				node->parent = root;
				root->right = node;
				break;
			}
			root = root->right;
		}
		else
		{
			if (root->left == NULL)
			{
				node->parent = root;
				root->left = node;
				break;
			}
			root = root->left;
		}
	}
	return (node);
}
