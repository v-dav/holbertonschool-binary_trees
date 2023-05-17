#include "binary_trees.h"

/**
 * binary_tree_height - a function that measures
 * the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height
 *
 * Return: the height of the node
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);

	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
}

/**
 * binary_tree_balance - a function that measures
 * the balance factor of a binary tree
 * @tree: is a pointer to the root node of the tree
 * to measure the balance factor
 *
 * Return: the balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_height = -1;
	size_t right_height = -1;

	if (!tree)
		return (0);

	if (tree->left)
		left_height = binary_tree_height(tree->left);

	if (tree->right)
		right_height = binary_tree_height(tree->right);

	return (left_height - right_height);
}

/**
 * binary_tree_is_full - a function that checks if a binary tree is full
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: 1 if full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int full = 1;

	if (!tree)
		return (0);

	if ((tree->left && !tree->right) || (!tree->left && tree->right))
		return (0);

	if (tree->left)
		full = full && binary_tree_is_full(tree->left);

	if (tree->right)
		full = full && binary_tree_is_full(tree->right);

	return (full);
}

/**
 * binary_tree_is_perfect - a function that checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = 0;
	size_t left_height = 0;
	size_t right_height = 0;

	if (!tree)
		return (0);

	if (!binary_tree_is_full(tree))
		return (0);

	height = binary_tree_height(tree);

	if (tree->left)
		left_height = binary_tree_height(tree->left);
	if (tree->right)
		right_height = binary_tree_height(tree->right);

	if ((height == left_height) && (height == right_height))
		return (1);
	else
		return (0);
}
