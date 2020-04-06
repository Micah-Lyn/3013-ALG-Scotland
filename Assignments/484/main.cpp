///////////////////////////////////////////////////////////////////////////////
//
// Author:           Micah-Lyn Scotland
// Email:            micahlyns@gmail.com
// Label:            P05
// Title:            Program 05 - 484
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//       This programs  remove all duplicates from a sequence of integers 
//       and print the list of unique integers occuring in the input sequence,
//       along with the number of occurences of each.
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{

    map<int, int> m;            // Map container
    vector<int> pairsFound;     

    int key;

    while (cin >> key) {
        // Checks if key exists in map
        if (m.find(key) == m.end()) {
            //not found
            pairsFound.push_back(key);
            m[key] = 1;
        }
        else {
            //found
            m[key] = m[key] + 1;
        }
    }

    for (int i = 0; i < pairsFound.size(); i++) {    

        cout << pairsFound[i] << " " << m[pairsFound[i]] << endl;

    }
}