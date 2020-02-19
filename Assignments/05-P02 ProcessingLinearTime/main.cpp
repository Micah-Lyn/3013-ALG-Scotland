///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Micah-Lyn Scotland
// Email:            micahlyns@gmail.com
// Label:            P02
// Title:            Processing Linear Time
// Course:           CMPS 3013
// Semester:         Spring 2020
//
// Description:
//       This program uses Javascript Object Notation as input format. It reads a 
//       dictionary file and stores it in a linked list. The amount the data takes
//       to be loaded on the linked list is recored. After the dictionary is loaded
//       "autosuggestions" is performed -  the user types in characters, then as each
//       character is being typed the top 10 suggestions will be displayed containing
//       words that matches the characters. The time as well as the amount of words 
//       found will also be displayed.
//       
// Usage: 
//      - $ ./main filename
//      - This will read in a dictonary file containing values to be stored in 
//        linked list. 
// Files:            
//      main.cpp         : driver program 
//      dict_w_defs.json : json input file
//      mygetch.hpp      : captures keyboard input
//      json.hpp         : json class written by nlohmann
//      JsonFacade.hpp   : json helper class to assist json.hpp class
//      Timer.hpp        : timer helper class
/////////////////////////////////////////////////////////////////////////////////

#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
#include "json.hpp"
#include "JsonFacade.hpp"
#include "Timer.hpp"
#include "mygetch.hpp"
#include <chrono>

using namespace std;
using json = nlohmann::json;
//https://github.com/nlohmann/json



/**
 * Node
 *
 * Description:
 *     Linked List Node - struct used to create linked list
 *
 * Public Methods:
 *            wordNode()
 *			  wordNode(string w, string def)
 *
 * Private Methods:
 * Usage:
 *
 *     Node* Head;		  Pointer to Head for linked list
 *
 */
struct wordNode {
    string word;
    string definition;
    wordNode *next;          //Node pointer in order to point to next node

    wordNode() {            
        word = "sing";
        definition = "make musical sounds with the voice, with a set tune.";
    }

    wordNode(string w, string def) {
        word = w;
        definition = def;
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
 *		void            Push(string w, string def) 
 *      void            getWord(string wordF)
 *     	void			PrintTail()
 *      int             countWords()
 *      void            matchingWords() 
 *		string			Print()
 * Usage:
 *
 *      List L;			             // Constructs a new list
 *		L.Push(objWord, objDef);	 // Pushes a value on the list
 */
class List {
private:
    wordNode *Head;                         // Pointer to Head
    wordNode *Tail;                         // Pointer to Tail
    string wordsV[10];                      // Array of words
    int count = 0;                          // Number of words found

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
	*      nothing
    */
    List() {                                // Constructs List
        Head = Tail = NULL;                 // Sets Head and Tail to Null
        count = 0;                          // Initalizes the words found to 0
    }

 /**
     * Public : Push
     *
     * Description:
     *      Push a word and definition unto the link list.
     *
     * Params:
     *      string     : w
     *      string     : def
     *
     * Returns:
     *      nothing
     */
    void Push(string w, string def) {
        wordNode *Temp = new wordNode(w, def);

        if (!Head && !Tail) {
            Head = Tail = Temp;
        }
        else {
            Tail->next = Temp;
            Tail = Temp;
        }
    }

   /**
     * Public : getWord
     *
     * Description:
     *      Stores  all the auto suggested words found into a vector in 
     *      order to calculate the count and stores the top 10 words 
     *      found in an array to be displayed.
     *
     * Params:
     *     string     : wordF
     *
     * Returns:
     *      nothing
     */
    void getWord(string wordF) {
        int size = 10, s = 0;
        string currWord;
		wordNode* begin = new wordNode;	
        wordNode* end = new wordNode;	
		begin = Head;
        end = NULL;
        

        vector<string> wordsA;

		while (begin != end) {

			currWord = begin->word;
			size_t found = currWord.find(wordF);
    
            
            if (found != string::npos) {
                wordsA.push_back(currWord);
                count = wordsA.size();
                
			}

			if (found != string::npos && s < size) {
                wordsV[s] = currWord;
                s++;
			}

			begin = begin->next;
		}
        begin = end;
        
	}


   /**
     * Public : printTail
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
    void printTail() {
        cout << Tail->word << ":" << Tail->definition << endl;
    }


   /**
     * Public : countWords
     *
     * Description:
     *      Returns the number of words in vector
     *
     * Params:
     *     None
     *
     * Returns:
     *      int	:  the word count or size of vector
     */
    int countWords() {
		return count;
	}


 /**
     * Public : matchingWords
     *
     * Description:
     *      Prints the top 10 matching words
     *
     * Params:
     *     None
     *
     * Returns:
     *      nothing
     */
    void matchingWords() {
		for(int i = 0; i < 10; i++) {
			cout << wordsV[i] << "  ";		
		}
		cout << endl;    
	}


     /**
      * Public : Print
      *
      * Description:
      *     Prints the list of values beginning from the head.
      *		A temp pointer is used to traverse the list. The
      *		values are converted to string.
      * Params:
      *     None
      *
      * Returns:
      *      nothing
      */
    void Print() {
        wordNode *Temp = Head;

        while (Temp != NULL)   {
            cout << Temp->word << ":" << Temp->definition << endl;
            Temp = Temp->next;
        }
    }
};

int main(int argc, char **argv) {
    List L;                             // Declares a list L
    JsonFacade *J;
    string objWord, objDef;             // Stores key and value from json file
    int size;                           // Stores size of json file

    J = new JsonFacade("dict_w_defs.json");

    size = J->getSize();

    vector<string> letters = J->getKeys();
    Timer T1;                           // Timer declared to time how long it 
                                        // takes to load file onto linked list.
    T1.Start();
    // Loops through json file to get the word and definition to be pushed onto linked list
    for (int i = 0; i < size; i++)  {
        objWord = J->getKey(i);
        objDef = J->getValue(objWord);
        L.Push(objWord, objDef);
       
    }
    T1.End();

    char k;                             // holder for character being typed
    string word = "";                   // var to concatenate letters to 

    cout<<"Type keys and watch what happens. Type capital Z to quit."<<endl;

   // While capital Z is not typed keep looping
    while ((k = getch()) != 'Z') {
        Timer T;                                 
        T.Start();

        if((int)k != 10) {              // if k is not a space print it
           word += k;                   // append char to word
           cout << word << endl;        // prints characters as they are being typed
            
        }
         L.getWord(word); 

        // hitting enter sets word back to empty
        if((int)k == 10 ) {
            cout<<"Enter pressed ... Word is empty\nWord: "<<endl;
            word = "";
           
        }////
        T.End();
             
        cout <<"\n\n"<< L.countWords() << " words found in ";
        printf( "%.3f", T.Seconds());
        cout <<" seconds";
        cout << "\n\n\n";
        L.matchingWords();                   
        cout <<"\n\n\n";
    }

return 0;
}