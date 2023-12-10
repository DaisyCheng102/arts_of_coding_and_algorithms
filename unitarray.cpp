#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("unitarray.txt");
    cin.rdbuf(fin.rdbuf());
    int cases, size;
    cin >> cases;
    while (cases--)
    {
        cin >> size;
        int num;
        int p = 0, n = 0;
        for (int j = 0; j < size; ++j)
        {
            cin >> num;
            if (num == 1)
                ++p;
            else
                ++n;
        }
        if (p >= n)
        { //  p > n, return 0 or 1
            cout << n % 2 << endl;
        }
        else
        { // p < n
            int k = (n - p + 1) / 2;
            cout << k + (n - k) % 2 << endl;
        }
    }
    return 0;
}