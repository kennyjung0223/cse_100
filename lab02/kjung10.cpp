// I used the textbook and lecture notes to complete this lab assignment.

#include <iostream>
using namespace std;

// time complexity: O(lgn), space complexity: O(1); O = big theta
int binary_search(int arr[], int key, int left, int right) {
    // binary search is an efficient algorithm where we continuously split the array to search for the key
    // we first have to sort the array (and in this case, ascending order) to perform binary search
    // the idea behind binary search is we start by accessing the lowest element and the highest element
    // from there, we can also calculate the middle element knowing the locations of our lowest and highest elements
    // we check the element in the middle to see if it matches the key, if so, return that index
    // otherwise, the middle element is either less than or greater than the key value, if it is less than the key,
    // we know that the key has to be to the right of the middle element (since our array is sorted in ascending order)
    // we can change our left position to be middle + 1 so we start looking at the right portion of the array
    // if the middle element was greater than the key, then the key must be in the left portion of the array
    // so we change the right position to middle - 1, we keep searching in these smaller portions until
    // the position of left is greater than the position of right, which means left and right crossed each other
    // so we cannot search any further, we would return -1 as our index output if the key was not found
    while (left <= right) {
        // iterating throughout the array while left is not greater than right
        int mid = left + (right - left) / 2;
        // mid is calculated as such to prevent integer overflow

        if (arr[mid] == key)
            // check if the middle element is a match
            return mid;
        else if (arr[mid] < key)
            // otherwise check if the middle element is less than the key (right portion of the array)
            left = mid + 1;
        else
            // this case means we should search in the left portion of the array
            right = mid - 1;
    }
    // element not found so return -1
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

    int index = binary_search(arr, key, 0, size - 1);

    cout << index << endl;

    return 0;
}