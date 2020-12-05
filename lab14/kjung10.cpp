#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int freq;
    int index;
    char bit;
    Node* left;
    Node* right;

    Node(int freq, int index, char bit, Node* left = nullptr, Node* right = nullptr) {
        this->freq = freq;
        this->index = index;
        this->bit = bit;
        this->left = left;
        this->right = right;
    }  
};

struct compare {
    bool operator()(Node* lhs, Node* rhs) {
        if (lhs->freq == rhs->freq) {
            if (lhs->index == -1) {
                return lhs->left->index > rhs->index;
            }
            else if (rhs->index == -1) {
                return lhs->index > rhs->left->index;
            }
            return lhs->index > rhs->index;
        }
        return lhs->freq > rhs->freq;
    }
};

Node* huffman(vector<int> freqs) {
    Node *z, *left, *right;
    priority_queue<Node*, vector<Node*>, compare> q;

    for (int i = 0; i < freqs.size(); i++) {
        q.push(new Node(freqs[i], i, '*'));
    }

    for (int i = 1; i < freqs.size(); i++) {
        left = q.top();
        left->bit = '0';
        q.pop();

        right = q.top();
        right->bit = '1';
        q.pop();

        z = new Node(left->freq + right->freq, -1, '*', left, right);
        q.push(z);
    }

    return q.top();
}

void print_huffman(Node* h_node, int i, string s) {
    if (h_node != nullptr) {
        if (h_node->index == i) {
            s += h_node->bit;
            cout << s << endl;
            return;
        }
        else {
            if (h_node->bit != '*') {
                s += h_node->bit;
            }
            print_huffman(h_node->left, i, s);
            print_huffman(h_node->right, i, s);
        }
    }
}

void print_codes(Node* h_tree, int n) {
    for (int i = 0; i < n; i++) {
        print_huffman(h_tree, i, "");
    }
}

int main() {

    int n;
    cin >> n;

    vector<int> freqs;

    for (int i = 0; i < n; i++) {
        int freq;
        cin >> freq;
        freqs.push_back(freq);
    }

    Node* h = huffman(freqs);

    print_codes(h, n);

    return 0;
}

