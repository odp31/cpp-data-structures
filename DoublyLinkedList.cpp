// linear data structure where each node contains data, a pointer to the next node and a pointer to the previous
// allows for efficient traversal in both directions 

#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node* prev;
};

class DoublyLinkedList {
public:
  Node* head;
  DoublyLinkedList(){
    head = nullptr;
  }
  void insertAtBeginning(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head; 
    newNode->prev = nullptr;
    if(head != nullptr) {
      head->prev = newNode;
    }
    head = newNode;
  }
  void insertAtEnd(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if(head == nullptr) {
      newNode->prev = nullptr;
      head = newNode;
      return;
    }
    Node* last = head;
    while(last->next != nullptr) {
      last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
  }
  void deleteNode(int key) {
    Node*temp = head;
    if(temp != nullptr && temp->data == key) {
      head = temp->next;
      if(head != nullptr) {
        head->prev = nullptr;
      }
      delete temp;
      return;
    }
    while(temp != nullptr && temp->data != key) {
      temp = temp->next;
    }
    if(temp == nullptr) {
      return;
    }
    temp->prev->next = temp->next;
    if(temp->next != nullptr) {
      temp->next->prev = temp->prev;
    }
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
  DoublyLinkdList list;
  list.insertAtEnd(1);
  list.insertAtBeginning(2);
  list.insertAtEnd(3);
  list.insertAtBeginning(4);

  list.printList(); // output; 4 2 1 3
  list.deleteNode(2);
  list.printList(); // output; 4 1 3 
  return 0;
}
