//implementation of Binary search tree with delete function
#include <iostream>

using namespace std;

// BST node of data and pointers to children
struct Node {
    int data;        // Data stored in the node
    Node *left;      // Pointer to left child
    Node *right;     // Pointer to right child

    Node(int x) {    // Constructor to initialize node
        data = x;
        left = right = nullptr;
    }
};

// Class for insert, delete, and print operations
class Bst {
private:
    Node *root;      // root node of the BST

    // To insert a value into the BST
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

    // To print the BST in descending order
    void _print(Node *root) {
        if (!root) {
            return;
        }
        _print(root->right);
        cout << root->data << " ";
        _print(root->left);
    }
    
    // For deletion:It finds the smallest value in the right subtree
    // also can use largest value in the left subtree
    Node* _findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    
    // Deletion handles 3 cases:
    // 1. No children   2. One child   3. Two children
    Node* _delete(Node* sub_root, int x) {
        if (sub_root == nullptr) return sub_root;
        
        // search for node
        if (x < sub_root->data) {
            sub_root->left = _delete(sub_root->left, x);    // delete from left
        } else if (x > sub_root->data) {
            sub_root->right = _delete(sub_root->right, x);  // delete from right
        } else {
            // found the node to delete
            // Case 1: No children (leaf node) - just delete
            if (sub_root->left == nullptr && sub_root->right == nullptr) {
                delete sub_root;
                return nullptr;
            }
            // Case 2: One child - connect parent to child
            else if (sub_root->left == nullptr) {
                Node* temp = sub_root->right;
                delete sub_root;
                return temp;
            } else if (sub_root->right == nullptr) {
                Node* temp = sub_root->left;
                delete sub_root;
                return temp;
            }
            // Case 3: Two children - replace with the smallest from the right subtree
            else {
                Node* temp = _findMin(sub_root->right);
                sub_root->data = temp->data;
                sub_root->right = _delete(sub_root->right, temp->data);
            }
        }
        return sub_root;
    }

public:
    // Constructor: creates an empty BST
    Bst() { root = nullptr; }
    
    // inserts a value
    void insert(int x) {
        _insert(root, x);
    }
    
    // deletes a node
    void deleteNode(int x) {
        root = _delete(root, x);
    }
    
    // prints all nodes
    void print() { _print(root); }
};

int main() {
    cout << "Hello World!\n";
    Bst tree;
    
    // Insert values into BST
    tree.insert(8);
    tree.insert(3);
    tree.insert(1);
    tree.insert(11);
    tree.insert(7);
    tree.insert(15);
    
    cout << "BST before deleting: ";
    tree.print();
    cout << endl;
    
    // Delete a random node(value)
    tree.deleteNode(11);
    
    cout << "BST after deleting 11: ";
    tree.print();
    cout << endl;
}
