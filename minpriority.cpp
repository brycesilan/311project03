/**
 * @file minpriority.cpp    Min-priority queue class functions.
 *
 * @brief
 *    Maintains data based on a minimum priority queue.
 *
 * @author Connor Richards
 */

#include "minpriority.h"

//TODO dont forget to delete stuff

MinPriorityQueue::Element::Element() {
  string=nullptr;
  key=0;
}

MinPriorityQueue::Element::Element(const string& id, int key) {
  string=id;
  key=key; //TODO this->key ?
}

MinPriorityQueue::Element::~Element() {
  string=nullptr;
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
}

int MinPriorityQueue::left(int i) {
}

int MinPriorityQueue::right(int i) {
}
