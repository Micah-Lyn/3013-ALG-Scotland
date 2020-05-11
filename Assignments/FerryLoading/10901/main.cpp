///////////////////////////////////////////////////////////////////////////////
//
// Author:           Micah-Lyn Scotland
// Email:            micahlyns@gmail.com
// Label:            P08
// Title:            Program 08 - 10901
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//       This programs uses a queue to check the time at which each car
//       reaches either side of a river using a ferry.
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <queue>

using namespace std;

int main()
{

    int cTestCases, nCars, tMinutes, mLines;

    cin >> cTestCases;

    while (cTestCases--)
    {

        cin >> nCars >> tMinutes >> mLines;

        //queue to store cars
        queue<int> carQ[2];

        int j = 0, time = 0, oSideTime;
        string oSide;

        vector<int> aTime;

        int i = 0;

        //loads arrival time for cars and loads the car in
        //the queue 0 = left, 1 = right
        while (i < mLines)
        {

            cin >> oSideTime >> oSide;

            aTime.push_back(oSideTime);

            if (oSide == "left")
            {
                carQ[0].push(i);
            }
            else
            {
                carQ[1].push(i);
            }

            i++;
        }

        // time at which car was unloaded at the opposite side
        vector<int> uTime(aTime.size());

        // if cars are present to move across the river (to
        // the left or right side) the car waiting the longest
        // is loaded
        while (!carQ[0].empty() || !carQ[1].empty())
        {
            int mlineT = 0;

            if (!carQ[1].empty() && !carQ[0].empty())
            {
                if (aTime[carQ[0].front()] >= aTime[carQ[1].front()])
                {
                    mlineT = aTime[carQ[1].front()];
                }
                else
                {
                    mlineT = aTime[carQ[0].front()];
                }
            }
            else
            {
                //if either side is empty the car on the opposite side
                //is taken
                if (carQ[1].empty())
                {
                    mlineT = aTime[carQ[0].front()];
                }
                else if (carQ[0].empty())
                {
                    mlineT = aTime[carQ[1].front()];
                }
            }

            //sets current time
            if (time <= mlineT)
            {
                time = mlineT;
            }

            int cCount = 0;

            //while the number of cars to load on the bank is more than
            //the number of cars on the bank, and the currebt side is
            //not empty and the actual time is less than or equal to
            //current time
            while ((nCars > cCount) && (!carQ[j].empty()) && (aTime[carQ[j].front()] <= time))
            {
                //time car takes to be offloaded
                uTime[carQ[j].front()] = tMinutes + time;
                carQ[j].pop();
                ++cCount;
            }

            time += tMinutes;

            //chooses the side the ferry is on
            if (j == 0)
            {
                j = 1;
            }
            else
            {
                j = 0;
            }
        }

        for (int i = 0; i < mLines; i++)
        {
            cout << uTime[i] << '\n';
        }

        if (cTestCases > 0)
            cout << '\n';
    }
    return 0;
}
