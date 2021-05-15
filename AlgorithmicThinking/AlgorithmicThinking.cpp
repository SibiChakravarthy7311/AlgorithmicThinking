// AlgorithmicThinking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left, * right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* LCA(Node* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == n1 || root->data == n2) {
        return root;
    }
    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);
    if (left != NULL && right != NULL) {
        return root;
    }
    if (left == NULL && right == NULL) {
        return NULL;
    }
    if (left != NULL) {
        return LCA(root->left, n1, n2);
    }
    return LCA(root->right, n1, n2);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "LCA: " << LCA(root, 2, 5)->data;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
