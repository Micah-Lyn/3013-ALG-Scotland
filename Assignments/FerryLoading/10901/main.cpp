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

        queue<int> carQ[2];

        int j = 0, time = 0, oSideTime;
        string oSide;

        vector<int> aTime;

        int i = 0;

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

        vector<int> uTime(aTime.size());

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

                if (carQ[1].empty())
                {
                    mlineT = aTime[carQ[0].front()];
                }
                else if (carQ[0].empty())
                {
                    mlineT = aTime[carQ[1].front()];
                }
            }
            if (time <= mlineT)
            {
                time = mlineT;
            }

            int cCount = 0;

            while ((nCars > cCount) && (!carQ[j].empty()) && (aTime[carQ[j].front()] <= time))
            {
                uTime[carQ[j].front()] = tMinutes + time;
                carQ[j].pop();
                ++cCount;
            }

            time += tMinutes;

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
