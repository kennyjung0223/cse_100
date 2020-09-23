// I used the textbook and lecture notes to complete this lab assignment.
#include <iostream>
#include<climits>
using namespace std;

int max_cross_subarray(int arr[], int low, int mid, int high) {
    int left_sum = INT_MIN;
    int sum = 0;

    for (int i = mid; i >= low; i--) {
        sum += arr[i];

        if (sum > left_sum) {
            left_sum = sum;
        }
    }

    int right_sum = INT_MIN;
    sum = 0;

    for (int j = mid + 1; j <= high; j++) {
        sum += arr[j];

        if (sum > right_sum) {
            right_sum = sum;
        }
    }

    return left_sum + right_sum;
}

int max_subarray(int arr[], int low, int high) {

    if (low == high) {
        return arr[low];
    }
    
    int mid = low + (high - low) / 2;

    int left_sum = max_subarray(arr, low, mid);
    int right_sum = max_subarray(arr, mid + 1, high);
    int cross_sum = max_cross_subarray(arr, low, mid, high);

    int max_part = max(left_sum, right_sum);
    return max(max_part, cross_sum);
}

int main() {

    int size;
    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int max_subarray_sum = max_subarray(arr, 0, size - 1);
    cout << max_subarray_sum;

    return 0;
}