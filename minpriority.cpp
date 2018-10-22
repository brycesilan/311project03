/**
 * @file minpriority.cpp    Min-priority queue class functions.
 *
 * @brief
 *    Maintains data based on a minimum priority queue.
 *
 * @author Connor Richards
 */

#include "minpriority.h"

MinPriorityQueue::Element::Element() {
  id=nullptr;
  key=0;
}

MinPriorityQueue::Element::Element(const string& id, int key) {
  //*this->id = id;
  cout << id;
  this->key=key; //TODO this->key ?
}

MinPriorityQueue::Element::~Element() {
  //TODO have to delete id ?
  id=nullptr;
  key=0;
}

MinPriorityQueue::MinPriorityQueue() {
  //TODO what do i initialize?
}

MinPriorityQueue::~MinPriorityQueue() {
  //TODO go through and delete elements and vector
}

void MinPriorityQueue::insert(const string& id, int key) {
  //TODO is this a insert at end or insert and minheap it
  //also are we keeping track of heapSize?
  cout << key << id;
}

void MinPriorityQueue::decreaseKey(string id, int newKey) {
  //TODO do i compare strings until we find index?
  //are we setting the minHeap[newKey] to 'id'
  cout << id << newKey;
}

string MinPriorityQueue::extractMin() {
  //Element* max;

  if(minHeap.size()<1) {
    cerr << "Error: Heap underflow" << endl;
  }

  //max=minHeap[0];
  minHeap[0]=minHeap[minHeap.size()-1]; //TODO might need -1 cause 0-4 is size 5
  //TODO heapSize-- but are we keeping track of that?
  minHeapify(0);
  //return max;
  return nullptr;
}

void MinPriorityQueue::buildMinHeap() {
  //TODO will not having a heapSize var break this?
  for(int idx=minHeap.size()/2; idx>=0; idx--) { //TODO make sure this works
    minHeapify(idx);
  }
}

void MinPriorityQueue::minHeapify(int i) {
  unsigned int left=left(i); //should i do 2i or make left(int i) a private non-member function
  unsigned int right=right(i);
  int smallest;

  if(left<=minHeap.size() && minHeap[left]<minHeap[i]) { //TODO watch for off by ones
    smallest=left;
  }
  else {
    smallest=i;
  }
  if(right<=minHeap.size() && minHeap[right]<minHeap[smallest]) {
    smallest=right;
  }
  if(smallest!=i) {
    Element* tmp=minHeap[smallest];
    minHeap[smallest]=minHeap[i];
    minHeap[i]=tmp;

    minHeapify(smallest);
  }
}

int MinPriorityQueue::parent(int i) {
  //TODO do i have to specify that is is floor?
  return i*2;
}

int MinPriorityQueue::left(int i) {
  return i/2;
}

int MinPriorityQueue::right(int i) {
  //TODO check that works
  return i/2+1;
}
