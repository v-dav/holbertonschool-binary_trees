#include "binary_trees.h"

/**
 * binary_tree_leaves - a function that counts the leaves in a binary tree
 * @tree: is a pointer to the root node of the tree
 * to count the number of leaves
 *
 * Return: the number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t nb = 0;

	if (!tree)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		nb++;

	nb += binary_tree_leaves(tree->left);
	nb += binary_tree_leaves(tree->right);

	return (nb);
}
