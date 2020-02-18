#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
#include "json.hpp"
#include "JsonFacade.hpp"
#include "timer.hpp"

using namespace std;
using json = nlohmann::json;
//https://github.com/nlohmann/json

struct wordNode
{
    string word;
    string definition;
    wordNode *next; // Pointer to the next node in the list

    wordNode()
    {
        word = "sing";
        definition = "make musical sounds with the voice, with a set tune.";
    }

    wordNode(string w, string def)
    {
        word = w;
        definition = def;
        next = NULL;
    }
};

class List
{
private:
    wordNode *Head;
    wordNode *Tail;

public:
    List()
    {
        Head = Tail = NULL;
    }

    void Insert(string w, string def)
    {
        wordNode *Temp = new wordNode(w, def);

        if (!Head && !Tail)
        {
            Head = Tail = Temp;
        }
        else
        {
            Tail->next = Temp;
            Tail = Temp;
        }
    }

    // void Insert(string w, string def) {
    //     // allocate new memory and init node
    //     wordNode *Temp = new wordNode(w, def);

    //       // figure out where it goes in the list

    //     Temp->next = Head;
    //     Head = Temp;
    //     if (!Tail) {
    //       Tail = Head;
    //     }

    //   }

    void PrintTail()
    {
        cout << Tail->word << ":" << Tail->definition << endl;
    }

    void Print()
    {
        wordNode *Temp = Head;
        string list;

        while (Temp != NULL)
        {
            cout << Temp->word << ":" << Temp->definition << endl;
            Temp = Temp->next;
        }
    }
};

int main(int argc, char **argv)
{
    List L;
    JsonFacade *J;
    string objWord, objDef;
    int size;

    J = new JsonFacade("dict_w_defs.json");

    size = J->getSize();

    cout << size << endl;

    vector<string> letters = J->getKeys();

    for (int i = 0; i < size; i++)
    {
        objWord = J->getKey(i);

        objDef = J->getValue(objWord);

        L.Insert(objWord, objDef);
       
    }

    L.Print();

    return 0;
}