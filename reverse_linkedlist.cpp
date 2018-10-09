#include<iostream>
using namespace std;

class Node {
	public:
	int data;
	Node* next;

	Node(int data) {
		this -> data = data;
		next = NULL;
	}
};

Node* insert() {
	int data;
	cin >> data;
	Node* head = NULL;
	Node* tail = NULL;
	while(data != -1) {
		Node* node = new Node(data);
		if(head == NULL) {
			head = node;
			tail = node;
		}
		else {
			tail -> next = node;
			tail = node;
		}
		cin >> data;
	}
	return head;
}

Node* reverse(Node* head) {
	if(head -> next == NULL) {
		return head;
	}
	Node* second = head -> next;

	Node* smallHead = reverse(head -> next);

	second -> next = head;
	head -> next = NULL;
	return smallHead;
}

void printLL(Node* head) {
	Node* temp = head;
	while(temp != NULL) {
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}

int main() {
	Node* head = insert();
	Node* newHead = reverse(head);
	printLL(newHead);
	return 0;
}