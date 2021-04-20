#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};

struct Node* add(struct Node* head, int val, int idx) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = val;
	new_node->next = NULL;

	if(head == NULL) {
		return new_node;
	}

    if(idx == 1) {
        new_node->next = head;
		return new_node;
    }

	struct Node* temp = head;
    int cnt = 1;
    while (temp->next != NULL && idx != cnt+1) {
		temp = temp->next;
        ++cnt;
	}
    new_node->next = temp->next;
    temp->next = new_node;
	return head;
}

void printList(struct Node* head) {
	while (head != NULL) {
        cout<<head->data<<" ";
		head = head->next;
	}
}

int main() {
	struct Node* head = NULL;
	head = add(head, 1, 1);
	head = add(head, 2, 2);
	head = add(head, 3, 1);
	head = add(head, 4, 3);
	head = add(head, 5, 4);
	printList(head);
	return 0;
}