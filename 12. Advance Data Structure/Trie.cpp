#include <bits/stdc++.h> 
using namespace std; 

const int ALPHABET_SIZE = 26; 

struct TrieNode { 
	struct TrieNode *children[ALPHABET_SIZE];
	bool isEndOfWord; 
}; 

// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) { 
	struct TrieNode *pNode = new TrieNode; 
	pNode->isEndOfWord = false;
	for(int i=0;i<ALPHABET_SIZE;i++)
		pNode->children[i] = NULL; 
	return pNode; 
} 

void insert(struct TrieNode *root, string str) { 
	struct TrieNode *pCrawl = root; 
	for (auto x: str) { 
		int idx = x-'a';
		if (!pCrawl->children[idx]) 
			pCrawl->children[idx] = getNode(); 
		pCrawl = pCrawl->children[idx]; 
	}
	pCrawl->isEndOfWord = true; 
} 

bool search(struct TrieNode *root, string str) { 
	struct TrieNode *pCrawl = root;
	for (auto x: str) { 
		int idx = x-'a'; 
		if (!pCrawl->children[idx]) 
			return false; 
		pCrawl = pCrawl->children[idx]; 
	} 
	return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 


int main() { 
	string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their" };
	int n = sizeof(keys)/sizeof(keys[0]);
	
	struct TrieNode *root = getNode(); 

	for (int i=0;i<n;i++)
		insert(root, keys[i]); 

	cout<<search(root, "the")<<endl; 
	cout<<search(root, "th")<<endl; 
} 
