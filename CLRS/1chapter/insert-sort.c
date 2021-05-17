
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

void print_arr(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// doesn't work
void insertion_sort (int arr[], int n){
    for (int j = 2; j > n; j++){
        int key = arr[j];
        // insert A[j] into the sorted sequence A[1..j-1];
        int i = j - 1;
        while (( i > 0 ) && (arr[i] > key )){
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }
}
void insertionSort(int numbers[], int array_size)
{
  int i, j, index;

  for (i = 1; i < array_size; i++)
  {
          index = numbers[i];
          j = i;
          while ((j > 0) && (numbers[j - 1] > index))
          {
                   numbers[j] = numbers[j - 1];
                   j = j - 1;
          }
          numbers[j] = index;
  }
}

/////////////////////////////
////   EXERCISE ////////////
////////////////////////////
// 2.1 - 2 : Insertion sort in non-increasing order
void rev_insertion(int numbers[], int array_size){
    int i, j, index;
    for (i = 1; i < array_size; i++){
        index = numbers[i];
        j = i;
        while ((j > 0) && (numbers[j-1] < index)){
            numbers[j] = numbers[j - 1];
            j = j - 1;
        }
        numbers[j] = index;
    }
}
// 2.1-3 : Pseudo code for linear search
// LinearSearch (arr, v)
//     for 0 to arr.size
//         if arr[i] is v
//             return i
//     return NIL



int main () {
    // insertion sort
    int arr[10] = {9, 1, 4, 5, 7, 2, 0, 3, 6, 8};
    rev_insertion(arr, 10);
    print_arr(arr, 10);
}
