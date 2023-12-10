#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool run(string &arr, int x, int y, int i, int ox, int oy)
{
    if (ox == 0 && oy == 0)
        return false;
    for (; i < arr.size(); ++i)
    {
        switch (arr[i])
        {
        case 'L':
            if (x - 1 != ox || y != oy)
                --x;
            break;
        case 'R':
            if (x + 1 != ox || y != oy)
                ++x;
            break;
        case 'U':
            if (y + 1 != oy || x != ox)
                ++y;
            break;
        case 'D':
            if (y - 1 != oy || x != ox)
                --y;
            break;
        }
    }
    return x == 0 && y == 0;
}
void original(string &arr)
{
    int x = 0, y = 0, ox = 0, oy = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        switch (arr[i])
        {
        case 'L':
            --ox;
            break;
        case 'R':
            ++ox;
            break;
        case 'U':
            ++oy;
            break;
        case 'D':
            --oy;
            break;
        }

        if (run(arr, x, y, i + 1, ox, oy))
        {
            cout << ox << " " << oy << endl;
            return;
        }
        x = ox;
        y = oy;
    }
    cout << "0 0\n";
}
int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("therobot.txt");
    cin.rdbuf(fin.rdbuf());
    int cases;
    cin >> cases;
    string arr;
    while (cases--)
    {
        cin >> arr;
        original(arr);
    }
    return 0;
}