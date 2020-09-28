#include <iostream>
using namespace std;

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