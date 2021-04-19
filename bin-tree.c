
#include <stdio.h>
#include <stdlib.h>

/*
 *Binary Tree:
 * Basic Operations:
 * - Search
 * - Traversal
 * - Insertion
 * - Deletion
 */

typedef struct tree {
    int item;
    struct tree *parent;
    struct tree *right;
    struct tree *left;
} tree;

// Left node of tree is lower, while right is greater
// Steps:
// Look at tree, if item == x, return tree
// If not, if x < item, recurse using the left part of the tree
// else if x > item, recurse using the right part of the tree
//
// Runtime: O(h) where: h = height of the bin tree
tree* search_tree(tree *l, int x){
    if (l == NULL) return NULL;

    if (l->item == x) return l;

    if (x < l->item)
        return search_tree(l->left, x);
    else
        return search_tree(l->right, x);
}
