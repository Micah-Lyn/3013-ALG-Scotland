///////////////////////////////////////////////////////////////////////////////
//
// Author:           Micah-Lyn Scotland
// Email:            micahlyns@gmail.com
// Label:            P06
// Title:            Program 06 - 11597
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//       This programs finds the maximum number of spanning trees of a 
//       complete undirected graph that can be formed in such a way that 
//       no two of these spanning trees have a common edge.
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

int main()
{

    int cases = 1;
    int n;

    while (cin >> n && (n % 2) == 0)
    {

        if (n >= 2 && n <= 400)
        {
            cout << "Case " << cases << ": " << "" << n / 2;
            cout << "\n";
            cases++;
        }
    }

    return 0;
}