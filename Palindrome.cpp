/*
 * Palindrome.cpp
 * CIS 22C
 * LAB 3
 * Author: VY ANH PHAM
 */
#include <iostream>
#include "Queue.h"
#include "Stack.h"
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;


int main() {
	ifstream fin; // read file for Queue
	//ifstream finS; // read file for Stack
	fin.open("palindrome.txt");
	//finS.open("palindrome.txt");

	// test input file
	if (fin.fail()) {
		cout << "Input file failed to open." << endl;
		exit (-1);
	}
	/*if (finS.fail()) {
		cout << "Input file failed to open." << endl;
		exit (-1);
	}*/


	string input;
	while (getline(fin, input)) {
		Queue queue; // create Queue object
		Stack stack; // create Stack object

		char data[input.size()];
		stringstream ss[input.size()]; // used to covert char to string
		string sdata[input.size()];
		for (int i = 0; i < input.size(); i++) {
			data[i] = input[i];

			// convert to lower case
			data[i] = tolower(data[i]);

			// remove whitespace
			if (int(data[i]) == 32 || int(data[i]) == 33 || int(data[i]) == 39 || int(data[i]) == 46
					|| int(data[i]) == 44 || int(data[i]) == 63) {
				continue;
			}

			// convert char to string
			ss[i] << data[i];
			ss[i] >> sdata[i];

			queue.enqueue(sdata[i]); // add to queue
			stack.push(sdata[i]); // add to stack

		}

		Queue queue2(queue);
		Stack stack2(stack);
		int x = queue2.get_length();
		bool check = true;
		for (int i = 0; i < x; i++) {
			if (queue2.get_front() == stack2.get_top()) {
				check = true;
			}
			else {
				check = false;
				break;
			}
			queue2.dequeue();
			stack2.pop();
		}

		if (check == true) {
			cout << input << " (Palindrome)" << endl;
		}
		else {
			cout << input << " (Not a Palindrome)" << endl;
		}


		//queue.lettersOnly(); // remove punctuation marks in Queue object

		//Queue queue2(queue); // copy the queue to queue #2
		//queue2.reverse(); // reverse the order of queue #2
/*
		// Test if palindrome
		if (queue == queue2) {
			cout << inputQ << " (Palindrome)" << endl;
		}
		else {
			cout << inputQ << " (Not a Palindrome)" << endl;
		}
		*/



/*	string inputS;
	while (getline(finS, inputS)) {


		char data[inputS.size()];
		stringstream ss[inputS.size()]; // used to covert char to string
		string sdata[inputS.size()];

		for (int i = 0; i < inputS.size(); i++) {
			data[i] = inputS[i];

			// convert to lower case
			data[i] = tolower(data[i]);

			// remove whitespace
			if (int(data[i]) == 32 || int(data[i]) == 33 || int(data[i]) == 39 || int(data[i]) == 46
					|| int(data[i]) == 44 || int(data[i]) == 63) {
				continue;
			}

			// convert char to string
			ss[i] << data[i];
			ss[i] >> sdata[i];


		}*/

		//stack.lettersOnly(); // remove punctuation marks in Stack object

		//Stack stack2(stack); // copy the stack to stack #2
		//stack2.reverse();

		// Test if palindrome
		/*if (stack == stack2) {
			cout << inputS << " (Palindrome)" << endl;
		}
		else {
			cout << inputS << " (Not a Palindrome)" << endl;
		}*/
	}


}


/*** Test Result ***
Palindrome Tester using Queue:
-------------------------------
A man, a plan, a canal, Panama. (Palindrome)
Do geese see God? (Palindrome)
Never odd. Even. (Not a Palindrome)
Never odd or even. (Palindrome)
Eye (Palindrome)
Ear (Not a Palindrome)
Able was I ere I saw Elba! (Palindrome)
Was it Eliot's toilet I saw? (Palindrome)
Race cars (Not a Palindrome)

Palindrome Tester using Stack:
-------------------------------
A man, a plan, a canal, Panama. (Palindrome)
Do geese see God? (Palindrome)
Never odd. Even. (Not a Palindrome)
Never odd or even. (Palindrome)
Eye (Palindrome)
Ear (Not a Palindrome)
Able was I ere I saw Elba! (Palindrome)
Was it Eliot's toilet I saw? (Palindrome)
Race cars (Not a Palindrome)
*** End ***/

