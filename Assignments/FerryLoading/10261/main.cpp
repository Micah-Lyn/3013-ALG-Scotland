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

        cin >> ferry;

        ferry *= 100;

        int num = 1, carL[2001], tot[2001] = {};

        while (cin >> carL[num] && carL[num] > 0)
        {

            tot[num] = tot[num - 1] + carL[num];
            num++;
        }

        pair<int, int> ii = make_pair(0, 0);

        vector<vector<int>> pSide(num, vector<int>(ferry + 1, 0));

        vector<vector<string>> carSet(pSide.size(), vector<string>(pSide[0].size(), ""));

        pSide[0][0] = 1;

        num--;

        int i = 1;

        while (i <= num)
        {

            for (int j = 0; j <= ferry; j++)
            {

                if (pSide[i - 1][j] > 0)
                {

                    if (ferry - (tot[i - 1] - j) >= carL[i])
                    {

                        carSet[i][j] = "port";
                        pSide[i][j] = 1;
                        ii = make_pair(i, j);
                    }

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

        cout << ii.first << endl;

        string answer;

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
