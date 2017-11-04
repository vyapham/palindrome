/*
 * Stack.cpp
 * CIS 22C
 * LAB 3
 * Author: VY ANH PHAM
 */
#include <iostream>
#include <cstddef>
#include <assert.h>
#include "Stack.h"

using namespace std;

Stack::Stack() {
    top = NULL;
    length = 0;
}

Stack::Stack(const Stack &stack):length(stack.length) {
    if (stack.top == NULL) {
        top = NULL;
    }
    else {
        top = new Node(stack.top -> data);
        NodePtr temp = stack.top;
        NodePtr qtemp = top;

        while (temp -> next != NULL) {
            qtemp -> next = new Node;
            qtemp = qtemp -> next;
            temp = temp -> next;
            qtemp -> data = temp -> data;
        }
    }
}

Stack::~Stack() {
    NodePtr temp = top;
    NodePtr temp2 = top;
    while (temp != NULL) {
        temp = temp -> next;
        delete temp2;
        temp2 = temp;
    }
}

void Stack::pop() {
	assert(length != 0);
    NodePtr temp = new Node;
    temp = top;
    top = top -> next;
    delete temp;
    length--;
}

void Stack::push(string data) {
	if (length == 0) {
		top = new Node(data);
	}
	else {
	    NodePtr N = new Node(data);
	    N -> next = top;
	    top = N;
	}

    length++;
}

string Stack::get_top() {
    return top -> data;
}

int Stack::get_length() {
    return length;
}

void Stack::print() {
    NodePtr temp = new Node;
    temp = top;
    while (temp != NULL) {
        cout << temp -> data << endl;
        temp = temp -> next;
    }
}

bool Stack::operator==(const Stack &stack) {
    if (length != stack.length) {
        return false;
    }
    NodePtr temp1 = top;
    NodePtr temp2 = stack.top;
    while (temp1 != NULL) {
        if (temp1 -> data != temp2 -> data) {
            return false;
        }
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }
    return true;
}

void Stack::reverse() {
	if (length > 1) {
		NodePtr temp = new Node;
		NodePtr cursor = new Node;
		temp = top;
		cursor = top;
		cursor = cursor -> next;
		temp -> next = NULL;
		top = cursor;
		while (cursor -> next != NULL) {
			cursor = cursor -> next;
			top -> next = temp;
			temp = top;
			top = cursor;
		}
		top -> next = temp;
	}
}

void Stack::lettersOnly() {
	NodePtr temp = new Node;
	NodePtr cursor = new Node;
	NodePtr qtemp = new Node;
	temp = top -> next;
	cursor = top -> next;
	qtemp = top;

	if (top -> data == "." || top -> data == "!" || top -> data == "?" ||
			top -> data == "," || top -> data == "'" || top -> data == " ") {
		top = temp;
		delete qtemp;
		qtemp = temp;
		temp = top -> next;
		cursor = top -> next;
	}
	while (temp != NULL) {

		if (temp -> data == "." || temp -> data == "!" || temp -> data == "?" ||
				temp -> data == "," || temp -> data == "'" || temp -> data == " ") {
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
