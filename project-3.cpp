#include <iostream>
#include <cstdlib>
#include <fstream>
class Node
{
public:
	Node* next;
	int data;
};
using namespace std;

class LinkedList
{
public:
	int length;
	Node* head;
	LinkedList();
	~LinkedList();
	Node * add(int index, int data);
	Node * deleteIndex(int data);
	void print();
	void printInTextFile();

};

LinkedList::LinkedList() {
	this->length = 0;
	this->head = NULL;
}

LinkedList::~LinkedList() {
	std::cout << "LIST DELETED";
}

Node* LinkedList::add(int index, int data) {
	if (index < 0) return NULL;
	int currIndex = 1;
	Node* currNode = head;
	while (currNode && index > currIndex) {
		currNode = currNode->next;
		currIndex++;
	}
	if (index > 0 && currNode == NULL) return NULL;
	Node* newNode = new Node;
	newNode->data = data;
	if (index == 0) {
		newNode->next = head;
		head = newNode;
		this->length++;
	}
	else {
		newNode->next = currNode->next;
		currNode->next = newNode;
		this->length++;
	}
	return newNode;
}

void LinkedList::print() {

	Node* head = this->head;
	int i = 1;
	while (head) {
		//std::cout << i << ": " << head->data<<endl;
		std::cout << "Index " << i - 1 << ": " << head->data << endl;
		head = head->next;
		i++;
	}
}

void LinkedList::printInTextFile() {
	fstream file;
	file.open("C:/Zeming.Zhao.lList.txt", ios::out | ios::in);
	Node* head = this->head;
	int i = 1;
	while (head) {

		// Writing on file
		file << "Index " << i - 1 << " : " << head->data << endl;
		head = head->next;
		i++;
	}

}

Node* LinkedList::deleteIndex(int value) {
	Node* currNode = head;
	int currIndex = 1;
	while (currNode && currIndex < value)
	{
		currNode = currNode->next;
		currIndex++;

	}
	Node* Temp = currNode;
	Temp = Temp->next;
	currNode->next = Temp->next;
	return currNode;

}


int main(int argc, char const *argv[])
{
	LinkedList* list = new LinkedList();
	//list->add(0,rand() % 10);
	//list->add(0,2);
	//list->add(1,20);

	//1.Create a list of the following elements [11,10,9,8,7,6,5,4,3,2,1]
	cout << endl << "1.Create a list of the following elements [11,10,9,8,7,6,5,4,3,2,1]" << endl;
	list->add(0, 11);
	list->add(1, 10);
	list->add(2, 9);
	list->add(3, 8);
	list->add(4, 7);
	list->add(5, 6);
	list->add(6, 5);
	list->add(7, 4);
	list->add(8, 3);
	list->add(9, 2);
	list->add(10, 1);

	list->print();
	std::cout << endl << " List Length: " << list->length << std::endl;

	//delete list;

	//2. Delete element #5 (counting from 0)
	cout << endl << "2. Delete element #5 (counting from 0)" << endl;
	list->deleteIndex(5);
	list->print();


	//3. Insert element 100 at position 8 (counting from 0)
	cout << endl << "3. Insert element 100 at position 8 (counting from 0)" << endl;
	list->add(8, 100);
	list->print();

	//Using object from the linked list For step 4 the name of the file should be FirstName.LastName.lList.txt
	list->printInTextFile();
	cout << endl << "Write text to be written on file." << endl;


	return 0;
}