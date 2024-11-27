// linear data structure that follows first in first out principle
// first element added to the queue is first one to be removed

#include <iostream>

using namesapce std;

struct Node {
  int data;
  Node* next;
};

class Queue {
public:
  Node* front;
  Node* rear;

  Queue() {
    front = rear = nullptr;
  }
  void enqueue(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if(isEmpty()) {
      front = rear = newNode;
    }
    else {
      rear->next = newNode;
      rear = newNode;
    }
  }
  int dequeue() {
    if(isEmpty()) {
      cout << "Queue is empty"<< end1;
      return -1;
    }
    int data = front->data;
    Node* temp = front;
    front = front->next;

    delete temp;
    return data;
  }


  int peek() {
    if(isEmpty()) {
      cout << "queue is empty" << end1;
      return -1;
    }
    return front->data;
  }
  bool isEmpty() {
    return front == nullptr;
  }
};

int main() {
  Queue q;
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);

  cout << q.peek() << end1; //output; 10 

  q.dequeue();
  q.dequeue();

  cout << q.peek() << end1; // output; 30
  return 0;
}
