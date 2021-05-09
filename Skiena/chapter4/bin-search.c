
#include <stdlib.h>
#include <stdio.h>

int binary_search(int s[], int key, int low, int high){
    int middle; // i mid element
    if (low > high) return -1; // key not found
    middle = (low + high) / 2;

    if (s[middle] == key) return middle;
    if (s[middle] > key)
        return (binary_search(s, key, low, middle-1));
    else
        return (binary_search(s, key, middle+1, high));
}
