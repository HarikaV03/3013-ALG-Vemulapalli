#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

class Bst {
private:
    Node *root;

    // Function to insert a value into the BST
    void _insert(Node *&sub_root, int x) {
        if (sub_root == nullptr) {
            sub_root = new Node(x);
        } else {
            if (x < sub_root->data) {
                _insert(sub_root->left, x);
            } else {
                _insert(sub_root->right, x);
            }
        }
    }

    // Function to print the BST in descending order
    void _print(Node *root) {
        if (!root) {
            return;
        }
        _print(root->right);
        cout << root->data << " ";
        _print(root->left);
    }
    
    // Find the smallest value in the right subtree
    // also can use largest value in the left subtree
    Node* _findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    
    // Function to delete a node from the BST
    Node* _delete(Node* sub_root, int x) {
        if (sub_root == nullptr) return sub_root;
        
        if (x < sub_root->data) {
            sub_root->left = _delete(sub_root->left, x);
        } else if (x > sub_root->data) {
            sub_root->right = _delete(sub_root->right, x);
        } else {
            // Case 1: No children
            if (sub_root->left == nullptr && sub_root->right == nullptr) {
                delete sub_root;
                return nullptr;
            }
            // Case 2: One child
            else if (sub_root->left == nullptr) {
                Node* temp = sub_root->right;
                delete sub_root;
                return temp;
            } else if (sub_root->right == nullptr) {
                Node* temp = sub_root->left;
                delete sub_root;
                return temp;
            }
            // Case 3: Two children
            else {
                Node* temp = _findMin(sub_root->right);
                sub_root->data = temp->data;
                sub_root->right = _delete(sub_root->right, temp->data);
            }
        }
        return sub_root;
    }

public:
    Bst() { root = nullptr; }

    void insert(int x) {
        _insert(root, x);
    }
    
    void deleteNode(int x) {
        root = _delete(root, x);
    }
    
    void print() { _print(root); }
};

int main() {
    cout << "Hello World!\n";
    Bst tree;
    
    // Insert random values
    tree.insert(42);
    tree.insert(17);
    tree.insert(88);
    tree.insert(5);
    tree.insert(23);
    tree.insert(76);
    tree.insert(97);
    
    cout << "BST before deleting: ";
    tree.print();
    cout << endl;
    
    // Delete a random node
    tree.deleteNode(17);
    
    cout << "BST after deleting 11: ";
    tree.print();
    cout << endl;
}

