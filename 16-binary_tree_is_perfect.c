#include "binary_trees.h"
#include <stdio.h>

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
	size_t left_depth = 0;
	size_t right_depth = 0;

	if (!tree)
		return (0);

	printf("%d\n", binary_tree_is_full(tree));
	
	if (binary_tree_is_full(tree) == 0)
		return (0);

	height = binary_tree_height(tree);
	printf("Tree height: %ld\n", height);

	if (tree->left)
	{
		left_depth = binary_tree_depth(tree->left);
		printf("Left depth: %ld\n", left_depth);
	}
		
	if (tree->right)
	{
		right_depth = binary_tree_depth(tree->right);
		printf("Right depth: %ld\n", right_depth);
	}

	if ((height == left_depth) && (height == right_depth))
		return (1);
	else
		return (0);
}
