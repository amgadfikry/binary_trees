#include "binary_trees.h"

/**
 * b_size - measure size of binary tree
 * @tree: pointer to root node
 * Return: size of binary tree
 */

int b_size(const binary_tree_t *tree)
{
	int lt, rt;

	if (tree == NULL)
		return (0);

	lt = b_size(tree->left);
	rt = b_size(tree->right);

	return (1 + lt + rt);
}


/**
 * arr_insert - insert new value in given arr
 * @arr: pointer to arr
 * @val: value inserted to arr
 */

void arr_insert(int *arr, int val)
{
	int index = 0;

	while (arr[index] != -500)
		index++;
	arr[index] = val;
}

/**
 * arr_inorder - make inorder array of given tree
 * @tree: pointer to tree
 * @arr: array to put tree in it
 * @func: function insert data in array
 */

void arr_inorder(const binary_tree_t *tree, int *arr, void (*func)(int *, int))
{
	const binary_tree_t *ptr;

	if (tree == NULL || func == NULL)
		return;

	ptr = tree;

	if (ptr->left)
		arr_inorder(ptr->left, arr, func);

	func(arr, ptr->n);

	if (ptr->right)
		arr_inorder(ptr->right, arr, func);
}

/**
 * binary_tree_is_bst - check if tree is BST or not
 * @tree: pointer to tree
 * Return: 1 if BST or 0 if not
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	int *arr, size, i;

	if (tree == NULL)
		return (0);
	if (tree->right == NULL && tree->left == NULL)
		return (1);

	size = b_size(tree);
	arr = malloc(sizeof(int) * size);
	if (arr == NULL)
		return (0);

	for (i = 0; i < size; i++)
		arr[i] = -500;

	arr_inorder(tree, arr, &arr_insert);

	for (i = 0; i < size - 1; i++)
	{
		if (arr[i] >= arr[i + 1])
		{
			free(arr);
			return (0);
		}
	}

	free(arr);
	return (1);
}
