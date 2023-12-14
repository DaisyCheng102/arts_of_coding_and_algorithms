#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("donttrytocount.txt");
    cin.rdbuf(fin.rdbuf());
    int cases, lenghtx, lengths;
    cin >> cases;

    while (cases--)
    {
        int i = 0;
        string x, s;
        cin >> lenghtx >> lengths;
        cin >> x >> s;
        for (; i < 6; ++i)
        {
            if (x.find(s) != string::npos)
            {
                cout << i << endl;
                break;
            }
            x += x;
        }
        if(i >= 6)
            cout << -1 << endl;
    }
    return 0;
}