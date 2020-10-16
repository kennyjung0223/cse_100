// I used to book and lecture notes to complete this lab
// I also referenced some stuff on vectors with this website: http://www.cplusplus.com/reference/vector/vector/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// k = max(arr) + 1 to accommodate for the temp vector size

int find_k(vector< vector<int> > &arr) {
    int k = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < 10; j++) {
            if (arr[i][j] > k) {
                k = arr[i][j];
            }
        }
    }
    return k + 1;
}

void count_sort(vector< vector<int> > &arr, int size, int k, int digit) {
    // using vector constructors: std::vector(count, value = 0), default value = 0
    vector<int> temp (k);
    vector< vector<int> > sorted(size, vector<int>(k));

    for(int i = 0; i < size; i++) {
        temp[arr[i][digit]] += 1;
    }
    for (int i = 1; i < k; i++) {
        temp[i] += temp[i - 1];
    }
    for (int i = size - 1; i >= 0; i--) {
        sorted[temp[arr[i][digit]] - 1] = arr[i];
        temp[arr[i][digit]] -= 1;
    }
    for (int i = 0; i < size; i++) {
        arr[i] = sorted[i];
    }
}

void radix_sort(vector< vector<int> > &arr, int k) {
    for (int i = 9; i >= 0; i--) {
        count_sort(arr, arr.size(), k, i);
    }
}

int main() {

    int size;
    cin >> size;

    vector< vector<int> > arr;

    for (int i = 0; i < size; i++) {
        vector<int> temp;
        for (int j = 0; j < 10; j++) {
            int val;
            cin >> val;
            temp.push_back(val);
        }
        arr.push_back(temp);
    }

    int k = find_k(arr);

    radix_sort(arr, k);

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < 10; j++) {
            cout << arr[i][j] << ";";
        }
        cout << endl;
    }
}
