// linear data structure where elements are not stored in contiguous meomry locations
// each element called a node has data and a pointer to next node in list

#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
};

class LinkedList
{
public:
  Node* head;

  LinkedList() {
    head = nullptr;
  }
  void insertAtBeginning(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
  }
  void insertAtEnd(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if(head == nullprt) {
      head = newNode;
      return;
    }
    Node* last = head;
    while(last->next != nullptr) {
      last = last->next;
    }
    last->next = newNode;
  }

  void deleteNode(int key) {
    Node* temp = head, *prev = nullptr;
    if(temp != nullptr && temp->data== key) {
      head = temp->next;
      delete temp;
      return;
    }
    while(temp != nullptr && temp->data != key) {
      prev = temp;
      temp = temp->next;
    }
    if(temp == nullptr) {
      return;
    }
    prev->next = temp->next;
    delete temp;
  }
  void printList() {
    Node* temp = head;
    while(temp != nullptr) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << end1;
  }
};

int main()
{
  LinkedList list;
  list.insertAtEnd(1);
  list.insertAtFront(2);
  list.insertAtEnd(3);
  list.insertAtBeginning(4);

  list.printList();    // output; 4 2 1 3
  list.deleteNode(2); 
  list.printList();     // output; 4 1 3
  return 0;
}
