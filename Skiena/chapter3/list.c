
/*
 *  Why List? (Linked List):
 *  - No Overflow (dynamic memory allocation)
 *  - Simpler insertion and deletion
 *  - Larger records, moving pointers is easier than moving the items itself
 *  Why Arrays (Static sized storage):
 *  - Linked structs, require extra space for storing pointers
 *  - Linked, do not allow efficient random access
 *  - Arrays -> better mem locality an cache performance
 *
 *  NOTE
 *  - Lists and Arrays are both recursive objects...
 *  If you cut both arrays and lists, you get smaller sized same struct.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int item;
    struct list *next;
} list;

list *search_list(list *l, int x){
    if (l == NULL) return NULL;

    if (l->item == x) return l;
    else return(search_list(l->next, x));
}

void insert_list(list **l, int x){
    list *p;
    p = malloc(sizeof(list));
    p->item = x;
    p->next = *l;
    *l = p;
}

list *predecessor_list(list *l, int x){
    if ((l == NULL) || (l->next == NULL)){
        printf("Error\n");
        return (NULL);
    }
    if ((l->next)->item == x)
        return (l);
    else
        return predecessor_list(l->next, x);
}

void delete_list(list **l, int x){
    list *p;
    list *pred;
    list *search_list(), *predecessor_list();

    p = search_list(*l, x);
    if (p != NULL){
        pred = predecessor_list(*l, x);
        if (pred == NULL)
            *l = p->next;
        else
            pred->next = p->next;
        free(p);
    }
}

