///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Micah-Lyn Scotland
// Email:            micahlyns@gmail.com
// Label:            A02
// Title:            Linked List Class
// Course:           CMPS 3013
// Semester:         Spring 2020
//
// Description:
//       This program implements a class that allows a linked list to be used similar to
//       an array. It overloads the "[]" (square brackets) to simulate accessing seperate 
//       array elements, but really it traverses the list to find the specified node using
//       an index value. It also overloads the "+" to join lists together and "push"to add  
//	 items onto the end of the list, as well as "pop" items off the end of our array. 
//       
// Usage: 
//      - $ ./main filename
//      - This will read in a file containing whatever values to be read into our list/array. 
//      
// Files:            
//      main.cpp    : driver program 
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

int A[100];			// array of 100 elements

/**
 * Node
 *
 * Description:
 *     Linked List Node - struct used to create linked list
 *
 * Public Methods:
 *                        Node()
 *			  Node(int n)
 *
 * Private Methods:

 * Usage:
 *
 *     Node* Head;		  Pointer to Head for linked list
 *
 */
struct Node {
    int x;
    Node* next;		// Node pointer in order to point to next node
    Node() {		// Default constructor set x to -1 and next to NULL
	x = -1;
	next = NULL;
    }
    Node(int n) {	// Parameterized constructor for a node
	 x = n;
	 next = NULL; 
    }
};

/**
 * List
 *
 * Description:
 *      This class implements a Linked list which consists
		of nodes. Each node contains data and point or is 
		linked to the next node in the list.
 *
 * Public Methods:
 *						List()
 *		void				Push(int val)
 *		void				Insert(int val)
 *     		void				PrintTail()
 *		string				Print()
 *		int				Pop()
 *		List				operator+(const List& Rhs)
 *		int				operator[](int index) 
 *		friend				ostream& operator<<(ostream& os, List L)

 * Usage:
 *
 *      	List L1;			// Constructs a new list
 *		L1.Push(i);			// Pushes a value on the list
 */
class List {
private:
     Node* Head;		   // Pointer to Head
     Node* Tail;		   // Pointer to Tail(end of list)
     int Size;		  	   // Number of items in List 

public:
   /**
    * Constructor : List
    *
    * Description:
    * 	  Default constructor for list 
    *
    * Params:
    *      none
    *
    * Returns:
	 nothing
    */
    List() {				// Constructs List
	Head = Tail = NULL;		// Sets Head and Tail to Null
	Size = 0;			// Initalizes size of list to 0
    }
    /**
     * Public : Push
     *
     * Description:
     *      Push a value unto the link list.
     *
     * Params:
     *      int     :  value pushed or added on to the list
     *
     * Returns:
     *      nothing
     */
    void Push(int val) {
	 // allocate new memory and init node
	 Node* Temp = new Node(val);

	 if (!Head && !Tail) {
	     Head = Tail = Temp;
	 } else {
	     Tail->next = Temp;
	     Tail = Temp;
	 }
	 Size++;
    }

    /**
     * Public : Insert
     *
     * Description:
     *      Inserts a value to the link list from the head
     *
     * Params:
     *      int     :  val
     *
     * Returns:
     *      nothing
     */
    void Insert(int val) {
	 // allocate new memory and init node
	 Node* Temp = new Node(val);

	 // figure out where it goes in the list
	 Temp->next = Head;
	 Head = Temp;
	 if (!Tail) {			
	     Tail = Head;
	 }
		Size++;
    }

    /**
     * Public : PrintTail
     *
     * Description:
     *      Prints value at the end of list
     *
     * Params:
     *     None
     *
     * Returns:
     *      nothing
     */
    void PrintTail() {				
	cout << Tail->x << endl;
    }

     /**
      * Public : Print
      *
      * Description:
      *         Prints the list of values beginning from the head.
      *		A temp pointer is used to traverse the list. The
      *		values are converted to string.
      * Params:
      *     None
      *
      * Returns:
      *      List
      */
    string Print() {
	Node* Temp = Head;			// Declares a temp pointer that points to head
	string list;				// List declared as string
	    
	while (Temp != NULL) {			// Print the values in the list with an arrow
						// returns the list of values with proper format
	    list += to_string(Temp->x) + "->";
            Temp = Temp->next;
	}

	return list;
    }

     /**
      * Public : Pop
      *
      * Description:
      *      Removes or pops a value from the list. 
      *		The size of the list is then decreased.
      * Params:  
      *     None
      *
      * Returns:
      *      int     :  0
      */
    int Pop() {		// not implemented
	Size--;		// Decreases size when item is popped from the list
	return 0; 
    }

     /**
      * Public : operator+
      *
      * Description:
      *      Plus(+) operator is overlaoded to join or concatenate two or
      *		more lists together.
      * Params:
      *     List&       :  a list to concatenate
      * 
      * Returns:
      *     List	:  a concatenated list
      */
    List operator+(const List& Rhs) {
	// Create a new list that will contain both when done
	List NewList;

	// Get a reference to beginning of local list
	Node* Temp = Head;

	// Loop through local list and Push values onto new list
	while (Temp != NULL) {
	   NewList.Push(Temp->x);
	   Temp = Temp->next;
	}

	// Get a reference to head of Rhs
	Temp = Rhs.Head;

	// Same as above, loop and push
	while (Temp != NULL) {
		NewList.Push(Temp->x);
		Temp = Temp->next;
	}

	// Return new concatenated version of lists
	return NewList;
     }

       /**
	* Public : operator[]
	*
	* Description:
	*      [] operator is overlaoded to print list as an array.
	*		
	* Params:
	*     int      :  array index
	*
        * Returns:
	*     int      :  the value accessed in the list
	*/

       // Implementation of [] operator.  This function returns an
       // int value as if the list were an array.
     int operator[](int index) {
	 Node* Temp = Head;

	 if (index >= Size) {
	     cout << "Index out of bounds, exiting";
	     exit(0);
	} else {

	    for (int i = 0; i < index; i++) {
		 Temp = Temp->next;
	    }
	    return Temp->x;
	}
     }
      /**
       * Public : operator <<
       *
       * Description:
       *      Overloads extraction operator (<<) to print a list.
       * Params:
       *	   ostream&	  :   os
       *            List	  :   a list
       *
       * Returns:
       *     ostream	  :   os
       */
     friend ostream& operator<<(ostream& os, List L) {
	os << L.Print();
	return os;
     }
};

int main(int argc, char** argv) {
    List L1;		// Declares a list called L1
    List L2;		// Declares a list called L2

    for (int i = 0; i < 25; i++) {	// Adds or pushes numbers 0 - 24 to List 1
	 L1.Push(i);
    }

    for (int i = 50; i < 100; i++) {	// Adds or pushes numbers 50 - 99 to List 2
	 L2.Push(i);
    }

    //cout << L1 << endl;
    L1.PrintTail();		// Print the value of the last number in list 1
    L2.PrintTail();		// Print the value of the last number in list 2

    List L3 = L1 + L2;		// Adds values of list 1 and list 2, and stores it in list 3
    cout << L3 << endl;		// Prints list 3

    cout << L3[5] << endl;	// Prints elements as if it was an array
    return 0;
}
