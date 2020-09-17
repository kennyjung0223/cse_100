// I used the textbook and lecture notes to complete this lab assignment.
// runtime complexity: big theta(nlgn), space complexity: big theta(n) due to auxiliary space

#include <iostream>
using namespace std;

// Merge sort is an efficient sorting algorithm that uses the concept of divide and conquer. This means by nature,
// merge sort can be solved recursively. Essentially, the idea is to divide the problem into subproblems and use those
// subproblems to solve the whole problem. Our base case would be when your subproblem has 1 element, since that means
// the subproblem is already sorted. After you have divided up your subproblems, you will start conquering and combining.
// With merge sort, we build an auxiliary array that stores enough elements for the two subproblems we are merging combined.
// The two subproblems are arrays that we divided and will compare each element to build our auxiliary array, which as a result,
// will be sorted. We continue to combine as such until the whole list is completed. The result will be a sorted list of items.

// the conquer and combining part of the algorithm
void merge(int arr[], int low, int mid, int high) {
    // calculate the sizes for our left partition and our right partition
    int size_1 = mid - low + 1;
    int size_2 = high - mid;

    // build our auxiliary arrays with the size of each partition + 1
    // we + 1 since we account for sentinels, which we add at the end and take into consideration is 'infinity'
    // we have sentinels because without them, our last comparison for conquering and combining means
    // we leave out the highest value. We want to make sure all of the values are taken into consideration,
    // so we use sentinels to ensure the last and highest value is taken into consideration.
    int L[size_1 + 1];
    int R[size_2 + 1];

    for (int i = 0; i < size_1; i++) {
        // build the left partition array
        L[i] = arr[low + i];
    }

    for (int j = 0; j < size_2; j++) {
        // build the right partition array
        R[j] = arr[mid + j + 1];
    }

    // setting our sentinels
    L[size_1] = INT_MAX;
    R[size_2] = INT_MAX;

    int i = 0;
    int j = 0;

    for (int k = low; k <= high; k++) {
        // conquer part
        if (L[i] < R[j]) {
            // combine part
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
    }
}

// the divide part of the algorithm
void merge_sort(int arr[], int low, int high) {
    // our low and high represents our boundaries
    // not low <= high since low == high means we are at the base case already, which is don't divide further
    if (low < high) {
        // calculate the mid so we can keep dividing the list evenly
        int mid = low + (high - low) / 2;

        // make our recursive calls that divide
        merge_sort(arr, low, mid);
        // we have to continue dividing both partitions, so we keep dividing the right portion as well
        merge_sort(arr, mid + 1, high);
        // after we successfully divided, we merge (conquer and combine)
        merge(arr, low, mid, high);
    }
}

int main() {

    int size;
    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    merge_sort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << ";";
    }

    return 0;
}