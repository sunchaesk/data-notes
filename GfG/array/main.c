

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//// NOTE
// Array is continuous array structure
// -- Can't resize the array
// -- Has O(1) data access by index

////////////////////////////////////////////////////
//////////////   ARRAY ROTATIONS //////////////////
//////////////////////////////////////////////////
// What is array rotation?
// Moving the array by left or right...
// eg a1 = {1, 2, 3, 4, 5};
// -> after rotation: a2 = {3, 4, 5, 1, 2};
void leftRotateByOne(int arr[], int n)
    // arr is array
    // n is size of array
{
    int temp = arr[0], i;
    for (i = 0; i < n - 1; i++){
        arr[i] = arr[i + 1];
    }
    arr[n-1] = temp;
}
void leftRotate(int arr[], int d, int n)
    // d is the amount of rotation
{
    int i;
    for (i = 0; i < d; i++)
        leftRotateByOne(arr, n);
}
/////////////////////////////////////////////////////////

int main (){

}
