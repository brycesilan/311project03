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
}

MinPriorityQueue::~MinPriorityQueue() {
  //TODO go through and delete elements and vector
}

void MinPriorityQueue::insert(const string& id, int key) {
  //TODO is this a insert at end or insert amd minheap it
  cout << key << id;
}

void MinPriorityQueue::decreaseKey(string id, int newKey) {
  cout << id << newKey;
}

string MinPriorityQueue::extractMin() {
  //Element* max;

  if(minHeap.size()<1) {
    cerr << "Error: Heap underflow" << endl;
  }

  //max=minHeap[0];
  minHeap[0]=minHeap[minHeap.size()-1]; //TODO might need -1 cause 0-4 is size 5
  minHeapify(0);
  //return max;
  return nullptr;
}

void MinPriorityQueue::buildMinHeap() {
}

void MinPriorityQueue::minHeapify(int i) {
  cout << i;
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
