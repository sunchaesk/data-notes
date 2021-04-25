// Sorting
// - Basic building block of various algorithms
// - historically spent more time sorting than anything else

// Applications of Sorting:
// - Searching
// - Pair with the smallest diff
// - Element uniqueness
// - Frequency distribution
// - kth largest element
// - Convex hull
//       What is the polygon of smallest area that has set of n points in a given dimension


#include <stdlib.h>
#include <stdio.h>
// qsort
// void qsort(void *base, size_t nel, size_t width,
//            int (*compare) (const void *, const void *));
int intcompare(int *i, int *j)
{
    if (*i > *j) return 1;
    if (*i < *j) return -1;
    return 0;
}
// eg function to use in qsort


// Heapsort
// - Has 2 steps:
//     - Organizing the data into the heap data structure O(log n)
//     - extracting the top node each time and storing them into the array (will be sorted) O(n)
//
// STEP1:  Unsorted array -> heap (balanced binary tree)
// if max-heap: Parent has to be bigger than the children nodes
// - elements are added from the left most available space, and if newly added doesn't make the ds a heap -> recursively sort the heap
//
// STEP2: extracting node each time -> sorted array
// extract all elements (n sized) and fill them up from the back
// when extracted:
//      the head will be empty, so you have to fill the head from the rightmost node

