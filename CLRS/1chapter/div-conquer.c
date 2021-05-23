
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

// NOTE: Divide And Conquer
// recursively solve the problem, and at each recursive stage, do 3 steps:
// - Divide: problem -> subproblem : smaller instances of the same problem
// - Conquer : recursively solve the subproblems. If the subprogram is small enough, solve the problem
// - Combine:  Combine results from each part -> return 1

// 4.1 Maximum Subarray Program
// Pseudo Code:
// FinaMaxCrossing (A, low, mid, high)
// leftsum = -infinity
// sum = 0
// for i = mid downto low
//     sum = sum + A[i]
//     if sum > leftsum
//        leftsum = sum
//        max-left = i
// rightsum = -infinity
// sum = 0
// for j = mid + 1 to high
//     sum = sum + A[j]
//     if sum > rightsum
//         rightsum = sum
//         max-right = j
// return (max-left, max-right, leftsum + rightsum);

struct ret {
    int max_left;
    int max_right;
    int sum;
};
struct ret find_max_iterative(int arr[], int low, int mid, int high){
    int max_left, max_right;
    int leftsum = -999999;
    int sum = 0;
    for (int i = mid; i > low; i--){
        sum = sum + arr[i];
        if (sum > leftsum){
            leftsum = sum;
            max_left = i;
        }
    }
    int rightsum = -9999999;
    sum = 0;
    for (int j = mid + 1; j < high; j++){
        sum = sum + arr[j];
        if (sum > rightsum){
            rightsum = sum;
            max_right = j;
        }
    }
    struct ret r;
    r.max_left = max_left;
    r.max_right = max_right;
    r.sum = leftsum + rightsum;
    return r;
}

void print_s(struct ret s){
    printf("%d - %d - %d\n", s.max_left, s.max_right, s.sum);
}

void find_max_recursive(int arr[], int low, int high){
    struct ret r;
    if (high == low){
        printf("");
    }

    return r;
}

int main(){
    int byte_array_dec[20] = {15-20, 22-20, 0-20, 8-20, 19-20, 17-20, 32-20, 11-20, 35-20, 27-20, 29-20, 23-20, 27-20, 14-20, 23-20, 26-20, 12-20, 32-20, 2-20, 31-20};
    struct ret s = find_max_iterative(byte_array_dec, 0, 11, 20);
    print_s(s);
}
