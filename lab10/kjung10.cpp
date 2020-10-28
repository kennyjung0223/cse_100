#include <iostream>
#include <vector>

using namespace std;

int hash_1(int key) {
    return key % 13;
}

int hash_2(int key) {
    return 1 + (key % 11);
}

int hash_function(int key, int i) {
    return (hash_1(key) + i * hash_2(key)) % 13;
}

void insert(vector<int> &table, int value) {
    for (int i = 0; i < 13; i++) {
        int key = hash_function(value, i);

        if (table[key] == -4) {
            table[key] = value;
            break;
        }
    }
}

void search(vector<int> &table, int value) {
    for (int i = 0; i < 13; i++) {
        int key = hash_function(value, i);

        if (table[key] == -4) {
            cout << "NOT_FOUND" << endl;
            return;
        }
        else if (table[key] == value) {
            cout << key << endl;
            return;
        }
    }
    cout << "NOT_FOUND" << endl;
}

void delete_val(vector<int> &table, int value) {
    for (int i = 0; i < 13; i++) {
        int key = hash_function(value, i);

        if (table[key] == value) {
            table[key] = -4;
            return;
        }
    }
}

void print(vector<int> &table) {
    for (int i = 0; i < 13; i++) {
        if (table[i] == -4) {
            cout << " " << endl;
        }
        else {
            cout << table[i] << endl;
        }
    }
}

int main() {

    int num;
    int m = 13;

    bool inserting = true;
    bool searching = false;
    bool deleting = false;

    vector<int> table(m, -4);

    while (inserting || searching || deleting) {
        cin >> num;
        if (num == -1) {
            inserting = false;
            searching = true;
            cout << "++++table printout++++" << endl;
            print(table);
            cout << "++++searching++++" << endl;
        }
        else if (inserting) {
            insert(table, num);
        }
        else if (num == -2) {
            searching = false;
            deleting = true;
            cout << "++++deleting++++" << endl;
        }
        else if (searching) {
            search(table, num);
        }
        else if (num == -3) {
            deleting = false;
            cout << "++++table printout++++" << endl;
            print(table);
        }
        else if (deleting) {
            delete_val(table, num);
        }
    }

    return 0;
}