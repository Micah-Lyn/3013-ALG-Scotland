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