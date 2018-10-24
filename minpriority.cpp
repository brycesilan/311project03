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
}

MinPriorityQueue::~MinPriorityQueue() {
  for(unsigned int idx=0; idx<minHeap.size(); idx++) { //TODO check off by ones
    delete minHeap[idx]; //* ?
  }
}

void MinPriorityQueue::insert(const string& id, int key) {
  Element* tmp=new Element(id, key);
  minHeap.push_back(tmp);
  cout << "heap size is " << minHeap.size() << endl;
  cout << "element 1 is " << *minHeap[0]->id << endl;
  cout << "tmp id is " << *tmp->id << endl;
  cout << "key is " << key << endl;
  decreaseKey(*tmp->id, key); //TODO make sure correct
}

void MinPriorityQueue::decreaseKey(string id, int newKey) {
  int tmpKey=-1;

  for(unsigned int idx=0; idx<=minHeap.size()-1; idx++) { //TODO Ob1s, also -1?
    if(*minHeap[idx]->id==id) {
      tmpKey=idx;
      break;
    }
  }

  //cout << "tmp key is " << tmpKey;
  //cout << " and the vector thing is " << *minHeap[tmpKey]->id << endl;
  //cout << "new key is " << newKey;
  //cout << " and the vector thing is " << *minHeap[newKey]->id << endl;

  if(minHeap[newKey]->id > minHeap[tmpKey]-id) {
    cerr << "Error: New key is greater than current key" << endl;
  }
  
  minHeap[tmpKey]=newKey

  while(tmpKey>0 && minHeap[parent(tmpKey)] > minHeap[tmpKey]) { //TODO Ob1s
    Element* tmp=minHeap[tmpKey];
    minHeap[tmpKey]=minHeap[parent(tmpKey)];
    minHeap[parent(tmpKey)]=tmp;

    tmpKey=parent(tmpKey);
  }
}

string MinPriorityQueue::extractMin() {
  Element* max;

  if(minHeap.size()<1) {
    return ""; //this was the error heap underflow
  }

  max=minHeap[0];
  minHeap[0]=minHeap[minHeap.size()-1]; //TODO might need -1 cause 0-4 is size 5
  minHeapify(0);

  cout << "extract min is returning : " << *max->id << endl; //TODO for debugging
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
