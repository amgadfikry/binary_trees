#include "binary_trees.h"

/**
 * enq - add element to last of queue
 * @head: pointer to head of queue
 * @p: pointer value to svae
 * Return: pointer of head
 */

queue *enq(queue *head, const binary_tree_t *p)
{
	queue *ptr, *temp;

	if (head == NULL)
	{
		head = malloc(sizeof(queue));
		if (head == NULL)
			return (NULL);
		head->p = p;
		head->next = NULL;
		return (head);
	}
	else
	{
		ptr = head;
		while (ptr->next)
			ptr = ptr->next;
		temp = malloc(sizeof(queue));
		if (temp == NULL)
			return (NULL);
		temp->p = p;
		temp->next = NULL;
		ptr->next = temp;
		return (head);
	}
}

/**
 * rm_q - remove first element in queue
 * @head: pointer to head of queue
 * Return: new header of queue
 */

queue *rm_q(queue *head)
{
	queue *ptr;

	ptr = head->next;
	free(head);
	head = ptr;
	return (head);
}

/**
 * binary_tree_levelorder - level order traversal
 * @tree:  pointer of root of tree
 * @func: pointer to function that apply on each node
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue *head;
	const binary_tree_t *node;

	if (tree == NULL || func == NULL)
		return;

	head = enq(NULL, tree);
	while (head)
	{
		node = head->p;
		head = rm_q(head);
		func(node->n);
		if (node->left)
			head = enq(head, node->left);
		if (node->right)
			head = enq(head, node->right);
	}
}
