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
 * diff_dep - check if common ancestor with nodes not on
 * same depth
 * @l_dep: large depth
 * @s_dep: small depth
 * @l_ptr: pointer of node long depth
 * @s_ptr: pointer of node small depth
 * Return: pointer to common ancestor or NULL
 */

binary_tree_t *diff_dep(int l_dep, int s_dep, const binary_tree_t *l_ptr,
			const binary_tree_t *s_ptr)
{
	while (l_ptr)
	{
		if (l_ptr == s_ptr)
			return ((binary_tree_t *)s_ptr);
		l_ptr = l_ptr->parent;
		if (l_dep > s_dep)
			l_dep--;
		else
			s_ptr = s_ptr->parent;
	}
	return (NULL);
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
	int dep1, dep2;

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
		return (NULL);
	}
	else if (dep1 < dep2)
		return (diff_dep(dep2, dep1, ptr2, ptr1));
	else
		return (diff_dep(dep1, dep2, ptr1, ptr2));
}
