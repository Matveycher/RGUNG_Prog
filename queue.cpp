#include <cstdlib>
#include <iostream>
#include "queuend.h"
#include "queue.h"

using namespace std;

Queue::Queue() {
	headPtr = tailPtr = NULL;
}

Queue::~Queue() {
	deleteAll();
	cout << "Queue is deleted" << endl;
}

void Queue::enqueue(int value) {
	QueueNode *newPtr = getNewNode(value);
	if(isEmpty())
		headPtr = newPtr;
	else
		tailPtr->nextPtr = newPtr;
	tailPtr = newPtr;
}

void Queue::enqueueFront(int value) {
	QueueNode *newPtr = getNewNode(value);
	if(isEmpty())
		tailPtr = newPtr;
	else
		newPtr->nextPtr = headPtr;
	headPtr = newPtr;
}

int Queue::dequeue() {
	if(isEmpty()) {
		cout << "Queue is empty" << endl;
		return 0;
	}
	QueueNode* tempPtr = headPtr;
	if(headPtr == tailPtr)
		headPtr = tailPtr = NULL;
	else
		headPtr = headPtr->nextPtr;
	int returnValue = tempPtr->data;
	delete tempPtr;
	return returnValue;
}

void Queue::edit(int value, int change) {
	if(isEmpty()) {
		cout << "Queue is empty" << endl;
		return;
	}
	int n = 0;
	QueueNode *currentPtr = headPtr;
	while(currentPtr != NULL) {
		if(currentPtr->data == value) {
			n++;
			currentPtr->data = change;
		}
		currentPtr = currentPtr->nextPtr;
	}
	if(n == 0)
		cout << "Element " << value << " not found" << endl;
	else
		cout << "Elements found: " << n << endl;
}

void Queue::stackQueue(const Queue &queue) {
	QueueNode *currentPtr1 = headPtr, *currentPtr2 = queue.headPtr;
	while(currentPtr1 != NULL || currentPtr2 != NULL) {
		currentPtr1->data = currentPtr1->data + currentPtr2->data;
		currentPtr1 = currentPtr1->nextPtr;
		currentPtr2 = currentPtr2->nextPtr;
	}
	while(currentPtr2 != NULL) {
		enqueue(currentPtr2->data);
		currentPtr2 = currentPtr2->nextPtr;
	}
}

void Queue::mergeQueue(const Queue &queue) {
	QueueNode *currentPtr = queue.headPtr;
	while(currentPtr != NULL) {
		enqueue(currentPtr->data);
		currentPtr = currentPtr->nextPtr;
	}
}

void Queue::sortQueue() {
	if(!isEmpty()) {
		int l = 0;
		QueueNode *currentPtr = headPtr;
		while(currentPtr != NULL) {
			l++;
			currentPtr = currentPtr->nextPtr;
		}
		int *temp = new int[l];
		l = 0;
		currentPtr = headPtr;
		while(currentPtr != NULL) {
			temp[l++] = currentPtr->data;
			currentPtr = currentPtr->nextPtr;
		}
		int i, j;
		for(i = 0; i < l; i++)
			for(j = 0; j < l; j++)
				if(temp[i] > temp[j])
					swap(temp[i], temp[j]);
		currentPtr = headPtr;
		deleteAll();
		for(i = 0; i < l; i++)
			enqueueFront(temp[i]);
		delete[] temp;
	}
}

void Queue::reverseQueue() {
	if(!isEmpty()) {
		Queue temp;
		int value;
		while(!isEmpty()) {
			value = dequeue();
			temp.enqueueFront(value);
		}
		while(!temp.isEmpty()) {
			value = temp.dequeue();
			enqueue(value);
		}
	}
}

void Queue::deleteDups() {
	QueueNode *currentPtr1 = headPtr, *currentPtr2, *previousPtr;
	while(currentPtr1 != NULL) {
		currentPtr2 = currentPtr1->nextPtr;
		previousPtr = currentPtr1;
		while(currentPtr2 != NULL) {
			if(currentPtr1->data == currentPtr2->data) {
                QueueNode *tempPtr = currentPtr2;
				previousPtr->nextPtr = currentPtr2->nextPtr;
                delete tempPtr;
            }
			else
				previousPtr = currentPtr2;
			currentPtr2 = currentPtr2->nextPtr;
		}
		tailPtr = currentPtr1;
		currentPtr1 = currentPtr1->nextPtr;
	}
}

void Queue::deleteAll() {
	while(!isEmpty())
		dequeue();
}

int Queue::isEmpty() const {
	return headPtr == NULL;
}

int Queue::length() const {
	QueueNode *currentPtr = headPtr;
	int l = 0;
	while(currentPtr != NULL) {
		l++;
		currentPtr = currentPtr->nextPtr;
	}
	return l;
}

void Queue::condition() const {
	if(isEmpty())
		cout << "Queue is empty" << endl;
	else {
		cout << "Condition of queue:" << endl <<
		"Head is " << headPtr->data << endl <<
		"Tail is " << tailPtr->data << endl << 
		"Length is " << length();
	}
}

void Queue::print() const {
	if(isEmpty())
		cout << "Queue is empty" << endl;
	else {
		cout << "Queue is:" << endl;
		QueueNode *currentPtr = headPtr;
		while(currentPtr != NULL) {
			cout << currentPtr->data << " <-- ";
			currentPtr = currentPtr->nextPtr;
		}
		cout << "NULL" << endl;
	}
}

QueueNode* Queue::getNewNode(int value) {
	QueueNode *newPtr = new QueueNode(value);
	if(newPtr != NULL)
		return newPtr;
	cout << "Memory couldn't be allocated" << endl;	
	return NULL;
}