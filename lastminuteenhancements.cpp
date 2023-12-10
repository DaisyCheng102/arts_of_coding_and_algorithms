#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("lastminuteenhancements.txt");
    cin.rdbuf(fin.rdbuf());
    int cases;
    cin >> cases;
    while (cases--)
    {
        int size, divers = 0, prev = 0, curr, prevprev = -1;
        cin >> size;
        for (int i = 0; i < size; ++i)
        {
            cin >> curr;
            if (prev >= curr)
            {
                ++curr;
                if(prev != curr)
                    ++divers;
            }
            else
            {
                ++divers;
            }
            prev = curr;
        }
        cout << divers << endl;
    }
    return 0;
}