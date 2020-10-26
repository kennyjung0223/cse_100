// I used https://www.geeksforgeeks.org/list-cpp-stl/ for using lists. I also used geeksforgeeks to look up substr for strings
// I used iterators because I learned them recently in my CSE 165 class, and I find that they would be extremely helpful to use
// for this lab. That way, I do not have to iterate through the linked list twice where the first time I would track how many
// elements are in the linked list. With the iterators, I can iterate through the linked list only once.

// I also solved a hash table design problem on LeetCode, so designing this hash table was fairly within my skill expertise.

#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

// hash function to compute keys
int hash_function(int value, int m) {
    return value % m;
}

// insert the value into the hash table
void insert(vector< list<int> > &table, int value, int m) {
    int key = hash_function(value, m);
    table[key].push_front(value);
}

// delete the value in the hash table
void delete_val(vector< list<int> > &table, int value, int m) {
    int key = hash_function(value, m);

    // normal iterator since we modify the linked list
    for (list<int>::iterator it = table[key].begin(); it != table[key].end(); it++) {
        if ((*it) == value) {
            table[key].erase(it);
            cout << value << " : DELETED\n++++++++++++++++++++" << endl;
            return;
        }
    }
    cout << value << " : DELETE FAILED\n++++++++++++++++++++" << endl;
}

// search the value in the hash table
void search(vector< list<int> > &table, int value, int m) {
    int key = hash_function(value, m);
    int count = 0;

    // const_iterator since we promise not to modify the linked list (only searching)
    for (list<int>::const_iterator it = table[key].begin(); it != table[key].end(); it++) {
        if ((*it) == value) {
            cout << value << " : FOUND AT " << key << "," << count << "\n++++++++++++++++++++" << endl;
            return;
        }
        count++;
    }
    cout << value << " : NOT FOUND\n++++++++++++++++++++" << endl;
}

void print(vector< list<int> > &table) {
    for (int i = 0; i < table.size(); i++) {
        cout << i << " : ";
        for (list<int>::const_iterator it = table[i].begin(); it != table[i].end(); it++) {
            if (it != table[i].begin()) {
                cout << "->";
            }
            cout << (*it);
        }
        cout << endl;
    }
    cout << "++++++++++++++++++++" << endl;
}

int main() {

    int m;
    cin >> m;

    vector< list<int> > table(m);

    string s;
    getline(cin, s);

    char operation = s[0];

    while (operation != 'e') {
        if (operation == 'i') {
            // insert
            insert(table, stoi(s.substr(2, s.length() - 1)), m);
        }
        else if (operation == 'd') {
            // delete
            delete_val(table, stoi(s.substr(2, s.length() - 1)), m);
        }
        else if (operation == 's') {
            // search
            search(table, stoi(s.substr(2, s.length() - 1)), m);
        }
        else if (operation == 'o') {
            // output
            print(table);
        }
        getline(cin, s);
        operation = s[0];
    }

    return 0;
}