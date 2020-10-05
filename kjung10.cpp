// I was familiar with a different implementation of quick sort that I
// understood far better than the implementation Professor Carreira-Perpinan
// provided us. It is still divide and conquer, but it also uses while loops
// and a randomized pivot. The time complexity is still O(nlgn) on average,
// O(n^2) worst case. Worst case occurs when the array is already sorted.

#include <iostream>
using namespace std;

// swap helper function
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void quick_sort(int arr[], int left, int right) {
    // create instances of left and right pointers as we will need
    // left and right later as bounds when we divide
    // our pivot is an element in the array between the left and right bounds
    int i = left;
    int j = right;
    int pivot = arr[rand() % (right - left) + left];

    // the idea is to swap all items in such a way where we end up with
    // items less than the pivot to the left and items greater than the pivot
    // to the right

    // when we cross i and j, that is when we stop comparing
    while (i <= j) {
        // keep incrementing i if the element is less than pivot 
        while (arr[i] < pivot) {
            i++;
        }
        // keep decrementing j if the element is greater than pivot
        while (arr[j] > pivot) {
            j--;
        }
        // if we made it this far, we know that our arr[i] and arr[j] are in
        // the wrong partitions of our array, so we make a swap on both of them
        // and keep moving forward with our algorithm until i crosses j
        // i crossing j means we should not make more comparisons otherwise we
        // break our rule of partitioning
        if (i <= j) {
            swap(arr, i, j);
            i++;
            j--;
        }
    }
    // we're still not over yet, we want to keep sorting the items in our partitions
    // first check if left is less than j, and we can sort that partition if so
    // same idea goes with i less than right

    // we won't execute this call if we have one element left, which is trivially sorted
    if (left < j) {
        quick_sort(arr, left, j);
    }
    if (i < right) {
        quick_sort(arr, i, right);
    }
}

int main() {

    int size;
    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    quick_sort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << ";";
    }

    return 0;
}