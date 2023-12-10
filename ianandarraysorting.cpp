#include <iostream>
#include <limits>
#include <fstream>
#include <filesystem>

using namespace std;

// https://codeforces.com/group/dGxXsD48aw/contest/479559/problem/D
int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    string name = filesystem::path(argv[0]).filename();
    ifstream fin(name + ".txt");
    cin.rdbuf(fin.rdbuf());
    int cases, size;
    cin >> cases;
    while (cases--)
    {
        cin >> size;
        if (size % 2 != 0)
        {
            cout << "YES" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            long long sumo = 0, sume = 0;
            for (int i = 0, num = 0; i < size; ++i)
            {
                cin >> num;
                if (i % 2 != 0)
                    sume += num;
                else
                    sumo += num;
            }
            // int *psum = &sumo, num = 0;
            // while (size--)
            // {
            //     cin >> num;
            //     *psum += num;
            //     psum = (psum == &sumo ? &sume : &sumo);
            // }
            cout << (sumo <= sume ? "YES" : "NO") << endl;
        }
    }
    return 0;
}