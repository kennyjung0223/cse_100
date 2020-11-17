#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void print(vector<vector <int>> s, int i, int j) {
    if (i == j) {
        cout << "A" << i - 1;
    }
    else {
        cout << "(";
        print(s, i, s[i][j]);
        print(s, s[i][j] + 1, j);
        cout << ")";
    }
}

void matrix_chain_order(vector<int> p) {
    int n = p.size() - 1;

    vector<vector <int>> m(n + 1, vector<int>(n + 1));
    vector<vector <int>> s(n + 1, vector<int>(n + 1));

    for (int l = 2; l < n + 1; l++) {
        for (int i = 1; i < n - l + 2; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << m[1][n] << endl;
    print(s, 1, n);
}

int main() {

    int size;
    cin >> size;

    vector<int> p(size + 1);

    for (int i = 0; i < size + 1; i++) {
        cin >> p[i];
    }

    matrix_chain_order(p);

    return 0;
}