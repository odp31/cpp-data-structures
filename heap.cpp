// specialized tree baed data structure that satisfies heap property
// max heap; parent node always >= children
// min heap; parent <= children 

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
  int arr[MAX_SIZE];
  int size;
} Heap;

void heapify(Heap* heap, int i)
{
  int smallest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if(left < heap->size && heap->arr[left] < heap->arr[smallest])
    smallest = left;
  if(right < heap->size && heap->arr[right] < heap->arr[smallest])
    smallest = right; 
  if(smallest != i) {
    int temp = heap->arr[i];
    heap->arr[i] = heap->arr[smallest];
    heap->arr[smallest] = temp;
    heapify(heap, smallest);
  }
}
void insert(Heap* heap, int x) {
  heap->size++;
  heap->arr[heap->size - 1] = x;
  for(int i = (heap->size - 1) / 2; i >= 0; i--) {
    heapify(heap, i);
  }
}

int extractMin(Heap* heap)
{
  if(heap->size <= 0) {
    return INT_MAX;
  }
  int root = heap->arr[0];
  heap->arr[0] = heap->arr[heap->size - 1];
  heap->size--;
  heapify(heap, 0);
  return root;
}

void printArray(int arr[], int size)
{
  for(int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  printf("\n");
  }
}

int main()
{
  Heap heap; 
  heap.size = 0; 

  insert(&heap, 3);
  insert(&heap, 2);
  insert(&heap, 15);
  insert(&heap, 4);
  insert(&heap, 45);

  printf("min heap arary: ");
  printArray(heap.arr, heap.size);

  printf("extract min: %d\n", extractMin(&heap));
  printf("min heap array after extractMin: ");
  printArray(heap.arr, heap.size);
  return 0; 
}
