#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>

using namespace std;

// https://codeforces.com/group/dGxXsD48aw/contest/482418/problem/A
int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    string name = filesystem::path(argv[0]).filename();
    ifstream fin(name + ".txt");
    cin.rdbuf(fin.rdbuf());
    int cases, size, max;
    cin >> cases;
    while (cases--)
    {
        cin >> size >> max;
        cout << max / (size/2 + 1) << endl;
    }
    return 0;
}