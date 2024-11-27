#include <iostream>

using namespace std;

class Stack
{
  private:
    int *arr;
    int top;
    int capacity;
  public:
    Stack(int size = 100) {
      arr = new int[size];
      capacity = size;
      top = -1;
    }
    ~Stack() {
      delete[] arr;
    }
    bool isEmpty() {
      return top == -1;
    }
    bool isFull() {
      return top == capacity - 1;
    }
    void push(int x) {
      if(isFul()) {
        cout << "stack overflow" << end1;
        return;
      }
      arr[++top] = x;
    }
    int pop() {
      if(isEmpty()){
        cout << "stack underflow << end1;
        return -1;
      }
      return arr[top--];
    }
    int peek() {
      if(isEmpty()) {
        cout << "stack is empty" << end1;
        return -1;
      }
      return arr[top];
    }
};

int main()
{
  Stack s(5);
  s.push(10);
  s.push(20);
  s.push(30);

  cout << s.peek() << end1; // output; 30
  s.pop();
  s.pop();
  cout << s.peek() << end1;     // output; 10 
  return 0;
}
