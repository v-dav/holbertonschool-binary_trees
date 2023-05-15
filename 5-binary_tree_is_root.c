#include "binary_trees.h"

/**
 * binary_tree_is_root - a function that checks if a node is a root
 * @node: Pointer to the node of the tree to check
 *
 * Return: 0 if node is NULL or isn't root, 1 if is root
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (node->parent)
		return (0);
	else
		return (1);

}
