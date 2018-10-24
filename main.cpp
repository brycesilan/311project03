/**
 * @file main.cpp   Main driver of minimum priority queue program
 *
 * @author Connor Richards
 */

//TODO what is 'prefer operator[] for vector access where appropriate'
//TODO main should implement 'test driver'
//      what is that

#include <iostream>
#include "minpriority.h"

using namespace std;

int main() {
  char input='0';
  MinPriorityQueue mainMinQueue;

  while(input!='q') {
    cin >> input;

    if(input=='a') {
      string inString;
      int key=0;

      cin >> inString >> key;

      mainMinQueue.insert(inString, key); //TODO idk if this works cause string&
    }
    else if(input=='d') {
      string inString;
      int key=0;

      cin >> inString >> key;

      mainMinQueue.decreaseKey(inString, key);
    }
    else if(input=='x') {
      string extractedString=mainMinQueue.extractMin();

      if(extractedString!="") {
        cout << extractedString << endl;
      }
      else {
        cout << "empty" << endl;
      }
    }
    else {
      cerr << "Error: Invalid input" << endl;
    }
  }

  return 0;
}
