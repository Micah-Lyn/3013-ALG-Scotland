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
        //nCars : number of cars
        //cTime: t minutes
        //mLines: gives the arrival time in minutes for a car
        cin >> nCars >> cTime >> mLines;

        // time taken to cross the river and return
        cTime *= 2;

        // a : holds the time in minutes
        // amt : total time for cars to go across
        int amt = 0, a = 0, i = 0;

        //loads arrival time for each car in line
        while (i < mLines)
        {

            cin >> car[i];

            i++;
        }

        int present, travel;

        // cars that have gone across
        int m = (mLines + nCars - 1) % nCars;

        while (m < mLines)
        {
            // if total time is more than the arrival time for a car

            if (amt > car[m])
            {

                a = amt;
            }

            else if (amt < car[m])
            {
                a = car[m];
            }

            //time each car takes to go across
            amt = a + cTime;
            // number of cars that have gone across
            m += nCars;
        }

        present = amt - cTime / 2;

        travel = (mLines + nCars - 1) / nCars;

        //present time in minutes since the beginning of the day when the last car was delivered and travel: minimum number of trips
        cout << present << " " << travel << '\n';
    }
    return 0;
}