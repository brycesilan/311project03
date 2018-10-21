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
  this->id=id;
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
}

void MinPriorityQueue::decreaseKey(string id, int newKey) {
}

string MinPriorityQueue::extractMin() {
}

void MinPriorityQueue::buildMinHeap() {
}

void MinPriorityQueue::minHeapify(int i) {
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
