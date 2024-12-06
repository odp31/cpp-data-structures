#include <iostream>

using namespace std;

class Node {
public:
  int data;
  Node* next;

  Node(int data) {
    this->data = data;
    this->next = nullptr;
  }
};

class CircularLinkedList {
public:
  Node* head;

  CircularLinkedList() {
    head = nullptr;
  }
  // insert node at beginning
  void insertAtBeginning(int data) {
    Node* newNode = new Node(data);
    if(head== nullptr) {
      head=newNode;
      newNode->next = head;
    } else {
      Node* temp = head;
      while(temp->next != head) {
        temp = temp->next;
      }
      newNode->next = head;
      temp->next = newNode;
      head = newNode;
    }
  }
// insert node at end
  void insertAtEnd(int data) {
    Node* newNode = new Node(data);
    if(head == nullptr) {
      head = newNode;
      newNode -> next = head;
    } else {
      Node* temp = head;
      while(temp->next != head) {
        temp = temp->next;
      }
      temp->next = newNode;
      newNode->next = head;
    }
  }
// delete node with given value
void deleteNode(int data) {
  if(head == nullptr) {
    return;
  }
  Node* temp = head;
  Node* prev = nullptr;
  do {
    if(temp->data == data) {
      if(prev == nullptr) { // deleting head node
        if(head->next == head) {
          head = nullptr;
        } else {
          Node* last = head;
          while(last -> next != head) {
            last = last->next;
          }
          last->next = head->next;
          head = head->next;
        }
      } else {
          prev->next = temp -> next;
          delete temp;
      }
      return;
    }
    prev = temp;
    temp = temp->next;
  } while (temp !- head); 
}

// print circular linked list
void printList() {
  if (head== nullptr) {
    cout << "list is empty" << end1;
    return;
  }
  Node* temp = head;
  do {
    cout << temp-> data << " ";
    temp = temp->next;
  } while (temp != head);
  cout << end1;
}
};

int main() {
  CircularLinkedList cll;
  cll.insertAtBeginning(5);
  cll.insertAtBeginning(10);
  cll.insertAtEnd(15);
  cll.printList();       //output; 10 5 15
  cll.deleteNode(5);
  cll.printList();        //output; 10 15
  return 0;
}
