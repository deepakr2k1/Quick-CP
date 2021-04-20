#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct Node* add(struct Node* root, int val) {
    if(root == NULL) {
        root = newNode(val);
        return root;
    }
    struct Node* temp = root;
    while(true) {
        if(temp->data > val) {
            if(temp->left == NULL) {
                temp->left = newNode(val);
                return root;
            }
            temp = temp->left;
        } else {
            if(temp->right == NULL) {
                temp->right = newNode(val);
                return root;
            }
            temp = temp->right;
        }
    }
    return root;
}

void printList(struct Node* root) {
    if(root == NULL) return;
    printList(root->left);
    cout<<root->data<<" ";
    printList(root->right);
}

int main() {
	struct Node* root = NULL;
	root = add(root, 4);
	root = add(root, 2);
	root = add(root, 5);
	root = add(root, 3);
	root = add(root, 1);
	printList(root);
	return 0;
}