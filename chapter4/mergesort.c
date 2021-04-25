
// Mergesort
// Runs in complexity of O(n log n)
#include "priority_queue.c"

void merge(int s[], int low, int middle, int high){
    int i;
    priority_queue buffer1, buffer2;

    pq_init(&buffer1);
    pq_init(&buffer2);

    for (i=low; i <= middle; i++) pq_insert(&buffer1, s[i]);
    for (i=middle+1; i <= high; i++) pq_insert(&buffer2, s[i]);

    i = low;
    while(!(empty_pq(&buffer1) || empty_pq(&buffer2))){
        if (headq(&buffer1) <= headq(&buffer2))
            s[i++] = extract_min(&buffer1);
        else
            s[i++] = extract_min(&buffer2);
    }
    while(!empty_pq(&buffer1)) s[i++] = extract_min(&buffer1);
    while(!empty_pq(&buffer2)) s[i++] = extract_min(&buffer2);
}
void mergesort(int s[], int low, int high){
    // int i;
    int middle;

    if (low < high){
        middle = (low + high)/2;
        mergesort(s, low, middle);
        mergesort(s, middle + 1, high);
        merge(s, low, middle, high);
    }
}

// Other implementation
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
