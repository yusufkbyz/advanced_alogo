#include <iostream>
#include <cassert>
using namespace std;

// ============================================================
// Node class
// ============================================================
class Node {
public:
	int data;
	Node* next;
	Node(int value) { data = value; next = nullptr; }
};

// ============================================================
// LinkedList class
// ============================================================
class LinkedList {
public:
	Node* head;

	LinkedList() { head = nullptr; }

	~LinkedList() {
		Node* current = head;
		while (current != nullptr) {
			Node* nextNode = current->next;
			delete current;
			current = nextNode;
		}
	}

	void insertAtHead(int value) {
		Node* newNode = new Node(value);
		newNode->next = head;
		head = newNode;
	}

	void insertAtTail(int value) {
		Node* newNode = new Node(value);
		if (head == nullptr) {
			head = newNode;
			return;
		}
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;
	}

	bool deleteValue(int value) {
		if (head == nullptr) {
			return false;
		}
		if (head->data == value) {
			Node* temp = head;
			head = head->next;
			delete temp;
			return true;
		}
		Node* current = head;
		while (current->next != nullptr) {
			if (current->next->data == value) {
				Node* temp = current->next;
				current->next = temp->next;
				delete temp;
				return true;
			}
			current = current->next;
		}
		return false;
	}

	bool search(int value) {
		Node* current = head;
		while (current != nullptr) {
			if (current->data == value) {
				return true;
			}
			current = current->next;
		}
		return false;
	}

	int length() {
		int count = 0;
		Node* current = head;
		while (current != nullptr) {
			count++;
			current = current->next;
		}
		return count;
	}

	void reverse() {
		Node* prev = nullptr;
		Node* current = head;
		while (current != nullptr) {
			Node* nextNode = current->next;
			current->next = prev;
			prev = current;
			current = nextNode;
		}
		head = prev;
	}

	void print() {
		Node* current = head;
		while (current != nullptr) {
			cout << current->data << " -> ";
			current = current->next;
		}
		cout << "null" << endl;
	}
};

// ---- Do NOT modify below this line ----
int main() {
	LinkedList L;

	// TC1: insertAtHead (builds list in reverse order)
	L.insertAtHead(30);
	L.insertAtHead(20);
	L.insertAtHead(10);
	cout << "TC1: "; L.print();

	// TC2: insertAtTail
	L.insertAtTail(40);
	L.insertAtTail(50);
	cout << "TC2: "; L.print();

	// TC3: length
	cout << "TC3: length = " << L.length() << endl;

	// TC4: search
	cout << "TC4: search(30)=" << L.search(30)
		<< " search(99)=" << L.search(99) << endl;

	// TC5: delete head
	L.deleteValue(10);
	cout << "TC5: "; L.print();

	// TC6: delete tail
	L.deleteValue(50);
	cout << "TC6: "; L.print();

	// TC7: delete middle
	L.deleteValue(30);
	cout << "TC7: "; L.print();

	// TC8: delete non-existent
	bool r = L.deleteValue(99);
	cout << "TC8: deleteValue(99)=" << r << endl;

	// TC9: reverse
	LinkedList L2;
	L2.insertAtTail(1); L2.insertAtTail(2); L2.insertAtTail(3);
	L2.reverse();
	cout << "TC9: "; L2.print();

	// TC10: empty list edge cases
	LinkedList L3;
	cout << "TC10: length=" << L3.length()
		<< " search=" << L3.search(5)
		<< " delete=" << L3.deleteValue(5) << endl;

	return 0;
}
