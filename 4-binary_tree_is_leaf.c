#include "binary_trees.h"

/**
 * binary_tree_is_leaf - a function that checks if a node is a leaf
 * @node: Pointer to the node of the tree to check
 *
 * Return: 0 if node is NULL or the node isn't leaf, 1 if the node is leaf
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (!node->left && !node->right)
		return (1);
	else
		return (0);
}
