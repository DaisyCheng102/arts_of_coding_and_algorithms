#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>

using namespace std;

// https://codeforces.com/group/dGxXsD48aw/contest/394666/problem/C
int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    string name = filesystem::path(argv[0]).filename();
    ifstream fin(name + ".txt");
    cin.rdbuf(fin.rdbuf());
    int size, time;
    cin >> size >> time;
    string queue;
    cin >> queue;
    while(time--)
    {
        for(int i = 1;i < size;++i)
        {
            if(queue[i] == 'G' && queue[i - 1] == 'B')
            {
                char temp = queue[i];
                queue[i] = queue[i-1];
                queue[i-1] = temp;
                ++i;
            }
        }
    }
    cout << queue;
    return 0;
}