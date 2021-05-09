
#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "bool.h"

int partition (int s[], int l, int h){
    int i;
    int p;
    int firsthigh;

    p = h;
    firsthigh = l;
    for (i = l; i < h; i++)
        if (s[i] < s[p]){
            // swap(&s[i], &s[firsthigh]);
            firsthigh ++;
        }
    // swap(&s[p], &s[firsthigh]);
    return firsthigh;
}

void quicksort(int s[], int l, int h){
    int p;

    if ((h-l) > 0){
        p = partition(s, l, h);
        quicksort(s, l, p-1);
        quicksort(s, p+1, h);
    }
}

int main() {

}

// If choose median, the worst case is O(n^2), but average
// case of O(n log n)
// better & more robust method is to randomize pivot
// average case & worse case O(n log n)
// - with high probability
