// I used the textbook and lecture notes to complete this lab assignment.
#include <iostream>
using namespace std;

// heap sort is an efficient algorithm that converts an array into a heap
// a heap is an array that represents a binary tree with special properties
// these special properties are relevant to two kinds of heaps: max-heaps and min-heaps
// for this lab, we used a max-heap which has one property: the parent node has 
// nodes as a child or children (of up to two only) where the parent node is greater
// than both child nodes. Due to the recursive nature of trees, this condition is valid
// amongst its children as well, until they reach the bottom of the tree which are
// trivially max-heaps (single nodes).

// to convert an array into a max-heap, we call the max-heapify function. This swaps
// certain nodes accordingly to fulfill the max-heap property. Afterwards, we can
// perform the heap-sort algorithm to sort the array in place! In place means we do
// not even make another array or anything, just sort it in place.

// time complexity: O(nlgn)
// space complexity: O(1)

// helper functions
int get_parent(int index) {
    return (index - 1) / 2;
}

int get_left_child(int index) {
    return 2 * index + 1;
}

int get_right_child(int index) {
    return 2 * index + 2;
}

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// max-heapify
void max_heapify(int arr[], int index, int heap_size) {
    int left = get_left_child(index);
    int right = get_right_child(index);
    int largest = index;

    if (left <= heap_size && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right <= heap_size && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != index) {
        swap(arr, index, largest);
        max_heapify(arr, largest, heap_size);
    }
}

// build-max-heap
void build_max_heap(int arr[], int heap_size) {
    int parent = get_parent(heap_size);

    for (int i = parent; i >= 0; i--) {
        max_heapify(arr, i, heap_size);
    }
}

// heap-sort
void heap_sort(int arr[], int heap_size) {
    build_max_heap(arr, heap_size - 1);

    for (int i = heap_size - 1; i > 0; i--) {
        swap(arr, 0, i);
        max_heapify(arr, 0, i - 1);
    }
}

int main() {

    int size;
    cin >> size;

    int arr[size];
    
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    heap_sort(arr, size);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << ';';
    }

    return 0;
}