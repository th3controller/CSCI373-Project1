/*
    Project 1 - CSCI 373
    David Slaby and Michael Garcia
    Professor Ni Lu
    Merging and Sorting Two Sorted Singly Linked Lists
 */

#include <iostream>
using namespace std;

/* Defintion & Initialization of a Singly Linked List */
class ListNode {
public:
	int val;
	ListNode *next;
};

/* Sorting and Merging Function */
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	ListNode fake;
	ListNode *last = &fake;
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

/* Push Function */
void push(ListNode **head_ref, int new_data) {
	/* Allocate node */
	ListNode *new_node = new ListNode();

	/* Put in the data */
	new_node->val = new_data;

	/* Link the old list off the new node */
	new_node->next = (*head_ref);

	/* Move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Print Function */
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

	cout << "List 1: ";
	printList(l1);

	cout << endl;

	cout << "List 2: ";
	printList(l2);

	cout << endl;

	cout << "Merged Linked List: ";
	printList(result);

	return 0;
}
