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
#include <iostream>
#include <fstream>

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
	int* A;           // pointer to array of int's
	int size;         // current max stack size
	int top;          // top of stack 
	double itemSize;	  // number of the current size of the stack everytime something is pushed on the stack
	int growth;		  // number of times array grow
	int resize;		  // checks each time stack grow and shrink
	int maxRatio;
	int minRatio;

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
		maxRatio = -99999990;
		minRatio = 999999999;
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
		maxRatio = -99999990;
		minRatio = 999999999;
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
			//cout << "printing from pop" << A[top];
			//cout << "\n\n";
			// reduce the number of item in the stack size--;
			//itemSize = itemSize - 1;
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
		for (int i = 0; i <= top; i++) {
			cout << A[i] << " ";
		}
		cout << "\n";
		cout << "Max Stack Size: " << itemSize << "\n";
		cout << "End Stack Size: " << size << "\n";
		cout << "Stack Resized:  " << resize << " time(s)" << "\n";
		cout << endl;
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
			//cout << "pushing value onto stack" << x;
			//cout << "\n\n";
			//CheckResize(); // we check resize to make sure the ratio isnt below .50

			return true;
		}
		

		return false;

	}


	/**
	 * Public void: Resize
	 *
	 * Description:
	 *      Resizes the container for the stack by doubling
	 *      its capacity
	 *
	 * Params:
	 *      NULL
	 *
	 * Returns:
	 *      NULL
	 */

	void printArray(int* a, int size) {
		for (int i = 0; i < size; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	void ContainerGrow() {
		growth++;


		long newSize = size * 1.75;			 //increase size of original by 1.75

		int* B = new int[newSize];			 // allocate new memory
		//printf("New Size: %d\n", newSize);
		//printf("Old size: %d\n", size);
		//printf("\n----------------\nIncreasing size of container\n----------------\n");
		//memcpy(B, A, size * 4);
		//B[size + 1] = 1234;
		//printArray(A, size);
		//printArray(B, newSize);
		for (int i = 0; i < size; i++) {     // copy values to new array
			B[i] = A[i];
		}
		//printf("Finished copying\n");
		//printf("Growth: %d\n", growth);
		//delete [] A;							 // delete old array
		//printf("Finished deleting\n");
		size = newSize;

		//if (newSize > itemSize)
			//itemSize = newSize;

		A = B;	                // reset array pointer

		resize++;
	}

	void ContainerShrink() {
		// decrease stack by 0.5 if stack is half empty

		int newSize = size * 0.5;       // double size of original

		//printf("New Size: %d\n", newSize);
		//printf("Old size: %d\n", size);
		int* B = new int[newSize];  // allocate new memory


		//memcpy(B, A, newSize * 4);
		//if (newSize == 15) {
		//	cout << B[newSize] << endl;
		//}

		for (int i = 0; i < newSize; i++) {    // copy values to new array
			B[i] = A[i];
		}
		//printArray(A, size);
		//printArray(B, newSize);
		//delete[] A;                // delete old array

		size = newSize;             // save new size

		A = B;                      // reset array pointer

		//make top be the new size of the array
		//top = newSize;

		resize++;
	
	}


	void CheckResize() {
		double ratio;
		int resize = 0; // check how many times stack was resized
		// check the ratio
		// ratio = number of items in stack / stack size

		//ratio = itemSize / size;
		int half = top + 1;
		ratio = (double)half / (double) size;

		cout << ratio << endl;

		if (ratio < .5) {
			// If the stack grows more than once, it can be shrinked
			
				if (growth >=1 && size > 1) {
				ContainerShrink();
				//cout << "container shrink\n\n";
			
			    }
		}
		else if (ratio >= 1) {
			ContainerGrow();
			//cout << "container grow\n\n";
		}
	}



	

};

// MAIN DRIVER
// Simple Array Based Stack Usage:
int main() {
	ArrayStack stack;
	int r = 0;

	int num = 0;

	ifstream in("nums.dat");
	//ofstream out("output.dat");

	while (!in.eof()) {
	
		in >> num;
		
			if (num % 2 == 0) {
				stack.Push(num);
				//cout << "push in main" << num;
			}
			else {

				stack.Pop();
				//cout << "number encountered" << num;
			}
			
	}
	stack.Print();

}