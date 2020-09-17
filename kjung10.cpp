// I used the textbook and lecture notes to complete this lab assignment.

#include <iostream>
using namespace std;

int linear_search(int arr[], int size, int key) {
    // linear search is a very intuitive searching algorithm that takes in the list of elements and a key
    // in this implementation, we start from left to right, traversing through each element in the list
    // at each element, we compare its value with the key, if there is a match, we return that index, otherwise, we keep searching
    // if we reach the end of the list and did find any match, we return -1 as representative of "the key is not in the list"
    for (int i = 0; i < size; i++) {
        // iterate through the entire array
        if (arr[i] == key) {
            // make comparison with element and key, return the index if there is a match
            return i;
        }
    }
    // return -1 when key is not in the array
    return -1;
}

int main() {

    int size;
    int key;

    cin >> size;
    cin >> key;

    int arr[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int index = linear_search(arr, size, key);

    cout << index << endl;

    return 0;
}