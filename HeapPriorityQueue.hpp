//
// Name : Paul Gritsch
// SSID : 1220449
// A05:  Submission Date: 12/10/23
//

#pragma once
#ifndef HEAPPRIORITYQUEUE_H
#define HEAPPRIORITYQUEUE_H
#include "VectorCompleteBinaryTree.hpp"



template <typename E, typename C>
class HeapPriorityQueue { 
public:
	// number of elements
	int size() const {return T.size();}
	// is the queue empty?
	bool empty() const {return size() == 0;}
	// insert element
	void insert(const E& e){
	  T.addLast(e);                           // add e to heap
	  Position v = T.last();                  // e's position
	  while (!T.isRoot(v)) {                  // up-heap bubbling
		 Position u = T.parent(v);
		 if (!isLess(*v, *u)) break;          // if v in order, we're done
		 T.swap(v, u);                        // ...else swap with parent
		 v = u;
	  }
	}
	// minimum element
	const E& min(){return *(T.root());}
	// remove minimum may neet to rename back to removeMin()
	void remove_min(){
	  if (size() == 1)                       // only one node?
		 T.removeLast();                     // ...remove it
	  else {
		 Position u = T.root();              // root position
		 T.swap(u, T.last());                // swap last with root
		 T.removeLast();                     // ...and remove last
		while (T.hasLeft(u)) {              // down-heap bubbling
		 Position v = T.left(u);
		 if (T.hasRight(u) && isLess(*(T.right(u)), *v))
		   v = T.right(u);                   // v is u's smaller child
		 if (isLess(*v, *u)) {               // is u out of order?
		   T.swap(u, v);                     // ...then swap
		   u = v;
		 }
		 else break;                         // else we're done
		}
	  }
	}

  void removeMin(){
    remove_min();
  }


private:
	// priority queue contents
	VectorCompleteTree<E> T;
	// less-than comparator
	C isLess;
	// shortcut for tree position
	typedef typename VectorCompleteTree<E>::Position Position;
};

#endif