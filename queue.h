#ifndef QUEUE_H
#define QUEUE_H

#include "queuend.h"

class Queue {
	public:
		Queue();
		~Queue();
	
		void enqueue(int);
		void enqueueFront(int);
		int dequeue();
		void edit(int, int);
		
		void stackQueue(const Queue&);
		void mergeQueue(const Queue&);
		
		void sortQueue();
		void reverseQueue();
		
		void deleteDups();
		void deleteAll();
		
		int isEmpty() const;
		int length() const;
		void condition() const;
		void print() const;
	
	private:
		QueueNode *headPtr;
		QueueNode *tailPtr;
		
		QueueNode *getNewNode(int);
};

#endif