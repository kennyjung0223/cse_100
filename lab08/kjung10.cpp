// I used the lecture notes and this website: https://www.geeksforgeeks.org/list-cpp-stl/
// I used the website mentioned above to understand how to use the lists in STL
// In particular, I used sort() and merge() to finish this lab assignment

#include <iostream>
#include <vector>
#include <list>

using namespace std;

void bucket_sort(float arr[], int size) {
    // initialize a vector of lists, a flattened list for our concatenation, and an index pointer to actually sort arr
    vector< list<float> > temp(size);
    list<float> flattened;
    int i = 0;

    // essentially index serves as a hash function and we put the value of arr into a list which is at the position of our hash value
    // for the vector
    for (int i = 0; i < size; i++) {
        int index = size * arr[i];
        temp[index].push_back(arr[i]);
    }
    // sort each list in ascending order
    for (int i = 0; i < temp.size(); i++) {
        temp[i].sort();
    }
    // "flatten" all the lists into one consecutive list
    for (int i = 0; i < temp.size(); i++) {
        flattened.merge(temp[i]);
    }
    // access each value in our flattened list and set the values accordingly
    // we can do this since our flattened list will guaranteed be a sorted list
    for (auto it = flattened.begin(); it != flattened.end(); it++) {
        arr[i] = *it;
        i++;
    }
}

int main() {
    int size;
    cin >> size;

    float arr[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    bucket_sort(arr, size);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
}