//
// Name : Paul Gritsch
// SSID : 1220449
// A05:  Submission Date: 12/10/23
//
#pragma once
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "LinkedList.hpp"

template <class NodeType>
class PriorityQueue {
public :
	// call your linked list insert front or back ; or insert t sorted
	void insert(NodeType t){
		q.insert_back(t);
	}
	
	// update linked list to return an Iterator ( refer to Goodrich -6.2.3)
	// or change to ListIterator to a NodeType * ( useful for unsorted list )
	// ListIterator<NodeType> find_min(ListIterator<NodeType> iter);

  Iterator<NodeType> find_min(Iterator<NodeType> iter){
    Iterator<NodeType> min = iter;
    while (iter != nullptr){
      if (*iter < *min){
        min = iter;
      }
      ++iter;
    }
    return min;
  }
	
	// return the min , may need a find helper function	
	NodeType min(){
    Node<NodeType>* iter = q.Head();
		NodeType output = q.Head()->data;
		while (iter != nullptr){
			if (iter->data < output){
				output = iter->data;
			}
      iter = iter->next;
		}
		return output;
	}

  // remove the min
  // if list is already sorted , just remove_front or back
  // if list is not sorted , find ( min ) and remove
  // may need an erase ( Iterator& iter ) method to linkedlist , refer to Ch -6
  void remove_min(){
    Iterator<NodeType> nodetoremove = find_min(q.begin());
    q.erase(nodetoremove);    
  }
	
	// check if queue is empty
	bool is_empty(){
		return q.empty();
	}

  void display() {
    q.display();
  }
	
private :
	LinkedList<NodeType> q ;
};
	// Updates May Be Needed to A4 ’s LinkedList
	// to make insert and remove easier create a list iterator p243 Goodrich
	// or use a NodeType * as iterator
	// To support queue operations add the following methods
	// to your linkedlist implementation :
	// insert ( iterator , elem ) // need for insert min
	// erase ( iterator ) // need for remove min

#endif