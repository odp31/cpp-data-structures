// can implement a PQ using the priority_queue container form the C++ standard template library


#include <iostream>
#include <queue>

using namespace std;

int main() {
  priority_queue<int> pq;

  pq.push(10);
  pq.push(20);
  pq.push(5);

  while(!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
  }
  return 0;
}
