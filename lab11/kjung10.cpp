#include <iostream>
#include <string>

using namespace std;

struct Node {
    Node* parent;
    Node* left;
    Node* right;
    int val;

    Node() {
        parent = nullptr;
        left = nullptr;
        right = nullptr;
        val = 0;
    }

    Node(int val) {
        parent = nullptr;
        left = nullptr;
        right = nullptr;
        this->val = val;
    }
};

Node* T = nullptr;

void inorder(Node* temp) {
    if (temp) {
        inorder(temp->left);
        cout << temp->val << endl;
        inorder(temp->right);
    }
}

void preorder(Node* temp) {
    if (temp) {
        cout << temp->val << endl;
        preorder(temp->left);
        preorder(temp->right);
    }
}

void postorder(Node* temp) {
    if (temp) {
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->val << endl;
    }
}

void insert(Node* z) {
    Node* y = nullptr;
    Node* x = T;

    while (x) {
        y = x;

        if (x->val > z->val) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }
    z->parent = y;

    if (y == nullptr) {
        T = z;
    }
    else if (y->val > z->val) {
        y->left = z;
    }
    else {
        y->right = z;
    }
}

Node* tree_minimum(Node* root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

Node* search(Node* temp, int val) {
    if (!temp) {
        return nullptr;
    }
    else if (temp->val == val) {
        return temp;
    }
    else if (temp->val > val) {
        return search(temp->left, val);
    }
    else {
        return search(temp->right, val);
    }
}

void transplant(Node* u, Node* v) {
    if (u->parent == nullptr) {
        T = v;
    }
    else if (u == u->parent->left) {
        u->parent->left = v;
    }
    else {
        u->parent->right = v;
    }
    if (v != nullptr) {
        v->parent = u->parent;
    }
}

void delete_node(Node* temp, int z_val) {
    Node* z = search(temp, z_val);

    if (z != nullptr) {
        if (z->left == nullptr) {
            transplant(z, z->right);
        } 
        else if (z->right == nullptr) {
            transplant(z, z->left);
        }
        else {
            Node* y = tree_minimum(z->right);

            if (y->parent != z) {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
        }
    } 
}

int main() {

    string s;
    getline(cin, s);

    while (s[0] != 'e') {
        if (s.substr(0,2) == "in") {
            Node* temp = T;
            inorder(temp);
            cout << "++++++++++++++++++++" << endl;
        }
        else if (s.substr(0,3) == "pre") {
            Node* temp = T;
            preorder(temp);
            cout << "++++++++++++++++++++" << endl;
        }
        else if (s.substr(0,4) == "post") {
            Node* temp = T;
            postorder(temp);
            cout << "++++++++++++++++++++" << endl;
        }
        else if (s[0] == 'i') {
            Node* z = new Node(stoi(s.substr(2, s.length() - 1)));
            insert(z);
        }
        else if (s[0] == 'd') {
            Node* temp = T;
            int z_val = stoi(s.substr(2, s.length() - 1));
            delete_node(temp, z_val);
        }
        getline(cin, s);
    }

    return 0;
}