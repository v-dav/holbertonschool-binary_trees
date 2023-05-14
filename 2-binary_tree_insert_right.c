#include "binary_trees.h"

/**
 * binary_tree_insert_right - a function that inserts a node as the right-child
 * of another node
 * @parent: Pointer to the parent node
 * @value: Value to store in the new node
 *
 * Return: a pointer to a newly created node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_right_node = NULL;
	binary_tree_t *temp = NULL;

	if (parent == NULL)
		return (NULL);

	new_right_node = binary_tree_node(parent, value);
	if (new_right_node == NULL)
		return (NULL);

	if (parent->right == NULL)
		parent->right = new_right_node;
	else
	{
		temp = parent->right;
		parent->right = new_right_node;
		new_right_node->right = temp;
		temp->parent = new_right_node;
	}

	return (new_right_node);
}
