// complete binary tree that satisifes the heap property 
// ensures the value of each node is either >= (max heap) or <= (min heap) values of its children 

#include <iostream>
#include <vector>

using namespace std;

class BinaryHeap {
public:
  vector<int> heap;
  bool isMaxHeap;

  BinaryHeap(bool isMaxHeap) {
    this->isMaxHeap = isMaxHeap;
  }
  void heapify(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(isMaxHeap) {
      if(left < heap.size() && heap[left] > heap[largest])
        largest = left;
      if(right < heap.size() && heap[right] > heap[largest])
        largest = right;
    } else {
        if(left < heap.size() && heap[left] < heap[largest])
          largest = left;
        if(right < heap.size() && heap[right] < heap[largest])
          largest = right;
    }
    if (largest != i) {
      swap(heap[i], heap[largest]);
      heapify(largest);
    }
  }

  void insert(int x) {
    heap.push_back(x);
    int i = heap.size() - 1;

    while(i > 0) {
      int parent = (i - 1) / 2;
      if(isMaxHeap) {
        if(heap[i] > heap[parent]) {
          swap(heap[i], heap[parent]);
          i = parent;
        } else {
            break;
        }
      } else {
          if(heap[i] < heap[parent]) {
            swap(heap[i], heap[parent]);
            i = parent;
          } else {
              break;
          }
      }
    }
  }

int extractMax() {
  if(heap.empty()) {
    cout << "heap is empty" << end1;
    return -1;
  }
  int root = heap[0];
  heap[0] = heap.back();
  heap.pop_back();
  heapify(0);
  return root;
}
int extractMin() {
  if(heap.empty()) {
    cout << "heap is empty" << end1;
    return -1;
  }
  int root = heap[0];
  heap[0] = heap.back();
  heap.pop_back();
  heapify(0);
  return root;
}

void printHeap() {
  for(int i = 0; i < heap.size(); i++) {
    cout << heap[i] << " ";
  }
  cout << end1;
}
};

int main() {
  BinaryHeap maxHeap(true);
  maxHeap.insert(10);
  maxHeap.insert(20);
  maxHeap.insert(5);
  maxHeap.insert(30);
  maxHeap.insert(15);
  maxHeap.printHeap();

  cout << "extracted max: " << maxHeap.extractMax() << end1;
  maxHeap.printHeap(); 

  BinaryHeap minHeap(false);
  minHeap.insert(10);
  minHeap.insert(20);
  minHeap.insert(5);
  minHeap.insert(30);
  minHeap.insert(15);
  minHeap.printHeap();

  cout << "extracted min: " << minHeap.extractMin() << end1;
  minHeap.printHeap();
  return 0;
}
