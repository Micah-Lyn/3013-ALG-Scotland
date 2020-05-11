///////////////////////////////////////////////////////////////////////////////
//
// Author:           Micah-Lyn Scotland
// Email:            micahlyns@gmail.com
// Label:            P08
// Title:            Program 08 - 10261
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//       This programs tells the operator of a ferry which car to load on which
//       side so as to maximize the number of cars loaded.
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int testCase, ferry;

    cin >> testCase;

    while (testCase--)
    {
        //ferry length
        cin >> ferry;

        ferry *= 100; // converts length from metres to cm

        int num = 1, carL[2001], tot[2001] = {};

        // while cars are being read and its more than 0
        while (cin >> carL[num] && carL[num] > 0)
        {
            //add it to the total number of cars
            tot[num] = tot[num - 1] + carL[num];
            num++;
        }

        pair<int, int> ii = make_pair(0, 0);

        //pSide turns to 1 for if cars ranging from one to i are loaded based on the length(j) to the right side of the ferry
        vector<vector<int>> pSide(num, vector<int>(ferry + 1, 0));
        // stores whether the cars went on starboard size or port size
        vector<vector<string>> carSet(pSide.size(), vector<string>(pSide[0].size(), ""));

        //starting position set to 1
        pSide[0][0] = 1;

        num--;

        int i = 1;

        while (i <= num)
        {

            for (int j = 0; j <= ferry; j++)
            {
                // if cars from one i to i-1 were loaded sucessfully  to the right
                if (pSide[i - 1][j] > 0)
                {
                    // load car on the port or left side
                    if (ferry - (tot[i - 1] - j) >= carL[i])
                    {

                        carSet[i][j] = "port";
                        pSide[i][j] = 1;
                        ii = make_pair(i, j);
                    }

                    // load car on the starboard or right side
                    if (ferry - j >= carL[i])
                    {

                        carSet[i][j + carL[i]] = "starboard";
                        pSide[i][j + carL[i]] = 1;
                        ii = make_pair(i, j + carL[i]);
                    }
                }
            }

            i++;
        }

        // number of cars loaded on ferry
        cout << ii.first << endl;

        string answer;

        // prints whether the car goes on the left side or right side
        while (carSet[ii.first][ii.second] != "")
        {

            answer = carSet[ii.first][ii.second] + '\n' + answer;
            ii.second -= carSet[ii.first][ii.second] == "starboard" ? carL[ii.first] : 0;
            ii.first--;
        }

        cout << answer;

        if (testCase)
        {

            cout << '\n';
        }
    }
    return 0;
}