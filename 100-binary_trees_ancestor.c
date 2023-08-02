#include "binary_trees.h"

/**
 * b_depth - calculate depth of given node
 * @tree: pointer to node
 * Return: depth of node
 */

size_t b_depth(const binary_tree_t *tree)
{
	size_t count = 0;
	const binary_tree_t *ptr;

	if (tree == NULL)
		return (0);

	ptr = tree;
	while (ptr->parent)
	{
		ptr = ptr->parent;
		count++;
	}

	return (count);
}

/**
 * binary_trees_ancestor - find lowest common ancestor of two nodes
 * @first: pointer to first node
 * @second: pointer to second node
 * Return: pointer to common ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	const binary_tree_t *ptr1, *ptr2;
	int dep1, dep2, temp;

	if (first == NULL || second == NULL)
		return (NULL);
	ptr1 = first;
	ptr2 = second;
	dep1 = b_depth(ptr1);
	dep2 = b_depth(ptr2);
	if (dep1 == dep2)
	{
		while (ptr1 && ptr2)
		{
			if (ptr1 == ptr2)
				return ((binary_tree_t *)ptr1);
			ptr1 = ptr1->parent;
			ptr2 = ptr2->parent;
		}
	}
	else if (dep1 < dep2)
	{
		temp = dep2;
		while (ptr2)
		{
			if (ptr2 == ptr1)
				return ((binary_tree_t *)ptr1);
			ptr2 = ptr2->parent;
			if (temp > dep1)
				temp--;
			else
				ptr1 = ptr1->parent;
		}
	}
	else
	{
		temp = dep1;
                while (ptr1)
                {
                        if (ptr2 == ptr1)
                                return ((binary_tree_t *)ptr1);
                        ptr1 = ptr1->parent;
                        if (temp > dep2)
                                temp--;
                        else
                                ptr2 = ptr2->parent;
                }
	}
	return (NULL);
}
