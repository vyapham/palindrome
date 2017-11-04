/*
 * Stack.h
 * CIS 22C
 * LAB 3
 * Author: VY ANH PHAM
 */
#ifndef STACK_H_
#define STACK_H_

#include <string>
#include <cstddef>

using namespace std;

class Stack
{
    private:
        struct Node
        {
            string data;
            Node* next;
            Node(): next(NULL), data(""){}
            Node(string data): next(NULL), data(data){}

        };
        typedef Node* NodePtr;

        NodePtr top;
        int length;

    public:
        /**constructors and destructors*/

        Stack();
        //initializes an empty stack
        //postcondition: an empty stack

        Stack(const Stack &stack);
        //initializes stack to have same elements as another stack
        //postcondition: a copy of stack

        ~Stack();
        //frees memory allocated to the stack
        //postcondition: memory for stack has been freed

        void pop();
        //removes an element from the top of the stack
        //postcondition: an element has been removed from the top of the stack

        void push(string data);
        //adds an element to the top of the stack
        //postcondition: an element added to the top of the stack

        /**accessors*/

        string get_top();
        //returns the element at the top of the stack
        //precondition: the stack is not empty

        int get_length();
        //returns the size of the stack

        /**additional stack operations*/
        void print();
        //prints the elements in the stack in a programmer-specified format to stdout

        bool operator==(const Stack &stack);
        //returns whether this stack is equal to another stack

        /** The following functions are used from the Palindrome assignment*/
        void reverse();
        // Reverse the order of stack

        void lettersOnly();
        // Remove all punctuation marks
};

#endif /* STACK_H_ */
