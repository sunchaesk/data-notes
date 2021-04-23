
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


// Finding max and min
// If max -> just go to the rightmost tree node
// vice versa for min
tree* find_minimum(tree *t){
    tree* min;

    if (t == NULL) return NULL;

    min = t;
    while (min->left != NULL)
        min = min->left;
    return min;
}

// Traversal - visiting all nodes in the binary tree
void traverse_tree(tree *l){
    while(l != NULL){
        traverse_tree(l->left);
        //process_item(l->item);
        traverse_tree(l->right);
    }
}

// Insert Node to bin tree
void insert_tree(tree **l, int x, tree *parent){
    tree *p;
    if (*l == NULL){
        p = malloc(sizeof(tree));
        p->item = x;
        p->left = p->right = NULL;
        p->parent = parent;
        *l = p;
        return;
    }
    if (x < (*l)->item)
        insert_tree(&((*l)->left), x, *l);
    else
        insert_tree(&((*l)->right), x, *l);
}
