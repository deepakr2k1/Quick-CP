#include<bits/stdc++.h>
using namespace std;

class Trie {
    public:
        Trie* left;
        Trie* right;
};

void insert(int n, Trie* head) {
    Trie* curr = head;
    for(int i=31; i>=0; i--) {
        int b = (n>>i) & 1;
        if(b==0) {
            if(!curr->left) {
                curr->left = new Trie();
            }
            curr = curr->left;
        } else {
            if(!curr->right) {
                curr->right = new Trie();
            }
            curr = curr->right;
        }
    }
}

int findMaxXorPair(Trie* head, int* arr, int n) {
    int max_xor = INT_MIN;
    for(int i=0;i<n;i++) {
        Trie *curr = head;
        int temp = 0;
        for(int j=31; j>=0; j--) {
            int b = (arr[i]>>j) & 1;
            if(b==0) {
                if(curr->right) {
                    curr = curr->right;
                    temp += 1<<j;
                } else {
                    curr = curr->left;
                }
            } else {
                if(curr->left) {
                    temp += 1<<j;
                    curr = curr->left;
                } else {
                    curr = curr->right;
                }
            }
        }
        max_xor = max(max_xor, temp);
    }
    return max_xor;
}

int main() {
    int arr[] = {8,1,2,15,10,5};
    int n = 6;
    Trie* head = new Trie();
    for(int i=0;i<n;i++) insert(arr[i], head);
    cout<<findMaxXorPair(head, arr, n)<<endl;
}