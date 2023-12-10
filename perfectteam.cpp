#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("perfectteam.txt");
    cin.rdbuf(fin.rdbuf());
    int cases, c, m, x;
    cin >> cases;
    while (cases--)
    {
        cin >> c >> m >> x;
        cout << min(((c + m + x) / 3), min(c, m)) << endl;
    }
    return 0;
}