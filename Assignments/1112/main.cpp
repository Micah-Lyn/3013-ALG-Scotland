///////////////////////////////////////////////////////////////////////////////
//
// Author:           Micah-Lyn Scotland
// Email:            micahlyns@gmail.com
// Label:            P07
// Title:            Program 07 - 1112
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//       This programs uses dijkstras algoritmn to help predict the number of
//       mice that will exit a maze.
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

#define ii pair<int, int>

vector<ii> adjMatrix[101];

int cTotal, cExit, mLinks, duration, distanceM[115];

void dijkstras(int c)
{

    priority_queue<ii> pQueue;

    for (int i = 0; i <= cTotal; i++)
    {
        distanceM[i] = INT_MAX;
    }

    distanceM[c] = 0;

    pQueue.push(ii(distanceM[c], c));

    while (!pQueue.empty())
    {

        ii miceP = pQueue.top();

        int c = miceP.second;

        pQueue.pop();

        for (int i = 0; i < adjMatrix[c].size(); ++i)
        {

            ii w = adjMatrix[c][i];

            if (distanceM[c] + w.second < distanceM[w.first])
            {
                distanceM[w.first] = distanceM[c] + w.second;
                pQueue.push(make_pair(distanceM[w.first], w.first));
            }
        }
    }
}

int main()
{
    int total, m1, m2, m3;

    cin >> total;

    while (total--)
    {

        cin >> cTotal >> cExit >> duration >> mLinks;

        while (mLinks--)
        {

            cin >> m1 >> m2 >> m3;

            adjMatrix[m2].push_back(ii(m1, m3));
        }

        dijkstras(cExit);

        int mCount = 0;

        for (int i = 1; i <= cTotal; i++)
        {

            if (distanceM[i] <= duration)

                mCount++;
        }

        cout << mCount << '\n';

        if (total > 0)
        {

            cout << '\n';
        }
    }

    return 0;
}