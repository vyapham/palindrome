/*
 * Queue.cpp
 * CIS 22C
 * LAB 3
 * Author: VY ANH PHAM
 */
#include "Queue.h"
#include <iostream>
#include <cstddef>
#include <assert.h>
#include <string>

using namespace std;

Queue::Queue() {
	front = NULL;
	end = NULL;
	length = 0;
}

Queue::Queue(const Queue &queue):length (queue.length) {
	if (queue.front == NULL) {
		front = end = NULL;
	}
	else {
		front = new Node(queue.front -> data);
		NodePtr temp = queue.front;
		NodePtr qtemp = front;

		while (temp -> next != NULL) {
			qtemp -> next = new Node;
			qtemp = qtemp -> next;
			temp = temp -> next;
			qtemp -> data = temp -> data;
		}

		end = qtemp;
	}
}

Queue::~Queue() {
	NodePtr temp = front;
	NodePtr temp2 = front;
	while (temp != NULL) {
		temp = temp -> next;
		delete temp2;
		temp2 = temp;
	}
}

void Queue::dequeue() {
	assert (length != 0);
	NodePtr temp = new Node;
	temp = front;
	front = front -> next;
	delete temp;
	length--;
}

void Queue::enqueue(string data) {
	if (length == 0) {
		front = new Node(data);
		end = front;
	}
	else {
		NodePtr node = new Node(data);
		end -> next = node;
		end = node;
	}
	length ++;
}

bool Queue::operator==(const Queue &queue) {
	if(length != queue.length) {
	        return false;
	    }

	    NodePtr temp1 = front;
	    NodePtr temp2 = queue.front;

	    while(temp1 != NULL) {
	        if(temp1->data != temp2->data) {
	            return false;
	        }
	        temp1 = temp1->next;
	        temp2 = temp2->next;
	    }
	    return true;
}

string Queue::get_front() {
	return front -> data;
}

int Queue::get_length() {
	return length;
}

bool Queue::is_empty() {
	return (length == 0);
}

void Queue::print() {
	NodePtr temp = new Node;
	temp = front;
	cout << temp -> data << endl;
	while (temp -> next != NULL) {
		temp = temp -> next;
		cout << temp -> data << endl;
	}
}

void Queue::reverse() {
	if (length > 1) {
		NodePtr temp = new Node;
		NodePtr cursor = new Node;
		temp = front;
		cursor = front;
		cursor = cursor -> next;
		temp -> next = NULL;
		front = cursor;
		end = temp;
		while (cursor -> next != NULL) {
			cursor = cursor -> next;
			front -> next = temp;
			temp = front;
			front = cursor;
		}
		front -> next = temp;
	}
}

void Queue::lettersOnly() {
	NodePtr temp = new Node;
	NodePtr cursor = new Node;
	NodePtr qtemp = new Node;
	temp = front -> next;
	cursor = front -> next;
	qtemp = front;


	while (temp != NULL) {
		string str = temp -> data;
		char x[str.length()];
		str.copy(x, str.length());
		if (int(x[0]) == 32 || int(x[0]) == 33 || int(x[0]) == 39 || int(x[0]) == 46
				|| int(x[0]) == 44 || int(x[0]) == 63) {
			temp = temp -> next;
			delete cursor;
			qtemp -> next = temp;
			cursor = temp;
		}
		else {
			temp = temp -> next;
			qtemp = cursor;
			cursor = cursor -> next;
		}
	}
}


