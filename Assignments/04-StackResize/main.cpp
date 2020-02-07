///////////////////////////////////////////////////////////////////////////////
//
// Author:           Micah-Lyn Scotland
// Email:            micahlyns@gmail.com
// Label:            P01
// Title:            Program 01 - Array Based Stack
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//       Overview of a class implementing an array based stack
//
/////////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>

using namespace std;

/**
 * ArrayStack
 *
 * Description:
 *      Array based stack
 *
 * Public Methods:
 *      - See class below
 *
 * Usage:
 *      - See main program
 *
 */
class ArrayStack {
private:
    int* A;          // pointer to array of int's
    int size;        // current max stack size
    int top;         // top of stack
    double itemSize; // number of the current size of the stack everytime something is pushed on the stack
    int growth;      // number of times array grow
    int resize;      // checks each time stack grow and shrink
    int maxSize;     // maximum stack size

public:
    /**
     * ArrayStack
     *
     * Description:
     *      Constructor no params
     *
     * Params:
     *     - None
     *
     * Returns:
     *     - NULL
     */
    ArrayStack() {
        size = 10;
        A = new int[size];
        top = -1;
        itemSize = 0;
        growth = 0;
        resize = 0;
        maxSize = 0;
    }

    /**
     * ArrayStack
     *
     * Description:
     *      Constructor size param
     *
     * Params:
     *     - int size
     *
     * Returns:
     *     - NULL
     */
    ArrayStack(int s) {
        size = s;
        A = new int[s];
        top = -1;
        itemSize = 0;
        growth = 0;
        resize = 0;
        maxSize = 0;
    }

    /**
     * Public bool: Empty
     *
     * Description:
     *      Stack empty?
     *
     * Params:
     *      NULL
     *
     * Returns:
     *      [bool] true = empty
     */
    bool Empty() {
        return (top <= -1);
    }

    /**
     * Public bool: Full
     *
     * Description:
     *      Stack full?
     *
     * Params:
     *      NULL
     *
     * Returns:
     *      [bool] true = full
     */
    bool Full() {
        return (top >= size - 1);
    }

    /**
     * Public int: Peek
     *
     * Description:
     *      Returns top value without altering the stack
     *
     * Params:
     *      NULL
     *
     * Returns:
     *      [int] top value if any
     */
    int Peek() {
        if (!Empty()) {
            return A[top];
        }

        return -99; // some sentinel value
            // not a good solution
    }

    /**
     * Public int: Pop
     *
     * Description:
     *      Returns top value and removes it from stack
     *
     * Params:
     *      NULL
     *
     * Returns:
     *      [int] top value if any
     */
    int Pop() {
        if (!Empty()) {
            CheckResize();
            top = top - 1;
            return A[top];
        }

        return -99; // some sentinel value
            // not a good solution
    }

    /**
     * Public void: Print
     *
     * Description:
     *      Prints stack to standard out
     *
     * Params:
     *      NULL
     *
     * Returns:
     *      NULL
     */
    void Print() {
        cout << "\n";
        cout << "##################################################################### \n";
        cout << "Assignment 4 - Resizing the Stack \n";
        cout << "CMPS 3013 \n";
        cout << "Micah-Lyn Scotland \n ";
        cout << "\n\n";
        cout << "Max Stack Size: " << maxSize << "\n";
        cout << "End Stack Size: " << size << "\n";
        cout << "Stack Resized:  " << resize << " time(s)" << "\n";
        cout << "\n\n";
        cout << "##################################################################### \n";

    }

    /**
     * Public bool: Push
     *
     * Description:
     *      Adds an item to top of stack
     *
     * Params:
     *      [int] : item to be added
     *
     * Returns:
     *      [bool] ; success = true
     */
    bool Push(int x) {

        if (Full()) {
            CheckResize();
        }
        if (!Full()) {
            CheckResize();
            A[++top] = x;
            return true;
        }

        return false;
    }

    /**
     * Public void: ContainerGrow
     *
     * Description:
     *      Grows the container for the stack by 1.75
     *
     * Params:
     *      NULL
     *
     * Returns:
     *      NULL
     */
    void ContainerGrow() {                       

        long newSize = size * 1.75;      // increase size of original by 1.75

        if (newSize > maxSize) {         // keeps track of max size
            maxSize = newSize;
        }

        int* B = new int[newSize];       // allocate new memory
        
        for (int i = 0; i < size; i++) { // copy values to new array
            B[i] = A[i];
        }
      
        delete[] A;		            	 // delete old array
       
        size = newSize;                  // save new size

        A = B;                           // reset array pointer

        growth++;                        // increments growth
        resize++;                        // increments resize
    }

    /**
     * Public void: ContainerShrink
     *
     * Description:
     *      Grows the container for the stack by .5
     *
     * Params:
     *      NULL
     *
     * Returns:
     *      NULL
     */

    void ContainerShrink() {

        int newSize = size * 0.5;           // shrinks size of original by .5
        int* B = new int[newSize];          // allocate new memory

        for (int i = 0; i < newSize; i++) { // copy values to new array
            B[i] = A[i];
        }

        delete[] A;                         // delete old array

        size = newSize;                     // save new size

        A = B;                              // reset array pointer

        resize++;
    }

    /**
     * Public void: CheckResize
     *
     * Description:
     *      Computes ratio of stack and grows or shrink stack accordingly
     *
     * Params:
     *      NULL
     *
     * Returns:
     *      NULL
     */

    void CheckResize() {
       
        int half = top + 1;                   // number of items currently on the stack
        double ratio = (double) half / size;  // computes ratio

        if (ratio < .5) {                     // if ratio is less than .5, growth is
            if (growth >= 1 && size > 10) {    // more than one and size is more than 10, 
                ContainerShrink();            // the container shrinks
            }
        }
        else if (ratio >= 1) {                // grows the container if ratio is more than
            ContainerGrow();                  // or equal to 1
        }
    }
};

// MAIN DRIVER
// Simple Array Based Stack Usage:
int main() {
    ArrayStack stack;
    int num = 0;
    
    ifstream in("nums_test.dat");

    while (!in.eof()) {

        in >> num;

        if (num % 2 == 0) {         // if the number is even it is pushed onto stack
            stack.Push(num);   
        }
        else {                      // value at top of stack is popped
            stack.Pop(); 
        }
    }
    stack.Print();                  // prints result of program
}
