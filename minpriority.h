/**
 * @file minpriority.h    Declaration of the MinPriorityQueue class.
 *
 * @author Connor Richards
 */

#ifndef MINPRIORITY_H
#define MINPRIORITY_H

class MinPriorityQueue {
  public:
    MinPriorityQueue();
    ~MinPriorityQueue();
    void insert(const string& id, int key);   /** inserts element with key */
    void decreaseKey(string id, int newKey);    /** decreases of element */
    string extractMin();    /** removes min element */
  private:
    void buildMinHeap();    /** builds min heap from vector */
    void minHeapify(int i);   /** makes 'i' element root of a min heap */
    int parent(int i);    /** returns parent of element 'i' */
    int left(int i);    /** returns left child of element 'i' */
    int right(int i);   /** returns right child of element 'i' */
    vector<Element*> minheap;   /** data storage */

    class Element {   /** declaration of an Element */
      public:
        string* id;
        int key;
        Element();
        Element(const string& id, int key);
        ~Element();
    };
};

#endif /** MINPRIORITY_H */
