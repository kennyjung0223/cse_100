// I used the lectures notes.

#include <iostream>

using namespace std;

int cut_rod(int prices[], int size) {
    int r[size + 1];
    int s[size + 1];
    int n = size;

    r[0] = 0;

    for (int i = 1; i <= size; i++) {
        int q = -1;
        for (int j = 1; j <= i; j++) {
            if (q < prices[j - 1] + r[i - j]) {
                q = prices[j - 1] + r[i - j];
                s[i] = j;
            }
        }
        r[i] = q;
    }

    cout << r[n] << endl;

    while (n > 0) {
        cout << s[n] << " ";
        n -= s[n];
    }
    cout << -1 << endl;

    return r[size];
}

int main() {

    int size;
    cin >> size;

    int prices[size];

    for (int i = 0; i < size; i++) {
        cin >> prices[i];
    }

    int max_revenue = cut_rod(prices, size);

    return 0;
}