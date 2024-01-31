#include "binary_trees.h"
/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{       
        binary_tree_t *anc_mom, *anc_dad;
	
	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	anc_mom = first->parent, anc_dad = second->parent;
	if (first == anc_dad || !anc_mom || (!anc_mom->parent && anc_dad))
		return (binary_trees_ancestor(first, anc_dad));
	else if (anc_mom == second || !anc_dad || (!anc_dad->parent && anc_mom))
		return (binary_trees_ancestor(anc_mom, second));
	return (binary_trees_ancestor(anc_mom, anc_dad));
}
