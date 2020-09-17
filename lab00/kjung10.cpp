// I used the textbook and lecture notes to complete this lab assignment.

#include <iostream>

using namespace std;

// time complexity: O(n), space complexity: O(1); O = big theta
void insertion_sort(int A[], int size) {
    for (int i = 1; i < size; i++) {
        // we start at i = 1 because the idea of insertion sort is every element on the left side is sorted
        // so when we start with 1 item on the left side, it is already sorted in place, so we can move to the next element
        // key is the element that we wish to find its sorted location
        int key = A[i];
        // we want to start looking before the key, so we initialize a pointer that is before the i pointer
        int j = i - 1;

        // break the loop if the j pointer goes past 0 or if we have found a good spot for key
        while (j >= 0 && A[j] < key) {
            // in essence, bubble up the lower values and keep going left with the j pointer
            A[j + 1] = A[j];
            j--;
        }
        // the good spot for key is at index j + 1
        A[j + 1] = key;
    }
}

int main() {
    
    int size;
    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    insertion_sort(arr, size);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << ';';
    }

    return 0;
}