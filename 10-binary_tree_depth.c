#include "binary_trees.h"

/**
 * binary_tree_depth - a function that measures
 * the depth of a nod of a binary tree
 * @tree: a pointer to the node to measure the depth
 *
 * Return: the node's depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	int depth = 0;

	if (!tree)
		return (0);

	if (tree->parent)
		depth = binary_tree_depth(tree->parent) + 1;

	return (depth);
}
