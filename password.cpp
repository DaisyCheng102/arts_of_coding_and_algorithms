#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("password.txt");
    cin.rdbuf(fin.rdbuf());
    int cases;
    cin >> cases;

    for (int i = 0, size; i < cases; ++i)
    {
        cin >> size;
        cin.ignore(256, '\n');
        cin.ignore(256, '\n');
        cout << (9 - size) * (10 - size) * 3 << endl;
    }
    return 0;
}