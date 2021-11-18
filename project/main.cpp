/*
    Project 1 - CSCI 373
    David Slaby and Michael Garcia
    Professor Ni Lu
    Singly linked list
    Merging two 
 */
#include <iostream>
using namespace std;

/* Link list node */
class ListNode {
public:
	int val;
	ListNode *next;
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	ListNode fake;						// Create a dummy node
	ListNode *last = &fake;				// Last points to the last result node
	while (l1 != NULL && l2 != NULL) {
		if (l1->val < l2->val) {
			last->next = l1;
			last = l1;
			l1 = l1->next;
		} else {
			last->next = l2;
			last = l2;
			l2 = l2->next;
		}
	}
	if (l1 != NULL) {
		last->next = l1;
	}
	if (l2 != NULL) {
		last->next = l2;
	}
	return fake.next;
}

void push(ListNode **head_ref, int new_data) {
	/* allocate node */
	ListNode *new_node = new ListNode();

	/* put in the data */
	new_node->val = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

void printList(ListNode *node) {
	while (node != NULL) {
		cout << node->val << " ";
		node = node->next;
	}
}

int main() {
	ListNode *l1 = NULL;
	ListNode *l2 = NULL;
	ListNode *result = NULL;

	push(&l1, 15);
	push(&l1, 10);
	push(&l1, 5);

	push(&l2, 20);
	push(&l2, 3);
	push(&l2, 2);

	result = mergeTwoLists(l1, l2);

	cout << "Merged Linked List is: \n";
	printList(result);

	return 0;
}