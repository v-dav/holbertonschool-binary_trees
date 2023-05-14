#include "binary_trees.h"

/**
 * binary_tree_insert_left - a function that inserts a node as the left-child
 * of another node
 * @parent: Pointer to the parent node
 * @value: Value to store in the new node
 *
 * Return: a pointer to a newly created node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_left_node = NULL;
	binary_tree_t *temp = NULL;

	if (parent == NULL)
		return (NULL);

	new_left_node = binary_tree_node(parent, value);
	if (new_left_node == NULL)
		return (NULL);

	if (parent->left == NULL)
		parent->left = new_left_node;
	else
	{
		temp = parent->left;
		parent->left = new_left_node;
		new_left_node->left = temp;
		temp->parent = new_left_node;
	}

	return (new_left_node);
}
