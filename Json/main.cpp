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

struct wordNode {
    string word;
    string definition;
    wordNode *next; // Pointer to the next node in the list

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

class List {
private:
    wordNode *Head;
    wordNode *Tail;
    string wordsV[10];
    int count = 0;

public:
    List() {
        Head = Tail = NULL;
    }

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

	int countWords() {
		return count;
	}
    
	

    void PrintTail() {
        cout << Tail->word << ":" << Tail->definition << endl;
    }

    void matchingWords() {
		for(int i = 0; i < 10; i++)
		{
			cout << wordsV[i] << "  ";		
		}
		cout << '\n';    
	}

    void Print() {
        wordNode *Temp = Head;
        string list;

        while (Temp != NULL)   {
            cout << Temp->word << ":" << Temp->definition << endl;
            Temp = Temp->next;
        }
    }
};

int main(int argc, char **argv) {
    List L;
    JsonFacade *J;
    string objWord, objDef;
    int size;

    J = new JsonFacade("dict_w_defs.json");

    size = J->getSize();

    vector<string> letters = J->getKeys();

    for (int i = 0; i < size; i++)  {
        objWord = J->getKey(i);
        objDef = J->getValue(objWord);
        L.Push(objWord, objDef);
       
    }

    char k;            
    string word = "";  

    cout<<"Type keys and watch what happens. Type capital Z to quit."<<endl;

   
    while ((k = getch()) != 'Z') {
        Timer T;                                 
        T.Start();

        if((int)k != 10) {   
           word += k;
           cout << word << endl;
            
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