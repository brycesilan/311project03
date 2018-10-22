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
  this->id=new string(id);
  this->key=key;
}

MinPriorityQueue::Element::~Element() {
  delete id;
}

MinPriorityQueue::MinPriorityQueue() {
  //TODO what do i initialize?
}

MinPriorityQueue::~MinPriorityQueue() {
  //TODO go through and delete elements in vector
}

void MinPriorityQueue::insert(const string& id, int key) {
  Element* tmp=new Element(id, key);
  minHeap.push_back(tmp);
  decreaseKey(*tmp->id, key); //TODO make sure correct
}

void MinPriorityQueue::decreaseKey(string id, int newKey) {
  int tmpKey=-1;

  for(unsigned int idx=0; idx<=minHeap.size()-1; idx++) { //TODO check for off by ones
    // also -1 ?
    if(*minHeap[idx]->id==id) {
      tmpKey=idx;
      break;
    }
  }

  if(tmpKey > minHeap[newKey]) { //TODO this is not right
    cerr << "Error: New key is greater than current key" << endl;
  }
  // TODO a[i]=key ? minHeap[newKey]=
  while(newKey>0 && minHeap[parent(newKey)] > minHeap[newKey]) {
    //exchange move newKey
    //TODO this is definitely wrong
  }
}

string MinPriorityQueue::extractMin() {
  Element* max;

  if(minHeap.size()<1) {
    cerr << "Error: Heap underflow" << endl;
  }

  max=minHeap[0];
  minHeap[0]=minHeap[minHeap.size()-1]; //TODO might need -1 cause 0-4 is size 5
  minHeapify(0);

  cout << "extract min is returning : " << *max->id << endl;
  return *max->id;
}

void MinPriorityQueue::buildMinHeap() {
  for(int idx=minHeap.size()/2; idx>=0; idx--) { //TODO make sure this works
    minHeapify(idx);
  }
}

void MinPriorityQueue::minHeapify(int i) {
  unsigned int left=this->left(i);
  unsigned int right=this->right(i);
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
