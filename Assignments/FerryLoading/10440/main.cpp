///////////////////////////////////////////////////////////////////////////////
//
// Author:           Micah-Lyn Scotland
// Email:            micahlyns@gmail.com
// Label:            P08
// Title:            Program 08 - 10440
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//       This programs caluclates the earliest time that all cars can be
//       transported across the rive and the minimum number of trips the 
//       operator has to make to deliver all the cars on time.
//
/////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{

    int car[1440];

    int nCars, cTime, mLines, testCases;

    cin >> testCases;

    while (testCases--)
    {

        cin >> nCars >> cTime >> mLines;

        cTime *= 2;

        int amt = 0, a = 0, i = 0;

        while (i < mLines)
        {

            cin >> car[i];

            i++;
        }

        int present, travel;

        int m = (mLines + nCars - 1) % nCars;

        while (m < mLines)
        {

            if (amt > car[m])
            {
                a = amt;
            }

            else if (amt < car[m])
            {
                a = car[m];
            }

            amt = a + cTime;

            m += nCars;
        }

        present = amt - cTime / 2;
        
        travel = (mLines + nCars - 1) / nCars;

        cout << present << " " << travel << '\n';
    }
    return 0;
}