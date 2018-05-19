/*
 chgPrioirity(PQ, priority): changes the priority (node value) of queue element.
 minPrioirty(PQ): removes the top element of the queue.
 contains(PQ, queue_element): does the queue contain queue_element.
 Insert(PQ, queue_element): insert queue_element into queue
 top(PQ):returns the top element of the queue.
 size(PQ): return the number of queue_elements
 */

#include <iostream>
#include <queue>
using namespace std;

// Structure to represent a min heap node
class element {
  public:
    element(int v, int dist) {
        this->v = v;
        this->dist = dist;
    }
    // A constructor to create a new Min Heap Node
    element() {
        this->v = 0;
        this->dist = 0;
    }
    int v;
    int dist;
};

// Structure to represent a min heap
class PriorityQueue {
   public:
     PriorityQueue(int capacity);
     void chgPriority(int v, int dist);
     element minPriority();
     bool contains(int v);
     void insert(int queue_element);
     int top();
     bool isEmpty();
   private:
     int size;      // Number of heap nodes present currently
     int capacity;  // Capacity of min heap
     int *pos;     // This is needed for decreaseKey()
     class element *array;
     void swap(element& a, element& b);
     void heapify(int idx);
};


// A constructor to create a Min Heap
PriorityQueue::PriorityQueue(int capacity) {
    pos = new int[capacity];
    size = 0;
    this->capacity = capacity;
    array = new element[capacity];
}

// A utility function to swap two nodes of min heap. Needed for min heapify
void PriorityQueue::swap(element &a, element &b) {
    element& t = a;
    a = b;
    b = t;
}

// A standard function to heapify at given idx
// This function also updates position of nodes when they are swapped.
// Position is needed for decreaseKey()
void PriorityQueue::heapify(int idx) {
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;
    
    if (left < this->size &&
        this->array[left].dist < this->array[smallest].dist )
        smallest = left;
    
    if (right < this->size &&
        this->array[right].dist < this->array[smallest].dist )
        smallest = right;
    
    if (smallest != idx)
    {
        // The nodes to be swapped in min heap
        element smallestNode = this->array[smallest];
        element idxNode = this->array[idx];
        
        // Swap positions
        this->pos[smallestNode.v] = idx;
        this->pos[idxNode.v] = smallest;
        
        // Swap nodes
        swap(this->array[smallest], this->array[idx]);
        
        heapify(smallest);
    }
}

// A utility function to check if the given minHeap is ampty or not
bool PriorityQueue::isEmpty() {
    return this->size == 0;
}

// Standard function to extract minimum node from heap
element PriorityQueue::minPriority() {
    //if (isEmpty())
    //    return nullptr;
    
    // Store the root node
    element root = this->array[0];
    
    // Replace root node with last node
    element lastNode = this->array[this->size - 1];
    this->array[0] = lastNode;
    
    // Update position of last node
    this->pos[root.v] = this->size-1;
    this->pos[lastNode.v] = 0;
    
    // Reduce heap size and heapify root
    --this->size;
    heapify(0);
    
    return root;
}


// Function to decreasy dist value of a given vertex v. This function
// uses pos[] of min heap to get the current index of node in min heap
void PriorityQueue::chgPriority(int v, int dist) {
    // Get the index of v in  heap array
    int i = this->pos[v];
    
    // Get the node and update its dist value
    this->array[i].dist = dist;
    
    // Travel up while the complete tree is not hepified.
    // This is a O(Logn) loop
    while (i && this->array[i].dist < this->array[(i - 1) / 2].dist)
    {
        // Swap this node with its parent
        this->pos[this->array[i].v] = (i-1)/2;
        this->pos[this->array[(i-1)/2].v] = i;
        swap(this->array[i],  this->array[(i - 1) / 2]);
        
        // move to parent index
        i = (i - 1) / 2;
    }
}

// A utility function to check if a given vertex
// 'v' is in min heap or not
bool PriorityQueue::contains(int v) {
    if (this->pos[v] < this->size)
        return true;
    return false;
}
